<?php
/**
 * @author Bruno Massa
 * @file
 * You can associate a geographic address with users.
 */

/**
 * Delete a given Address
 *
 * @param $id
 *   Number. The Address ID that should be deleted
 */
function _addresses_user_address_delete($id) {
  db_query('DELETE FROM {addresses_user} WHERE aid = %d', $id);

  // Show an warning message
  drupal_set_message(t('The address has been deleted.'), 'warning');
}

/**
 * Load the full address from a given Address ID or User ID
 *
 * @param $id
 *   Number. The external ID (eid) to look into the addresses_user table.
 * @param $id_type
 *   The type (name) of the identifier used to search the addresses_user
 *   table. Default to 'eid'. Can be set to 'aid' although.
 * @return
 *   Array. The numeric list of addresses arrays
 */
function _addresses_user_address_get($id, $id_type = 'eid') {
  static $addresses;
  static $addresses_user;

  if (empty($addresses[$id])) {
    $adr = db_query("SELECT * FROM {addresses_user}
      WHERE %s = %d
      ORDER BY is_primary DESC", $id_type, $id);

    // Transform all SQL findings into arrays
    $addresses[$id] = array();
    while ($address = db_fetch_array($adr)) {
      $addresses[$address['aid']] = $address;
      $addresses_user[$address['eid']][$address['aid']] = $address;
    }
  }

  if ($id_type == 'eid') {
    return $addresses_user[$id];
  }
  else {
    return $addresses[$id];
  }
}

/**
 * Saves a address and link it to its main object.
 * Needs a $user or $node object.
 *
 * @param $address
 *   Array. The address data to be saved.
 * @param $id
 *   Number. It might be the Node ID (nid) or the User ID (uid),
 *   depending on the $type variable
 */
function _addresses_user_address_save($address, $id) {
  if (!empty($address) && is_array($address)) {
    // If this address is the Primary, change all other address
    // to NOT primary
    if (!empty($address['is_primary'])) {
      db_query('UPDATE {addresses_user} SET is_primary = 0
        WHERE is_primary = 1 AND eid = %d', $id);
    }

    // Correct some values
    $address['country']   = drupal_strtolower($address['country']);
    $address['province']  = drupal_strtoupper($address['province']);

    // Save it on DB
    $address['eid'] = $id;
    if (empty($address['aid'])) {
      $update = NULL;
    }
    else {
      $update = array('aid');
    }

    drupal_write_record('addresses_user', $address, $update);
  }
}

/**
 * Manage the user Addresses: list them, create and delete operations
 *
 * @param $op
 *   String (optional). The action that should be executed:
 *   - NULL (default) => list all user addresses
 *   - 'add'          => Address form to add a new address
 *   - 'edit'         => Address form to modify an existing address
 *   - 'delete'       => It will promptly delete the address
 * @param aid
 *   Number (optional). The Address ID
 */
function _addresses_user_address($op = NULL, $aid = NULL) {
  global $user;
  $uid = $user->uid;

  // If the user has the permission to administer
  // other users, he can see others address pages too
  // (i.e. if $access is TRUE, then arg(1) may be any UID,
  // otherwise arg(1) == $uid, see permissions on menu)
  $access = user_access('administer users');
  if (!empty($access)) {
    $uid = arg(1);
  }

  switch ($op) {
    case 'add':
    case 'edit':
      // Its time to include the address form!

      // If it's an existing address, get the whole
      // address information
      $edit = arg(4) ? _addresses_user_address_get(arg(4), 'aid') : array();

      if (empty($edit)) {
        // Set the Element ID as User ID form new addresses
        $edit['eid'] = $uid;
      }
      elseif (empty($access) && $edit['eid'] != $uid) {
        // If the user has no permission or the user from
        // address is not the same as the user that are
        // accessing, deny the access
        return drupal_access_denied();
      }

      return drupal_get_form('_addresses_user_form', array(), $edit);

    case 'delete':
      /// @todo Generates a confirm page before delete
      _addresses_user_address_delete(arg(4));

      // Send the user to the address book
      drupal_goto("user/$uid/address");
      break;

    default:
      $addresses = _addresses_user_address_get($uid);
      return theme('addresses_user_overview', $uid, $addresses);
  }
}

/**
 * Create a address form for users
 */
function _addresses_user_form(&$form_state, $fields = array(), $values = array()) {
  $form = array();

  // Get the fields used on this address
  $fields = variable_get('addresses_user', array());

  // If its the very first time its loaded, use all fields
  if (empty($fields)) {
    $ftypes = module_invoke_all('addressesfieldapi', 'fields');
    foreach ($ftypes as $ftype => $field) {
      // List of address fields
      $fields[$index] = empty($field_values[$ftype]) ? $field['display'] : $field_values[$ftype];
    }
  }

  // Get the address form builder
  $form['addresses'] = array(
    '#default_value'  => $values,
    '#fields'         => $fields,
    '#required'       => TRUE,
    '#type'           => 'addresses_elements',
    '#tree'           => TRUE
  );
  $form['#uid'] = $values['eid'];

  // Add the submit button
  if (empty($values['aid'])) {
    $form['submit'] = array(
      '#type'   => 'submit',
      '#value'  => t('Create new address')
    );
  }
  else {
    $form['submit'] = array(
      '#type'   => 'submit',
      '#value'  => t('Update address')
    );
  }

  return $form;
}

/**
 * List all addresses from a given user
 *
 * @ingroup themeable
 * @param $uid
 *   Number. The user ID
 * @param &$addresses
 *   Array. A list of user addresses
 */
function theme_addresses_user_overview($uid, $addresses) {
  // Get the current page URL, to force the forms
  // to return here.
  $destination = drupal_get_destination();

  // The option to add a new address is always visible
  $output = "<p>". l(t('Click here to add a new address'),
    "user/$uid/address/add", array('query' => $destination)) .'.</p>';

  // Create a table showing the addresses
  if (!empty($addresses)) {

    // Add each address
    foreach ($addresses as $address) {
      $colunm = array();

      // Display a single address
      $colunm[] = theme('addresses', $address);

      // More readable variable
      $aid = $address['aid'];

      // Add the Edit and Delete options
      $colunm[] = l(t('edit'),
      "user/$uid/address/edit/$aid", array('query' => $destination)) .' / '. l(t('delete'),
      "user/$uid/address/delete/$aid");

      // Each line has two colunms
      $rows[] = $colunm;
    }

    // Create the addresses table
    $header = array(t('address'), t('options'));
    $output .= theme('table', $header, $rows);
  }

  // Show the resulting output
  return $output;
}
