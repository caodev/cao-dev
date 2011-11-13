<?php
/**
 * @author Bruno Massa
 * @file
 * All settings functions for Addresses module.
 */

/**
 * It splits the _addresses_addressesfieldapi_form into more pieces,
 * reducing the memory consumption on non related pages.
 *
 * @ingroup form
 */
function _addresses_addressesfieldapi_form($fields = array(), $values = array()) {
  $field_weights = variable_get('addresses_field_weight', array());
  $form = array();

  // Let users select if the address is the primary
  if (!empty($fields['is_primary'])) {
    $form['is_primary'] = array(
      '#type' => 'checkbox',
      '#title' => t('Default address'),
      '#default_value' => isset($values['is_primary']) ? $values['is_primary'] : '',
      '#weight' => empty($field_weights['is_primary']['weight']) ? 0 : $field_weights['is_primary']['weight'],
    );
  }

  // Adds the Address Name (Home, Office, Rio de Janeiro...)
  if (!empty($fields['aname'])) {
    $form['aname'] = array(
      '#type' => 'textfield',
      '#title' => t('Address name'),
      '#default_value' => isset($values['aname']) ? $values['aname'] : '',
      '#size' => 50,
      '#maxlength' => 75,
      '#description' => t('e.g. a place of business, venue, meeting point'),
      '#attributes' => NULL,
      '#required' => ($fields['aname'] == ADDRESSES_FIELD_REQUIRED),
      '#weight' => empty($field_weights['aname']['weight']) ? 0 : $field_weights['aname']['weight'],
    );
  }

  // Adds the Country
  if (!empty($fields['country'])) {
    // Get a list of enabled countries
    $countries = _addresses_country_get(variable_get('addresses_country_list', array()),
        variable_get('addresses_top_countries', array()));
    if (count($countries) > 1) {
      $countries = array('' => '') + $countries;
    }
    $country = isset($values['country']) ? $values['country'] : '';
    if (isset($countries['top_' . $country])) {
      $country = 'top_' . $country;
    }

    $form['country'] = array(
      '#type' => 'select',
      '#title' => t('Country'),
      '#default_value' => $country,
      '#options' => $countries,
      '#description' => NULL,
      '#extra' => 0,
      '#multiple' => FALSE,
      '#element_validate' => array('_addresses_validate_top_countries'),
      '#required' => ($fields['country'] == ADDRESSES_FIELD_REQUIRED),
      '#weight' => empty($field_weights['country']['weight']) ? 0 : $field_weights['country']['weight'],
    );
  }

  // Adds the Province field
  if (!empty($fields['province'])) {
    $form['province'] = array(
      '#default_value' => isset($values['province']) ? $values['province'] : '',
      '#maxlength' => 16,
      '#required' => ($fields['province'] == ADDRESSES_FIELD_REQUIRED),
      '#size' => 16,
      '#title' => t('State / Province'),
      '#type' => 'textfield',
      '#weight' => empty($field_weights['province']['weight']) ? 0 : $field_weights['province']['weight'],
    );
    // If country field is displayed then use AJAX
    // See addresses.js
    if ($form['country']) {
      drupal_add_js(drupal_get_path('module', 'addresses') . '/addresses.js');
      // Due to varying field names we use the following classes for the JS
      // see http://drupal.org/node/244471#comment-2499288
      $form['province']['#attributes']['class'] = 'addresses-province-field';
      $form['country']['#attributes']['class'] = 'addresses-country-field';
    }
    $form['#element_validate'][] = '_addresses_province_field_validate';
  }

  // Adds the City
  if (!empty($fields['city'])) {
    $form['city'] = array(
      '#type' => 'textfield',
      '#title' => t('City'),
      '#default_value' => isset($values['city']) ? $values['city'] : '',
      '#size' => 50,
      '#maxlength' => 255,
      '#required' => ($fields['city'] == ADDRESSES_FIELD_REQUIRED),
      '#weight' => empty($field_weights['city']['weight']) ? 0 : $field_weights['city']['weight'],
    );
  }

  // Adds the Streets and the Additional fields
  if (!empty($fields['street'])) {
    $form['street'] = array(
      '#type' => 'textfield',
      '#title' => t('Street'),
      '#default_value' => isset($values['street']) ? $values['street'] : '',
      '#size' => 50,
      '#maxlength' => 255,
      '#required' => ($fields['street'] == ADDRESSES_FIELD_REQUIRED),
      '#weight' => empty($field_weights['street']['weight']) ? 0 : $field_weights['street']['weight'],
    );
    if (!empty($fields['additional'])) {
      $form['additional'] = array(
        '#type' => 'textfield',
        '#title' => t('Additional'),
        '#default_value' => isset($values['additional']) ? $values['additional'] : '',
        '#size' => 50,
        '#maxlength' => 255,
        '#weight' => empty($field_weights['additional']['weight']) ? 0 : $field_weights['additional']['weight'],
      );
    }
  }

  // Adds the Postal Code
  if (!empty($fields['postal_code'])) {
    $form['postal_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Postal code'),
      '#default_value' => isset($values['postal_code']) ? $values['postal_code'] : '',
      '#size' => 16,
      '#maxlength' => 16,
      '#required' => ($fields['postal_code'] == ADDRESSES_FIELD_REQUIRED),
      '#weight' => empty($field_weights['postal_code']['weight']) ? 0 : $field_weights['postal_code']['weight'],
    );
  }

  foreach (array_keys($fields) as $ftype) {
    if ($fields[$ftype] == ADDRESSES_FIELD_HIDDEN) {
      $form[$ftype] = array(
        '#type' => 'hidden',
        '#value' => isset($values[$ftype]) ? $values[$ftype] : '',
      );
    }
  }

  return $form;
}

