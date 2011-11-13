<?php
// $Id

/**
 * @file
 * @brief User Badges admin functions
 * 
 * This file contains all the admin functions used by the module.
 *
 * @author Jeff Robbins (jjeff), http://drupal.org/user/17190
 * @author Chad Phillips (hunmonk), http://drupal.org/user/22079
 * @author Heine Deelstra (Heine), http://drupal.org/user/17943
 * @author Nuno Veloso (nunoveloso18), http://drupal.org/user/80656
 * @author Richard Skinner (Likeless), http://drupal.org/user/310635
 *
 * @warning For more information on licensing, read the LICENCE.txt file.
 *
 */

/**
 * Page callback for the main user badges admin page
 */
function user_badges_settings_page($op = NULL, $bid = NULL) {
  switch ($op) {
    case 'edit':
      if (is_numeric($bid)) {
        $output = drupal_get_form('user_badges_edit_form', $bid);
      }
      break;

    case 'delete' :
      if (is_numeric($bid)) {
        $output = user_badges_delete($bid);
      }
      break;

    default:
      $badges = user_badges_get_badges('all');
      $header = array(t('Name'), t('Image'), t('Operations'));
      if (is_array($badges)) {
        foreach ($badges as $badge) {
          $tablerow[$badge->bid]['name'] = $badge->name;
          $tablerow[$badge->bid]['image'] = theme('image', $badge->image, $badge->image, $badge->image);
          $tablerow[$badge->bid]['ops'] = l(t('edit'), 'admin/user/user_badges/edit/'. $badge->bid) .' '. l(t('delete'), 'admin/user/user_badges/delete/'. $badge->bid);
        }
      }
      $output = theme('table', $header, $tablerow, array('style' => 'width:100%'));
      $output .= "<br/><br/>";
      $form[] = array(
        '#type' => 'fieldset',
        '#title' => t('Add another'),
      );
      //$output .= user_badges_edit_form();
      $output .= drupal_get_form('user_badges_edit_form');
      break;
  }

  return $output;
}

/**
 * form to upload the badge images or to delete existing ones
 */
function user_badges_images_form($form_state) {
  $form = array('#skip_duplicate_check' => TRUE);
  if (module_exists('upload')) {
    $form['new']['upload'] = array('#type' => 'file', '#title' => t('Upload image'), '#size' => 40);
    $form['new']['attach'] = array('#type' => 'submit', '#value' => t('Upload'));
  }
  else {
    drupal_set_message(t('Upload of images requires the upload module to be enabled.'), 'error');
  }

  $form['#attributes']['enctype'] = 'multipart/form-data';

  $selects = user_badges_image_selects();
  if (count($selects)) {
    $form['images'] = array('#tree' => TRUE);
    foreach ($selects as $imagepath => $imageimg) {
      $form['images'][$imagepath] = array(
        '#type' => 'checkbox',
        '#title' => $imageimg,
        '#return_value' => 1,
        '#default_value' => FALSE,
        '#description' => check_plain($imagepath),
      );
    }
    $form['delete_image'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    );
  }
  return $form;
}

/**
 * Validate the uploaded image
 *
 * Check whether:
 * Delete has been chosen AND a checkbox has been selected
 * OR
 * Upload has been chosen AND the file upload form is not empty.
 */
function user_badges_images_form_validate($form, &$form_state) {
  $op = $form_state['clicked_button']['#value'];
  if ($op == t('Upload')) {
    $dir = file_create_path('badges');
    $is_writable = file_check_directory($dir, 1);
    if ($is_writable) {
      $validators = array(
        'file_validate_extensions' => array('png jpg jpeg gif'),
      );
      if ($file = file_save_upload('upload', $validators, $dir)) {
        if (!image_get_info($file->filepath)) {
          file_delete($file->filepath);
          form_set_error('upload', t('Uploaded image file does not appear to be a valid image file.  Please try again'));
        }
        else {
          user_badges_hold_temporary_file($file);
          $form_state['values']['file_image'] = $file;
        }
      }
      else {
        form_set_error('upload', t('Cannot save image.  Enter the path to an image and try again.'));
      }
    }
    else {
      form_set_error('upload', t('Cannot save image - directory not writable'));
    }
  }
  else if ($op == t('Delete')) {
    if (count(array_filter($form_state['values']['images'])) == 0) {
      form_set_error('images', t('Please select images to delete.'));
    }
  }
}

