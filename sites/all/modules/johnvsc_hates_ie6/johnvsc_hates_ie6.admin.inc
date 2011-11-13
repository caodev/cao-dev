<?php
/**
* Implementation of hook_admin_settings().
*/
function johnvsc_hates_ie6_admin_settings() {
  $form['#submit'][] = 'johnvsc_hates_ie6_admin_settings_submit';
  $form['johnvsc_hates_ie6-admin'] = array('#type' => 'fieldset', '#title' => t('IE Outdated Settings'), '#description' => t('Update the various fields for this block.'), '#weight' => - 2, '#collapsible' => TRUE, '#collapsed' => FALSE,);
/*Description: Format a multiple-line text field.
http://api.drupal.org/api/drupal/developer--topics--forms_api_reference.html/6#textfield*/
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-title'] = array('#type' => 'textarea', '#title' => t('Title Text'), '#default_value' => variable_get('johnvsc-ie6-title', '<h2>Did you know that your Internet Explorer is out of date? </h2>'), '#description' => t('This is the "title" that shows up on the block. I didn\'t hard code the tags so you can change and add them! '), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-message'] = array('#type' => 'textarea', '#title' => t('Message text'), '#default_value' => variable_get('johnvsc-ie6-page-message', '<p>To get the best possible experience using the web, developers recommend that you upgrade to the latest version of IE or other web browser.</p><p>Just click on the icons below to get to their respective download page</p>'), '#description' => t('This is the "message" that shows up on the block. Again, I didn\'t hard code the tags so you can change and add them!'), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-ie-link'] = array('#type' => 'textfield', '#title' => t('Internet Explorer Link'), '#default_value' => variable_get('johnvsc-ie6-ie-link', 'http://www.microsoft.com/windows/internet-explorer/default.aspx'), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-ff-link'] = array('#type' => 'textfield', '#title' => t('Mozilla Fire Fox Link'), '#default_value' => variable_get('johnvsc-ie6-ff-link', 'http://www.mozilla.com/en-US/'), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-op-link'] = array('#type' => 'textfield', '#title' => t('Opera Link'), '#default_value' => variable_get('johnvsc-ie6-op-link', 'http://www.opera.com/'), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-sa-link'] = array('#type' => 'textfield', '#title' => t('Apple Safari Link'), '#default_value' => variable_get('johnvsc-ie6-sa-link', 'http://www.apple.com/safari/download/'), '#required' => FALSE);
  $form['johnvsc_hates_ie6-admin']['johnvsc-ie6-ch-link'] = array('#type' => 'textfield', '#title' => t('Google Chrome Link'), '#default_value' => variable_get('johnvsc-ie6-ch-link', 'http://www.google.com/chrome'), '#required' => FALSE);
  return system_settings_form($form);
}
function johnvsc_hates_ie6_admin_settings_validate($form, & $form_state) {
//nothing to do here, this is just a placeholder
}
function johnvsc_hates_ie6_admin_settings_submit($form, & $form_state) {
  variable_set('johnvsc-ie6-title', $form_state['values']['johnvsc-ie6-title']);
  variable_set('johnvsc-ie6-message', $form_state['values']['johnvsc-ie6-message']);
  variable_set('johnvsc-ie6-ie-link', $form_state['values']['johnvsc-ie6-ie-link']);
  variable_set('johnvsc-ie6-ff-link', $form_state['values']['johnvsc-ie6-ff-link']);
  variable_set('johnvsc-ie6-op-link', $form_state['values']['johnvsc-ie6-oplink']);
  variable_set('johnvsc-ie6-sa-link', $form_state['values']['johnvsc-ie6-sa-link']);
  variable_set('johnvsc-ie6-ch-link', $form_state['values']['johnvsc-ie6-ch-link']);
}