/**
 * With the addition of top countries, we may get selections such
 * as 'top_\<country name>' which we want to convert to plain
 * '\<country name>'.
 *
 * @param $element
 *   Array. A representation of the element being validated.
 * @param $form_state
 *   Array. The current state of the form.
 */
function _addresses_validate_top_countries($element, &$form_state) {
  if (isset($element['#parents'][0])) {
    $field_name = $element['#parents'][0];
  }
  else {
    $field_name = 'addresses';
  }
  if (isset($form_state['values'][$field_name]['0']['country']) && $form_state['values'][$field_name]['0']['country'] == 'separator') {
    // the user selected the separator!
    $form_state['values'][$field_name]['0']['country'] = '';
  }
  elseif ($form_state['values'][$field_name]['country'] == 'separator') {
    // the user selected the separator!
    $form_state['values'][$field_name]['country'] = '';
  }
  elseif (isset($form_state['values'][$field_name]['0']['country']) && substr($form_state['values'][$field_name]['0']['country'], 0, 4) == 'top_') {
    $form_state['values'][$field_name]['0']['country'] = substr($form_state['values'][$field_name]['0']['country'], 4);
  }
  elseif (substr($form_state['values'][$field_name]['country'], 0, 4) == 'top_') {
    $form_state['values'][$field_name]['country'] = substr($form_state['values'][$field_name]['country'], 4);
  }
}

/**
 * Create a list of states from a given country.
 *
 * @param $country
 *   String. The country code
 * @param $string
 *   String (optional). The state name typed by user
 * @return
 *   Javascript array. List of states
 *
 * @deprecated
 *   This implementation was never functional in 6.x. To be removed in
 *   Addresses 2.x.
 */
function _addresses_autocomplete($country, $string = '') {
  $matches = array();

  if (substr($country, 0, 4) == 'top_') {
    $country = substr($country, 4);
  }

  // Check if the country code is there
  if ($country) {
    $string = drupal_strtolower($string);
    $string = '/^'. $string .'/';

    $provinces = _addresses_province_get($country);

    // Get only the first 5 provinces that matches
    // partially with the given piece of text
    if (!empty($provinces)) {
      $counter = 5;
      while (list($code, $name) = each($provinces)) {
        if (preg_match($string, drupal_strtolower($name))) {
          $matches[$code] = drupal_strtolower($name);
          --$counter;
          if ($counter <= 0) {
            break;
          }
        }
      }
    }
  }
  // Print the results as a JS array.
  echo drupal_to_js($matches);

  // Finish the page. Its necessary to not continue
  // to build a regular page
  exit();
}