function user_badges_hold_temporary_file($file = NULL) {
  static $static_file;
  if (isset($file)) {
    $static_file = $file;
  }
  return $file;
}

/**
 * Submission action for user_badges_images_form
 *
 * Save the uploaded file or delete the selected one
 */
function user_badges_images_form_submit($form, &$form_state) {
  $op = $form_state['clicked_button']['#value'];
  // Save uploaded files
  if ($op == t('Upload')) {
    $file = $form_state['values']['file_image'];
    file_set_status($file, FILE_STATUS_PERMANENT);
  }
  else if ($op == t('Delete')) {
    foreach ($form_state['values']['images'] as $path => $is_removed) {
      if ($is_removed) {
        $to_delete[] = $path;
      }
    }
    if (is_array($to_delete)) {
      user_badges_image_delete($to_delete);
    }
  }
}

/**
 * Delete the specified image
 */
function user_badges_image_delete($to_delete) {
  foreach ($to_delete as $path) {
    if (file_check_location($path, file_create_path('badges'))) {
      file_delete($path);
    }
  }
}

/**
 * form to associated badges with roles
 */
function user_badges_roles_form() {
  $roles = user_roles();
  $badges = user_badges_get_roles();
  $selects = array('' => 'inactive') + user_badges_get_badges('select');

  $form['blocked'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blocked user badge'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['blocked'][0] = array(
    '#type' => 'select',
    '#default_value' => $badges[0],
    '#options' => $selects,
  ); 


  $form['roles'] = array('#tree' => TRUE);
  foreach ($roles as $rid => $role) {
    if ($rid != 1) { // no badges for the anonymous role
      $form['roles'][$rid] = array(
        '#type' => 'select',
        '#title' => $role,
        '#default_value' => isset($badges[$rid]) ? $badges[$rid] : '',
        '#options' => $selects,
      );
    }
  }
  $form[] = array(
    '#type' => 'submit',
    '#value' => t('Save Roles'),
  );
  return $form;
}

/**
 * submission function for user_badges_roles_form
 */
function user_badges_roles_form_submit($form, &$form_state) {
  $array = $form_state['values']['roles'] + $form_state['values']['blocked'];
  user_badges_save_roles($array);
}

/**
 * form for general module settings
 */
function user_badges_settings_form() {
  $form['showone'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only show the most highest-level badge'),
    '#default_value' => variable_get('user_badges_showone', 0),
    '#description' => t('If this is checked, only the badge with the lightest weight will be shown.') .'<br/>'. 
      t('Note that if multiple badges have the same lightest weight, only one of them will appear 
      (first by alphabetical order).'),
  );
  $form['showblocked'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only show blocked user badge'),
    '#default_value' => variable_get('user_badges_showblocked', 0),
    '#description' => t('If checked, only the badge associated to blocked users will be shown, overriding other badges 
      the user eventually has as well as the preciding options.') .'<br/>'. 
      t('Note that if there is no badge associated to blocked users, no badges will appear.') .'</br>'.
      t('This option only acts on blocked users and has no repercussions on active user badges.'),
  );
  $form[] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings'),
  ); 
  return $form;
}

/**
 * submission function for user_badges_settings_form
 * 
 * Set the variables and display a message about the set values.
 */
function user_badges_settings_form_submit($form, $form_state) {
  variable_set('user_badges_showone', $form_state['values']['showone']);
  variable_set('user_badges_showblocked', $form_state['values']['showblocked']);
  
  $message = ($form_state['values']['showone'] ? t('Only the most highest-level user badge will be shown.') : 
    t('All user badges will be shown.')) .' '. ($form_state['values']['showblocked'] ? t('Blocked users only will 
    have blocked user badge displayed.') : '');
   
  drupal_set_message($message);
}