/**
 * Validation function for ISO 3166-1 alpha-2 country codes.
 *
 * @param $country
 *   ISO 3166-1 alpha-2 code of a country.
 * @return
 *   Boolean.
 */
function _addresses_country_valid($country) {
  if (empty($country)) {
    return FALSE;
  }

  // Country codes are listed in lowercase throughout the system
  $country = drupal_strtolower($country);

  // Cache results to prevent _addresses_country_get() being ran unnecessarily
  // Won't be needed once http://drupal.org/node/680376 is complete
  static $countries = array(
    'invalid' => array(),
    'valid' => array()
  );
  // If country is in the invalid sub-array elseif in the valid sub-array
  if (array_search($country, $countries['invalid']) !== FALSE) {
    return FALSE;
  }
  elseif (array_search($country, $countries['valid']) !== FALSE) {
    return TRUE;
  }

  // See if country code is found by _addresses_country_get().
  if (!_addresses_country_get(array($country => ' '))) {
    $countries['invalid'][] = $country;
    return FALSE;
  }

  $countries['valid'][] = $country;
  return TRUE;
}

/**
 * Callback function for loading provinces when changing the country of an
 * address.
 *
 * @return
 *   JSON encoded province selection field.
 */
function _addresses_province_ajax() {
  global $language;

  // Keep the same language between calls so that t() calls work as expected
  if (!empty($_GET['language'])) {
    $languages = language_list(); // get all languages
    if (isset($languages[$_GET['language']])) {
      $language = $languages[$_GET['language']];
    }
  }

  // ISO 3166-1 alpha-2 code of a country.
  $country = $_GET['country'];
  if (substr($country, 0, 4) == 'top_') {
    $country = substr($country, 4);
  }
  // HTML id attribute of select field.
  $field_id = $_GET['field_id'];
  // HTML name attribute of select field.
  $field_name = $_GET['field_name'];
  // HTML id attribute of province's wrapper.
  $passback = $_GET['passback'];
  // ISO-3166-2 code for the province or state to mark as selected.
  $province = $_GET['province'];
  //JSON encoded list of field attributes;
  $field_attributes = '';
  $attributes = json_decode($_GET['attributes']);
  if (is_object($attributes)) {
    foreach ($attributes as $attr => $val) {
      $field_attributes .= check_plain($attr) . "='" . check_plain($val) . "' ";
    }
  }

  // Check that required fields are supplied
  if (empty($field_id) || empty($field_name) || empty($passback)) {
    return drupal_json(array('error' => 'Invalid call'));
  }

  // $element is a form element we build below to get the needed HTML
  $element = array();
  // No need to use drupal_strtoupper() as ISO-3166-2 codes are latin based
  $element['#value'] = drupal_strtoupper($province);
  $element['#options'] = array();
  $provinces = array();
  $output = '';
  $hide = FALSE;

  if (!empty($country)) {
    module_load_include('inc', 'addresses');
    $provinces = _addresses_province_get($country);
    $element['#options'] = _addresses_province_get($country);
  }

  if (empty($provinces)) {
    $hide = TRUE;
  }

  // Generate province field HTML
  $output .= '<label for="' . $field_id . '">' . t('State / Province: ') . '</label>';
  $output .= '<select id="' . $field_id . '" name="' . $field_name
    . '" class="addresses-province-field" ' . $field_attributes . '>'
    . form_select_options($element) . '</select>';

  return drupal_json(array(
    'field' => $output,
    'passback' => $passback,
    'hide' => $hide,
  ));
}

/**
 * Validate province code or province name of a country.
 *
 * @param $country
 *   ISO 3166-1 alpha-2 code of a country.
 * @param $province
 *   ISO-3166-2 code or province name.
 * @return
 *   Returns FALSE if $country or $province are invalid.
 *   Returns ISO-3166-2 code if valid.
 *   Returns NULL if $country does not contain any provinces.
 */
function _addresses_province_valid($country, $province) {
  if (substr($country, 0, 4) == 'top_') {
    $country = substr($country, 4);
  }

  // Ensure that country code provided is valid
  if (!_addresses_country_valid($country)) {
    return FALSE;
  }

  $provinces = _addresses_province_get($country);

  // If the country chosen does not contain any provinces
  if (empty($provinces)) {
    return NULL;
  }

  // If $province provided matches ISO-3166-2 code.
  if ($provinces[strtoupper($province)]) {
    // Province supplied is ISO-3166-2 code.
    return $province;
  }

  // Flip array and change to lowercase to match names in key, can not use
  // array_search() or in_array() as they are case-sensitive.
  $provinces = array_change_key_case(array_flip($provinces));
  if ($provinces[strtolower($province)]) {
    // Return the ISO-3166-2 province code.
    return $provinces[strtolower($province)];
  }

  // $province provided did not return any valid matches.
  return FALSE;
}

/**
 * Validate the province field
 *
 * @deprecated
 *   Use _addresses_province_field_validate() which accepts not only ISO-3166-2
 *   but also provinces by name. To be removed in 2.x.
 */
function _addresses_province_validate($form, &$form_state) {
  // Check if its a valid province.
  // It should be the Province code listed on the
  // given COUNTRY.inc file
  $province = $form['province']['#value'];
  $country = $form['country']['#value'];
  if (substr($country, 0, 4) == 'top_') {
    $country = substr($country, 4);
  }
  if ($country && $province) {
    $provinces = _addresses_province_get($country);
    if (empty($provinces[drupal_strtoupper($province)])) {

      // Get the province fieldname
      $field_name = $form['province']['#name'];
      $field_name = drupal_substr($field_name, 0, -1);
      $field_name = preg_replace('/([^]])\[/', '\1][', $field_name);

      $countries = _addresses_country_get();
      form_set_error($field_name, t('Could not find %province as a province from %country. Try to use the province abbreviation or number.', array(
        '%province' => $form['province']['#value'],
        '%country' => $countries[$country])));
    }
  }
}

/**
 * Validate the province field
 *
 * @return void
 */
function _addresses_province_field_validate($form, &$form_state) {
  // If province is not required and empty then prevent validation
  if (!$form['province']['#required'] && $form['province']['#value'] == '') {
    return;
  }

  $province = _addresses_province_valid(
    $form['country']['#value'],
    $form['province']['#value']
  );

  // If province is valid or if the country does not have any provinces
  if ($province || is_null($province)) {
    // Find array's key path to province field's value in $form_state
    $form_state_province =& $form_state['values'];
    foreach ($form['province']['#parents'] as $v) {
      $form_state_province =& $form_state_province[$v];
    }

    // Set province to ISO-3166-2 code (properly uppercased)
    $form_state_province = $province;
  }
  // Prevent inability to alter CCK fields in some instances
  elseif ($form_state['values']['form_id'] != 'content_field_edit_form') {
    // Get the province fieldname
    $field_name = $form['province']['#name'];
    $field_name = drupal_substr($field_name, 0, -1);
    $field_name = preg_replace('/([^]])\[/', '\1][', $field_name);

    $countries = _addresses_country_get();
    form_set_error($field_name, t('Could not find %province as a province from %country. Try to use the province abbreviation or number.', array(
      '%province' => $form['province']['#value'],
      '%country' => $countries[$form['country']['#value']])));
  }
}

/**
 * Modules settings page
 *
 * @ingroup form
 */
function _addresses_settings(&$form_state) {
  module_load_include('inc', 'addresses');
  $countries = _addresses_country_get();
  $country_list = variable_get('addresses_country_list', array_keys(_addresses_country_get()));
  $top_countries = variable_get('addresses_top_countries', array());

  // List of countries that the site allow
  $form['addresses_country_list'] = array(
    '#default_value' => $country_list,
    '#description' => t('You might want to limit the country lists. Select the countries you want.'),
    '#multiple' => TRUE,
    '#options' => $countries,
    '#type' => 'select',
    '#title' => t('Possible country'),
  );

  $form['addresses_top_countries'] = array(
    '#default_value' => $top_countries,
    '#description' => t('Select any countries you want to also display at the top of the list of countries.'),
    '#multiple' => TRUE,
    '#options' => $countries,
    '#type' => 'select',
    '#title' => t('Top countries'),
  );

  // Allow users to change address formats
  $countries = array_intersect_key($countries, $country_list);
  array_unshift($countries, t('Default'));
  $countries_max = ceil(count($countries) / 4);
  $country_num = 0;

  foreach ($countries as $country_code => $country) {
    $columns[$country_num++ / $countries_max][] = l($country, 'admin/settings/address/format/'. $country_code);
  }

  foreach (array_keys($columns[0]) as $row) {
    $rows[] = array($columns[0][$row], $columns[1][$row], $columns[2][$row], $columns[3][$row]);
  }

  $form['addresses_format'] = array(
    '#children' => theme('table', array(), $rows),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#description' => t('Change how the addresses are displayed, for each country. The Default is used if the country doesnt have a preset address format.'),
    '#type' => 'fieldset',
    '#title' => t('Address formats'),
  );

  // Field weights
  $fields = module_invoke_all('addressesfieldapi', 'fields');
  $field_weights = variable_get('addresses_field_weight', array());
  $form['addresses_field_weight'] = array(
    '#collapsed' => $field_weights,
    '#collapsible' => TRUE,
    '#description' => t('Choose the order in which fields are displayed in user forms.'),
    '#theme' => 'addresses_field_weight',
    '#title' => t('Field order'),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  foreach ($fields as $field_code => $field) {
    $weight = empty($field_weights[$field_code]['weight']) ? 0 : $field_weights[$field_code]['weight'];
    $form['addresses_field_weight'][$field_code] = array(
      '#tree' => TRUE,
      '#weight' => $weight,
    );
    $form['addresses_field_weight'][$field_code]['field'] = array(
      '#attributes' => array('class' => 'field'),
      '#type' => 'markup',
      '#value' => $field['title'],
    );
    $form['addresses_field_weight'][$field_code]['weight'] = array(
      '#attributes' => array('class' => 'field'),
      '#default_value' => $weight,
      '#type' => 'weight',
      '#delta' => 50,
    );
  }

  // We will use the this function that automatically
  // save all form fields into global variables
  $form = system_settings_form($form);

  $form['buttons']['#weight'] = 10;
  return $form;
}

/**
 * Generate a settings form that will allow admins to choose
 * which addresses fields should be used.
 *
 * @param field_values
 *   Array (optional). The default values for each field, if any
 * @return
 *   Array. A form with settings
 * @ingroup form
 */
function _addresses_settings_fields($field_values = array()) {
  $ftypes = module_invoke_all('addressesfieldapi', 'fields');

  // List of address fields
  // We let the user choose the current status, sizes, labels and descriptions
  foreach ($ftypes as $ftype => $field) {
    // Mode
    $form['addresses'][$ftype][$ftype . '_select'] = array(
      '#type' => 'select',
      '#options' => array(
        ADDRESSES_FIELD_NONE      => 'None',
        ADDRESSES_FIELD_SHOW      => 'Normal',
        ADDRESSES_FIELD_REQUIRED  => 'Required',
        ADDRESSES_FIELD_HIDDEN    => 'Hidden',
      ),
      '#default_value'  => !isset($field_values[$ftype . '_select']) ? $field['display'] : $field_values[$ftype . '_select'],
    );

    // Size
    if ($field['type'] == 'int') {
      $form['addresses'][$ftype][$ftype . '_size'] = array(
        '#type' => 'textfield',
        '#size' => 3,
        '#maxlength' => 3,
        '#default_value' => 0,
        '#disabled' => TRUE,
      );
    }
    else {
      if (isset($field_values[$ftype . '_size'])) {
        $size = $field_values[$ftype . '_size'];
      }
      elseif (empty($field['length'])) {
        if ($field['type'] == 'text') {
          $size = 60;
        }
        else {
          $size = '';
        }
      }
      else {
        // the default field length is what we want in the database
        // here we reduce the size to the Drupal Core maximum if larger
        $size = $field['length'];
        if ($size > 60) {
          $size = 60;
        }
      }
      $form['addresses'][$ftype][$ftype . '_size'] = array(
        '#type' => 'textfield',
        '#size' => 3,
        '#maxlength' => 3,
        '#default_value' => $size,
      );
    }

    // Label
    $form['addresses'][$ftype][$ftype . '_label'] = array(
      '#type' => 'textfield',
      '#size' => 20,
      '#maxlength' => 255,
      '#default_value' => !isset($field_values[$ftype . '_label']) ? $field['title'] : $field_values[$ftype . '_label'],
    );

    // Description
    $form['addresses'][$ftype][$ftype . '_desc'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#default_value' => !isset($field_values[$ftype . '_desc']) ? $field['description'] : $field_values[$ftype . '_desc'],
    );
    $form['addresses'][$ftype]['#title'] = $field['title'];
  }

  $form['addresses']['#theme'] = 'addresses_settings_fields';

  return $form;
}

/**
 * Modules settings page
 *
 * @ingroup form
 */
function _addresses_settings_format(&$form_state, $country) {
  module_load_include('inc', 'addresses');
  $countries = _addresses_country_get();

  if (!$cname = $countries[$country]) {
    $cname = t('Default');
    $country  = 'default';
  }

  if (!$format_address = variable_get('addresses_format_'. $country, '')) {
    include_once drupal_get_path('module', 'addresses') .'/countries/us.inc';
    $format_address = addresses_address_format_us();
    variable_set('addresses_format_default', $format_address);
  }

  $form['addresses_format_'. $country] = array(
    '#default_value' => $format_address,
    '#title' => t('Address Format: %country', array('%country' => $cname)),
    '#type' => 'textarea',
    '#wysiwyg' => FALSE,
  );

  // Simulate theme('token_help'), but include two types and
  // erase the global types
  $full_list = token_get_list('addresses_general') + token_get_list('addresses_adr');
  unset($full_list['global']);
  $headers = array(t('Token'), t('Replacement value'));
  $rows = array();

  foreach ($full_list as $key => $category) {
    $rows[] = array(
      array(
        'data' => drupal_ucfirst($key) .' '. t('tokens'),
        'class' => 'region',
        'colspan' => 2,
      )
    );

    foreach ($category as $token => $description) {
      $row = array();
      $row[] = '!'. $token .'';
      $row[] = $description;
      $rows[] = $row;
    }
  }

  $output = theme('table', $headers, $rows, array('class' => 'description'));

  $form['#redirect'] = 'admin/settings/address';

  $form['token_help'] = array(
    '#value' => $output,
  );

  return system_settings_form($form);
}

/**
 * Format a date selection element.
 *
 * @param $element
 *   An associative array containing the properties of the element.
 *   Properties used: title, value, options, description, required and attributes.
 * @return
 *   A themed HTML string representing the date selection boxes.
 *
 * @ingroup themeable
 */
function theme_addresses_elements($element) {
  return theme('form_element', $element, '<div class="addresses-form">'. $element['#children'] .'</div>');
}

/**
 * Print a nice settings table for selecting which address fields
 * should be used.
 *
 * @param $form
 *   Array. The address field settings.
 * @return
 *   String. The single line address
 * @ingroup themeable
 */
function theme_addresses_settings_fields($form) {
  foreach (element_children($form) as $ftype) {
    $field = $form[$ftype];
    $rows[] = array(
      $field['#title'],
      drupal_render($field[$ftype . '_select']),
      drupal_render($field[$ftype . '_size']),
      drupal_render($field[$ftype . '_label']),
      drupal_render($field[$ftype . '_desc']),
    );
    unset($form[$ftype]);
  }

  $header = array(t('Field'), t('Visibility'), t('Size'), t('Label'), t('Help text'));
  $output = theme('table', $header, $rows);

  $output .= drupal_render($form);

  return $output;
}

/**
 * Add a draggable item effect on fields.
 *
 * @param $form
 *   Array. The address field weight values.
 * @return
 *   String. The table with draggable items
 * @ingroup themeable
 */
function theme_addresses_field_weight($form) {
  drupal_add_tabledrag('addresses-field-weight', 'order', 'sibling', 'field');

  foreach (element_children($form) as $field) {
    $rows[] = array(
      'class' => 'draggable',
      'data'  => array(
        drupal_render($form[$field]['field']),
        drupal_render($form[$field]['weight'])
      ),
    );
  }

  return theme('table', array(), $rows, array('id' => 'addresses-field-weight')) . drupal_render($form);
}

// vim: ts=2 sw=2 et syntax=php
