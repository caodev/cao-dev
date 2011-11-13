<?php
// $Id: curlypage.admin.inc,v 1.1.2.4.2.9 2010/06/29 11:47:29 manfer Exp $

/**
 * @file
 * Admin page callbacks for curlypage module.
 */

/**
 * Menu callback for admin/build/curlypage.
 * List of curlypages.
 */
function curlypage_list_form($form_state) {

  $curlypages = curlypage_load();

  if (count($curlypages)) {

    foreach ($curlypages as $curlypage) {
      $form['curlypages'][$curlypage->cpid] = array(
        '#tree' => TRUE,
      );
      $form['curlypages'][$curlypage->cpid]['cpid'] = array(
        '#type' => 'hidden',
        '#value' => $curlypage->cpid,
      );
      $form['curlypages'][$curlypage->cpid]['name'] = array(
        '#value' => check_plain($curlypage->name),
      );
      $form['curlypages'][$curlypage->cpid]['group'] = array(
        '#value' => check_plain($curlypage->curlypage_group),
      );
      $form['curlypages'][$curlypage->cpid]['link'] = array(
        '#value' => check_plain($curlypage->link),
      );
      $form['curlypages'][$curlypage->cpid]['peel_position'] = array(
        '#value' => curlypage_get_options('peel_position', $curlypage->peel_position),
      );
      $form['curlypages'][$curlypage->cpid]['status'] = array(
        '#type' => 'checkbox',
        '#default_value' => $curlypage->status,
      );
      $form['curlypages'][$curlypage->cpid]['weight'] = array(
        '#type' => 'weight',
        '#delta' => 50,
        '#default_value' => $curlypage->weight,
      );
      $form['curlypages'][$curlypage->cpid]['clone'] = array(
        '#value' => l(t('clone'), 'admin/build/curlypage/'. $curlypage->cpid .'/clone'),
      );
      $form['curlypages'][$curlypage->cpid]['edit'] = array(
        '#value' => l(t('edit'), 'admin/build/curlypage/'. $curlypage->cpid .'/edit'),
      );
      $form['curlypages'][$curlypage->cpid]['delete'] = array(
        '#value' => l(t('delete'), 'admin/build/curlypage/'. $curlypage->cpid .'/delete'),
      );
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );

  }
  else {
    $form['empty'] = array('#value' => t('There are no curlypages yet. <a href="!Add_new">Add</a> a curlypage first.', array('!Add_new' => url('admin/build/curlypage/add'))));
  }

  return $form;
}

/**
 * Theme: List of curlypages.
 */
function theme_curlypage_list_form($form) {

  $header = array(
    t('Curlypage'),
    t('Group'),
    t('Link'),
    t('Position'),
    array('data' => t('Enabled'), 'class' => 'checkbox'),
    t('Weight'),
    array('data' => t('Operations'), 'colspan' => '3'),
  );

  $curlypages = array();

  foreach (element_children($form['curlypages']) as $cpid) {
    $form['curlypages'][$cpid]['weight']['#attributes']['class'] = 'curlypage-weight';

    $curlypages[] = array(
      'data' => array(
        drupal_render($form['curlypages'][$cpid]['name']),
        drupal_render($form['curlypages'][$cpid]['group']),
        drupal_render($form['curlypages'][$cpid]['link']),
        drupal_render($form['curlypages'][$cpid]['peel_position']),
        array(
          'data' => drupal_render($form['curlypages'][$cpid]['status']),
          'class' => 'checkbox'
        ),
        drupal_render($form['curlypages'][$cpid]['weight']),
        drupal_render($form['curlypages'][$cpid]['clone']),
        drupal_render($form['curlypages'][$cpid]['edit']),
        drupal_render($form['curlypages'][$cpid]['delete']),
      ),
      'class' => 'draggable',
    );
  }

  $output = '';

  if (count($curlypages)) {
    $output .= theme('table', $header, $curlypages, array('id' => 'order-curlypages'));
  }

  $output .= drupal_render($form);

  drupal_add_tabledrag('order-curlypages', 'order', 'sibling', 'curlypage-weight');

  return $output;
}

/**
 * Submit: List of curlypages.
 */
function curlypage_list_form_submit($form, &$form_state) {

  $num_enabled_curlypages = 0;

  // for each curlypage update its status and its weight.
  foreach (element_children($form['curlypages']) as $cpid) {
    $curlypage->cpid   = $form['curlypages'][$cpid]['cpid']['#value'];
    $curlypage->weight = $form['curlypages'][$cpid]['weight']['#value'];
    $curlypage->status = $form['curlypages'][$cpid]['status']['#value'];

    if ($curlypage->status) {
      $num_enabled_curlypages++;
    }

    drupal_write_record('curlypages', $curlypage, 'cpid');
  }

  // Update the persistent variable num_enabled_curlypages that tracks number of curlypages enabled
  variable_set('num_enabled_curlypages', $num_enabled_curlypages);

  cache_clear_all();

}

/**
 * Menu callback; displays the curlypage configuration form.
 *
 * Using the same form for three different operations ($op):
 * - 'edit': edit an existing curlypage (default)
 * - 'add': add a new curlypage
 * - 'clone': clone an existing curlypage
 */
function curlypage_admin_edit($form_state, $curlypage, $op = 'edit') {

  if ($op == 'add' || !$curlypage->cpid) {
    $curlypage = curlypage_get_default();
  }

  if ($op == 'clone') {
    $curlypage->cpid = 0;
  }

  // Add Farbtastic color picker
  drupal_add_css('misc/farbtastic/farbtastic.css', 'module', 'all', TRUE);
  drupal_add_js('misc/farbtastic/farbtastic.js', 'module', 'header', FALSE, TRUE, TRUE);

  $form = array();

  $form['#attributes'] = array('enctype' => "multipart/form-data");

  $form['cpid'] = array(
    '#type' => 'value',
    '#value' => $curlypage->cpid,
  );

  $media_textfields = variable_get('curlypage_media_textfields', 0);
  $form['media_textfields'] = array(
    '#type' => 'value',
    '#value' => $media_textfields,
  );

  // Info
  $form['info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Curlypage info'),
    '#collapsible' => TRUE,
    '#weight' => -100,
  );

  $form['info']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable curlypage'),
    '#default_value' => $curlypage->status,
    '#description' => t('If this setting is enabled, the current curlypage is shown on the configured pages (you can edit visibility settings below).'),
  );

  // previous status of this curlypage before starting configuration
  $form['info']['previous_status'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->status,
  );

  $form['info']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Curlypage name'),
    '#default_value' => $curlypage->name,
    '#required' => TRUE,
    '#maxlength' => 64,
    '#size' => 40,
  );

  $form['info']['curlypage_group'] = array(
    '#type' => 'select',
    '#title' => t('Group'),
    '#description' => t('The group this curlypage belongs to.'),
    '#options' => curlypage_get_options('curlypage_group'),
    '#default_value' => $curlypage->curlypage_group,
    '#required' => TRUE,
  );
  // End Info

  // Details
  $form['details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Curlypage details'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 100,
  );

  // Position settings.
  $form['details']['position_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Position Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Set position of curlypage ( topleft, topright, bottomleft or bottomright).
  $form['details']['position_settings']['peel_position'] = array(
    '#type' => 'radios',
    '#title' => t('Corner'),
    '#description' => t('In what corner the ad will be displayed.'),
    '#options' => curlypage_get_options('peel_position'),
    '#default_value' => $curlypage->peel_position,
    '#required' => TRUE,
    '#attributes' => array('onclick' => 'check_peel_position()'),
  );

  // Disable absolute position model if curlypage is set on bottom corner
  $peel_position_check_js = "function check_peel_position() {\n";
  $peel_position_check_js .= "(function($) {\n";
  $peel_position_check_js .= "if ($('#edit-peel-position-bottomleft').attr('checked') || $('#edit-peel-position-bottomright').attr('checked')) {\n";
  $peel_position_check_js .= "$('#edit-peel-position-model-absolute').attr('disabled', true);\n";
  $peel_position_check_js .= "$('#edit-peel-position-model-fixed').attr('checked', true);\n";
  $peel_position_check_js .= "} else {\n";
  $peel_position_check_js .= "$('#edit-peel-position-model-absolute').removeAttr('disabled');\n";
  $peel_position_check_js .= "}\n";
  $peel_position_check_js .= "}) (jQuery);\n";
  $peel_position_check_js .= "}";

  drupal_add_js($peel_position_check_js, 'inline');

  // Set position model of peageear ( absolute | fixed ).
  $form['details']['position_settings']['peel_position_model'] = array(
    '#type' => 'radios',
    '#title' => t('Position Model'),
    '#description' => t('The CSS Position model you would prefer to use.'),
    '#options' => curlypage_get_options('peel_position_model'),
    '#default_value' => $curlypage->peel_position_model,
    '#required' => TRUE,
  );

  $peel_position_model_ini_js = "(function($){\n";
  $peel_position_model_ini_js .= "$(document).ready(function() {\n";
  $peel_position_model_ini_js .= "if ($('#edit-peel-position-bottomleft').attr('checked') || $('#edit-peel-position-bottomright').attr('checked')) {\n";
  $peel_position_model_ini_js .= "$('#edit-peel-position-model-absolute').attr('disabled', true);\n";
  $peel_position_model_ini_js .= "}\n";
  $peel_position_model_ini_js .= "});\n";
  $peel_position_model_ini_js .= "}) (jQuery);";

  drupal_add_js($peel_position_model_ini_js, 'inline');
  // End Position settings.


  // Wait settings.
  $form['details']['wait_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Wait Icon Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['details']['wait_settings']['wait_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable wait icon'),
    '#default_value' => $curlypage->wait_enable,
    '#description' => t('If this setting is enabled, a wait icon will be displayed while curlypage is loading.'),
  );

  // Set wait icon width
  $form['details']['wait_settings']['wait_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Wait Icon Width'),
    '#required' => TRUE,
    '#default_value' => $curlypage->wait_width,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );

  // Set wait icon height
  $form['details']['wait_settings']['wait_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Wait Icon Height'),
    '#required' => TRUE,
    '#default_value' => $curlypage->wait_height,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );

  // URL to wait icon.
  if ($media_textfields) {
    $form['details']['wait_settings']['wait_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Wait icon'),
      '#default_value' => check_plain($curlypage->wait_url),
      '#size' => 40,
      '#maxlength' => 255,
      '#required' => TRUE,
    );
  }
  else {
    $form['details']['wait_settings']['wait_url'] = array(
      '#type' => 'item',
      '#title' => t('Wait icon'),
      '#value' => check_plain($curlypage->wait_url),
    );
  }

  $form['details']['wait_settings']['wait_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an image to show while curlypage is loading (most common an animated GIF, Wait Icon Width x Wait Icon Height pixels).'),
    '#tree' => FALSE,
    '#size' => 40,
  );
  // End wait settings.


  // Style settings.
  $form['details']['style_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Style Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Style of flag ('style1' | 'style2').
  $form['details']['style_settings']['flag_style'] = array(
    '#type' => 'select',
    '#title' => t('Flag Style'),
    '#options' => curlypage_get_options('flag_style'),
    '#default_value' => $curlypage->flag_style,
    '#required' => TRUE,
  );

  // Style of peel ('style1' | 'style2').
  $form['details']['style_settings']['peel_style'] = array(
    '#type' => 'select',
    '#title' => t('Peel Style'),
    '#options' => curlypage_get_options('peel_style'),
    '#default_value' => $curlypage->peel_style,
    '#required' => TRUE,
  );
  // End Style settings.


  // Size Settings.
  $form['details']['size_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Size Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Design sizes are 100x100px and 500x500px for flag and peel respectively. If you decide to use a custom size try to use logical values. For example it makes not sense to use a larger size for the flag than for the peel. For a further explanation refer to <a href="!curlypage_size_manual">howto on home page</a>.', array('!curlypage_size_manual' => url('http://www.curlypage.co.cc/content/size-settings', array('external' => TRUE)))),
  );

  // Set flag width
  $form['details']['size_settings']['flag_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Flag Width'),
    '#required' => TRUE,
    '#default_value' => $curlypage->flag_width,
    '#maxlength' => 4,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );

  // Set flag height
  $form['details']['size_settings']['flag_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Flag Height'),
    '#required' => TRUE,
    '#default_value' => $curlypage->flag_height,
    '#maxlength' => 4,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );

  // Set peel width
  $form['details']['size_settings']['peel_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Peel Width'),
    '#required' => TRUE,
    '#default_value' => $curlypage->peel_width,
    '#maxlength' => 5,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );

  // Set peel height
  $form['details']['size_settings']['peel_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Peel Height'),
    '#required' => TRUE,
    '#default_value' => $curlypage->peel_height,
    '#maxlength' => 5,
    '#size' => 8,
    '#field_suffix' => 'px.',
  );
  // End Size settings.


  // Image Settings.
  $form['details']['image_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // URL to small image.
  if ($media_textfields) {
    $form['details']['image_settings']['small_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Unpeeled image'),
      '#default_value' => check_plain($curlypage->small_url),
      '#size' => 40,
      '#maxlength' => 255,
      '#required' => TRUE,
    );
  }
  else {
    $form['details']['image_settings']['small_url'] = array(
      '#type' => 'item',
      '#title' => t('Unpeeled image'),
      '#value' => check_plain($curlypage->small_url),
    );
  }

  $form['details']['image_settings']['small_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an image or flash movie to show when the ad is not peeled (JPG, GIF, PNG or SWF, Flag Width x Flag Height pixels).'),
    '#tree' => FALSE,
    '#size' => 40,
  );

  // URL to big image.
  if ($media_textfields) {
    $form['details']['image_settings']['big_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Peeled image'),
      '#default_value' => check_plain($curlypage->big_url),
      '#size' => 40,
      '#maxlength' => 255,
      '#required' => TRUE,
    );
  }
  else {
    $form['details']['image_settings']['big_url'] = array(
      '#type' => 'item',
      '#title' => t('Peeled image'),
      '#value' => check_plain($curlypage->big_url),
    );
  }

  $form['details']['image_settings']['big_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an image or flash movie to show when the ad is peeled (JPG, GIF, PNG or SWF, Peel Width x Peel Height pixels).'),
    '#tree' => FALSE,
    '#size' => 40,
  );

  // Mirror image ( true | false ).
  $form['details']['image_settings']['mirror'] = array(
    '#type' => 'checkbox',
    '#title' => t('Back mirror'),
    '#default_value' => $curlypage->mirror,
    '#description' => t('Mirror the ad on the back of the peeled page.'),
  );

  // In Transition for curlypage.
  $form['details']['image_settings']['in_transition'] = array(
    '#type' => 'select',
    '#title' => t('In Transition'),
    '#description' => t('In Transition for the curlypage.'),
    '#options' => curlypage_get_options('in_transition'),
    '#default_value' => $curlypage->in_transition,
    '#required' => TRUE,
  );

  // Duration of in transition (1-9).
  $form['details']['image_settings']['transition_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Transition Duration'),
    '#description' => t('Duration of in transition. (1-9)'),
    '#required' => TRUE,
    '#default_value' => $curlypage->transition_duration,
    '#maxlength' => 1,
    '#size' => 8,
  );

  // Style of peel back color.
  $form['details']['image_settings']['peel_color_style'] = array(
    '#type' => 'radios',
    '#title' => t('Back color style'),
    '#description' => t('Choose a flat or gradient color for the back of the peel.'),
    '#options' => curlypage_get_options('peel_color_style'),
    '#default_value' => $curlypage->peel_color_style,
    '#required' => TRUE,
  );

  // Color of peel back.
  $form['details']['image_settings']['peel_color'] = array(
    '#type' => 'radios',
    '#title' => t('Back color'),
    '#description' => t('This color will be used on the back of peel.'),
    '#options' => curlypage_get_options('peel_color'),
    '#default_value' => $curlypage->peel_color,
    '#required' => TRUE,
  );

  // Custom color.
  $form['details']['image_settings']['custom_color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom Color'),
    '#collapsible' => TRUE,
  );

  // Custom Color on Peel.
  $form['details']['image_settings']['custom_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom Color'),
    '#required' => TRUE,
    '#prefix' => '<div id="curlypage-customcolor-picker"></div>',
    '#default_value' => curlypage_rgb2hex($curlypage->red_value, $curlypage->green_value, $curlypage->blue_value),
    '#maxlength' => 7,
    '#size' => 8,
  );

  $customcolor_picker_ini = "(function($) {\n";
  $customcolor_picker_ini .= "$(document).ready(function() {\n";
  $customcolor_picker_ini .= "$('#curlypage-customcolor-picker').farbtastic('#edit-custom-color');\n";
  $customcolor_picker_ini .= "})\n";
  $customcolor_picker_ini .= "}) (jQuery);";

  drupal_add_js($customcolor_picker_ini, 'inline');

  // Red Value for Custom Color Peel.
  $form['details']['image_settings']['red_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->red_value,
  );

  // Green Value for Custom Color Peel.
  $form['details']['image_settings']['green_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->green_value,
  );

  // Blue Value for Custom Color Peel.
  $form['details']['image_settings']['blue_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->blue_value,
  );
  // End Image Settings.


  // Sound Settings.
  $form['details']['sound_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sound Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // URL to onload sound.
  if ($media_textfields) {
    $form['details']['sound_settings']['load_sound_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Onload Sound'),
      '#default_value' => check_plain($curlypage->load_sound_url),
      '#size' => 40,
      '#maxlength' => 255,
    );
  }
  else {
    $form['details']['sound_settings']['load_sound_url'] = array(
      '#type' => 'item',
      '#title' => t('Onload Sound'),
      '#value' => check_plain($curlypage->load_sound_url),
    );
  }

  if ($curlypage->load_sound_url != "") {
    $form['details']['sound_settings']['load_sound_remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete sound'),
      '#default_value' => 0,
      '#description' => t('Check this box if you want to remove load sound.'),
    );
  }

  $form['details']['sound_settings']['load_sound_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an mp3 file to play when the ad is loaded.'),
    '#tree' => FALSE,
    '#size' => 40,
  );

  // URL to open peel sound.
  if ($media_textfields) {
    $form['details']['sound_settings']['open_sound_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Open Peel Sound'),
      '#default_value' => check_plain($curlypage->open_sound_url),
      '#size' => 40,
      '#maxlength' => 255,
    );
  }
  else {
    $form['details']['sound_settings']['open_sound_url'] = array(
      '#type' => 'item',
      '#title' => t('Open Peel Sound'),
      '#value' => check_plain($curlypage->open_sound_url),
    );
  }

  if ($curlypage->open_sound_url != "") {
    $form['details']['sound_settings']['open_sound_remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete sound'),
      '#default_value' => 0,
      '#description' => t('Check this box if you want to remove open sound.'),
    );
  }

  $form['details']['sound_settings']['open_sound_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an mp3 file to play when the peel is opened.'),
    '#tree' => FALSE,
    '#size' => 40,
  );

  // URL to close peel sound.
  if ($media_textfields) {
    $form['details']['sound_settings']['close_sound_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Close Peel Sound'),
      '#default_value' => check_plain($curlypage->close_sound_url),
      '#size' => 40,
      '#maxlength' => 255,
    );
  }
  else {
    $form['details']['sound_settings']['close_sound_url'] = array(
      '#type' => 'item',
      '#title' => t('Close Peel Sound'),
      '#value' => check_plain($curlypage->close_sound_url),
    );
  }

  if ($curlypage->close_sound_url != "") {
    $form['details']['sound_settings']['close_sound_remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Delete sound'),
      '#default_value' => 0,
      '#description' => t('Check this box if you want to remove close sound.'),
    );
  }

  $form['details']['sound_settings']['close_sound_url_upload'] = array(
    '#type' => 'file',
    '#description' => t('Upload an mp3 file to play when the peel is closed.'),
    '#tree' => FALSE,
    '#size' => 40,
  );
  // End Sound Settings.


   // Linking Settings.
  $form['details']['linking_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('URL Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Link Enable ( true | false ).
  $form['details']['linking_settings']['link_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $curlypage->link_enabled,
    '#description' => t('Enable or disable the link.'),
  );

  // URL to open on curlypage click.
  $form['details']['linking_settings']['link'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#description' => t('URL to go when user click on the ad.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->link,
    '#size' => 40,
  );

  // Browser target (new) or self (self).
  $form['details']['linking_settings']['link_target'] = array(
    '#type' => 'radios',
    '#title' => t('URL target'),
    '#description' => t('Where to open the URL.'),
    '#options' => curlypage_get_options('link_target'),
    '#default_value' => $curlypage->link_target,
    '#required' => TRUE,
  );
  //End Linking Settings.


  // Motion Settings.
  $form['details']['motion_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Motion Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Open curlypage on click instead of on mouse over.
  $form['details']['motion_settings']['open_onclick'] = array(
    '#type' => 'checkbox',
    '#title' => t('Open Onclick'),
    '#default_value' => $curlypage->open_onclick,
    '#description' => t('Curlypage opens with a mouse over by default. If you check this box it will open on click.'),
  );

  // Speed of flag movement (1-9).
  $form['details']['motion_settings']['flag_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Flag motion speed'),
    '#description' => t('Speed for flag motion. (1-9)'),
    '#required' => TRUE,
    '#default_value' => $curlypage->flag_speed,
    '#maxlength' => 1,
    '#size' => 8,
  );

  // Speed of peel movement (1-9).
  $form['details']['motion_settings']['peel_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Peel motion speed'),
    '#description' => t('Speed for peel motion. (1-9)'),
    '#required' => TRUE,
    '#default_value' => $curlypage->peel_speed,
    '#maxlength' => 1,
    '#size' => 8,
  );

  // Opens curlypage automaticaly after configured seconds.
  $form['details']['motion_settings']['automatic_open'] = array(
    '#type' => 'textfield',
    '#title' => t('Automatically peel on load'),
    '#description' => t('Unpeel automatically when the page loads after configured seconds. 0 means no automatically open.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->automatic_open,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 's.',
  );

  // Seconds until curlypage close after automatically open.
  $form['details']['motion_settings']['automatic_close'] = array(
    '#type' => 'textfield',
    '#title' => t('Automatically unpeel'),
    '#description' => t('Automatically close after unpeeling after configured seconds. 0 means no automatically unpeel.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->automatic_close,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 's.',
  );
  // End Motion Settings.


  // Close button settings.
  $form['details']['closebutton_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Close Button Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Clickable button on open peel ( true | false ).
  $form['details']['closebutton_settings']['close_button_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close Button'),
    '#default_value' => $curlypage->close_button_enable,
    '#description' => t('Show a close button on open peel. If this is enabled the peel will not close on mouse out. Users must click button to close peel.'),
  );

  // Text on close button.
  $form['details']['closebutton_settings']['text_on_close_button'] = array(
    '#type' => 'textfield',
    '#title' => t('Close Button Text'),
    '#description' => t('Text on clickable close button.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->text_on_close_button,
    '#maxlength' => 20,
    '#size' => 40,
  );

  // Close Button Color.
  $form['details']['closebutton_settings']['closebutton_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Close Button Color'),
    '#required' => TRUE,
    '#prefix' => '<div id="curlypage-closebuttoncolor-picker"></div>',
    '#default_value' => curlypage_rgb2hex($curlypage->close_red_value, $curlypage->close_green_value, $curlypage->close_blue_value),
    '#maxlength' => 7,
    '#size' => 8,
  );

  $closebuttoncolor_picker_ini = "(function($) {\n";
  $closebuttoncolor_picker_ini .= "$(document).ready(function() {\n";
  $closebuttoncolor_picker_ini .= "$('#curlypage-closebuttoncolor-picker').farbtastic('#edit-closebutton-color');\n";
  $closebuttoncolor_picker_ini .= "})\n";
  $closebuttoncolor_picker_ini .= "}) (jQuery);";

  drupal_add_js($closebuttoncolor_picker_ini, 'inline');

  // Close Button Color Red Value.
  $form['details']['closebutton_settings']['close_red_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->close_red_value,
  );

  // Close Button Color Green Value.
  $form['details']['closebutton_settings']['close_green_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->close_green_value,
  );

  // Close Button Color Blue Value.
  $form['details']['closebutton_settings']['close_blue_value'] = array(
    '#type' => 'hidden',
    '#value' => $curlypage->close_blue_value,
  );
  // End Close Button Settings.


  // Time Settings
  $form['details']['time_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Curlypage Time Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['details']['time_settings']['delay'] = array(
    '#type' => 'textfield',
    '#title' => t('Delay'),
    '#description' => t('Delay seconds before the curlypage is shown.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->delay,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 's.',
  );
  $form['details']['time_settings']['time_slot'] = array(
    '#type' => 'textfield',
    '#title' => t('Time Slot'),
    '#description' => t('Amoung of time in seconds to show this curlypage. Set it to 0 if you want the curlypage to be shown forever.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->time_slot,
    '#maxlength' => 3,
    '#size' => 8,
    '#field_suffix' => 's.',
  );
  $form['details']['time_settings']['repeat_times'] = array(
    '#type' => 'textfield',
    '#title' => t('Repeat'),
    '#description' => t('For grouped curlypages you can configure how many times this curlypage would be repeated. Set it to 0 if you want the curlypage to be repeated forever.'),
    '#required' => TRUE,
    '#default_value' => $curlypage->repeat_times,
    '#maxlength' => 1,
    '#size' => 8,
  );
  // End Time Settings

  // Visibility settings.
  $form['visibility_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Curlypage visibility settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 500,
  );

  // Language-based visibility settings - only visible if 'locale' module enabled
  if (module_exists('locale')) {
    $form['visibility_settings']['language_vis_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Language specific visibility settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $default_language_values = array();
    $result = db_query("SELECT language FROM {curlypage_languages} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
    while ($language = db_fetch_object($result)) {
      $default_language_values[] = $language->language;
    }
    $language_options = locale_language_list();
    $form['visibility_settings']['language_vis_settings']['languages'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Show curlypage for specific languages'),
      '#options' => $language_options,
      '#default_value' => $default_language_values,
      '#description' => t('Show the curlypage only for the selected language(s). If you select no languages, the curlypage will be visible for all languages.'),
    );
  }

  // Role-based visibility settings (mostly borrowed from 'block.admin.inc')
  $default_role_values = array();
  $result = db_query("SELECT rid FROM {curlypage_roles} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
  while ($role = db_fetch_object($result)) {
    $default_role_values[] = $role->rid;
  }
  $result = db_query('SELECT rid, name FROM {role} ORDER BY name');
  $role_options = array();
  while ($role = db_fetch_object($result)) {
    $role_options[$role->rid] = $role->name;
  }
  $form['visibility_settings']['roles_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Role specific visibility settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['visibility_settings']['roles_vis_settings']['roles_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show curlypage for specific roles'),
    '#options' => curlypage_get_options('roles_visibility'),
    '#default_value' => $curlypage->roles_visibility,
  );
  $form['visibility_settings']['roles_vis_settings']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#options' => $role_options,
    '#default_value' => $default_role_values,
    '#description' => t('Select the role(s) you want to include or exclude. If you select no roles, the curlypage will be visible to all users.'),
  );

  // Node type based visibility settings
  $default_node_type_values = array();
  $result = db_query("SELECT type FROM {curlypage_node_types} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
  while ($node_type = db_fetch_object($result)) {
    $default_node_type_values[] = $node_type->type;
  }
  $node_types = array_keys(node_get_types());
  $node_type_options = array();
  foreach ($node_types as $type) {
    $node_type_options[$type] = $type;
  }
  $form['visibility_settings']['node_types_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types specific visibility settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['visibility_settings']['node_types_vis_settings']['types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' => $node_type_options,
    '#default_value' => $default_node_type_values,
    '#description' => t('Select the content type(s) where you want to include this curlypage. If you select no types, the curlypage will be visible on all content types.'),
  );

  // Page visibility settings
  $form['visibility_settings']['page_vis_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page specific visibility settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $access = user_access('use PHP for curlypage visibility');

  if ($curlypage->visibility == 2 && !$access) {
    $form['visibility_settings']['page_vis_settings'] = array();
    $form['visibility_settings']['page_vis_settings']['visibility'] = array(
      '#type' => 'value',
      '#value' => 2,
    );
    $form['visibility_settings']['page_vis_settings']['pages'] = array(
      '#type' => 'value',
      '#value' => $curlypage->pages,
    );
  }
  else {
    $options = array(
      t('Show on every page except the listed pages.'),
      t('Show on only the listed pages.')
    );
    $description = t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));

    if ($access) {
      $options[] = t('Show if the following PHP code returns <code>TRUE</code> (PHP-mode, experts only).');
      $description .= ' '. t('If the PHP-mode is chosen, enter PHP code between %php. Note that executing incorrect PHP-code can break your Drupal site.', array('%php' => '<?php ?>'));
    }
    $form['visibility_settings']['page_vis_settings']['visibility'] = array(
      '#type' => 'radios',
      '#title' => t('Show curlypage on specific pages'),
      '#options' => $options,
      '#default_value' => $curlypage->visibility,
    );
    $form['visibility_settings']['page_vis_settings']['pages'] = array(
      '#type' => 'textarea',
      '#title' => t('Pages'),
      '#default_value' => $curlypage->pages,
      '#description' => $description,
    );
  }

  // Allow submodules to add elements to the form.
  $modules = module_implements('curlypage_form');
  if (!empty($modules)) {
    foreach ($modules as $module) {
      $func = $module .'_curlypage_form';
      $func($form, $form_state);
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 900,
  );

  $form['cancel'] = array(
    '#type' => 'markup',
    '#value' => l(t('Cancel'), referer_uri()),
    '#weight' => 901,
  );

  return $form;

}

/**
 * hook_validate: validation function for the curlypage configuration form.
 */
function curlypage_admin_edit_validate($form, &$form_state) {

  // Sizes validation
  if (!is_numeric($form_state['values']['wait_width']) || $form_state['values']['wait_width'] < 10) {
    form_set_error('wait_width', t('Wait Icon Width must be a number greater than 10'));
  }
  if (!is_numeric($form_state['values']['wait_height']) || $form_state['values']['wait_height'] < 10) {
    form_set_error('wait_height', t('Wait Icon Height must be a number greater than 10'));
  }
  if (!is_numeric($form_state['values']['flag_width']) || $form_state['values']['flag_width'] < 10) {
    form_set_error('flag_width', t('Flag Width must be a number greater than 10'));
  }
  if (!is_numeric($form_state['values']['flag_height']) || $form_state['values']['flag_height'] < 10) {
    form_set_error('flag_height', t('Flag Height must be a number greater than 10'));
  }
  if (!is_numeric($form_state['values']['peel_width']) || $form_state['values']['peel_width'] < 50) {
    form_set_error('peel_width', t('Peel Width must be a number greater than 50'));
  }
  if (!is_numeric($form_state['values']['peel_height']) || $form_state['values']['peel_height'] < 50) {
    form_set_error('peel_height', t('Peel Height must be a number greater than 50'));
  }

  // Duration of transition validation
  if (!is_numeric($form_state['values']['transition_duration']) || $form_state['values']['transition_duration'] == 0) {
    form_set_error('transition_duration', t('Transition duration must be a number between 1 and 9'));
  }

  // Peel custom color validation.
  // If user sets color manually with input textfield wrong hex values would be ignored by conversion function.
  $custom_rgb_peel_color = curlypage_hex2rgb($form_state['values']['custom_color']);
  form_set_value($form['details']['image_settings']['red_value'], $custom_rgb_peel_color[0], $form_state);
  form_set_value($form['details']['image_settings']['green_value'], $custom_rgb_peel_color[1], $form_state);
  form_set_value($form['details']['image_settings']['blue_value'], $custom_rgb_peel_color[2], $form_state);

  // Flag speed validation
  if (!is_numeric($form_state['values']['flag_speed']) || $form_state['values']['flag_speed'] == 0) {
    form_set_error('flag_speed', t('Flag motion speed must be a number between 1 and 9'));
  }

  // Peel speed validation
  if (!is_numeric($form_state['values']['peel_speed']) || $form_state['values']['peel_speed'] == 0) {
    form_set_error('peel_speed', t('Peel motion speed must be a number between 1 and 9'));
  }

  // AutomaticOpen validation
  if (!is_numeric($form_state['values']['automatic_open']) || $form_state['values']['automatic_open'] < 0) {
    form_set_error('automatic_open', t('Automatically peel onload seconds must be a number between 0 and 999'));
  }

  // AutomaticClose validation
  if (!is_numeric($form_state['values']['automatic_close']) || $form_state['values']['automatic_close'] < 0) {
    form_set_error('automatic_close', t('Automatically peel onclose seconds must be a number between 0 and 999'));
  }

  // Close button color validation
  // If user sets color manually with input textfield wrong hex values would be ignored by conversion function.
  $custom_rgb_close_button_color = curlypage_hex2rgb($form_state['values']['closebutton_color']);
  form_set_value($form['details']['closebutton_settings']['close_red_value'], $custom_rgb_close_button_color[0], $form_state);
  form_set_value($form['details']['closebutton_settings']['close_green_value'], $custom_rgb_close_button_color[1], $form_state);
  form_set_value($form['details']['closebutton_settings']['close_blue_value'], $custom_rgb_close_button_color[2], $form_state);

  // Text on close button
  if (preg_match("/^[a-z][a-z ]+$/", $form_state['values']['text_on_close_button']) == 0) {
    form_set_error('text_on_close_button', t('Only lowercase letters and spaces are allowed for text on close button. It must start with a lowercase letter too.'));
  }

  // Delay validation
  if (!is_numeric($form_state['values']['delay']) || $form_state['values']['delay'] < 0) {
    form_set_error('delay', t('Delay seconds must be a number between 0 and 999'));
  }

  // TimeSlot validation
  if (!is_numeric($form_state['values']['time_slot']) || $form_state['values']['time_slot'] < 0) {
    form_set_error('time_slot', t('TimeSlot seconds must be a number between 0 and 999'));
  }

  // Repeat validation
  if (!is_numeric($form_state['values']['repeat_times'])) {
    form_set_error('repeat_times', t('Repeat must be a number between 0 and 9'));
  }

  if (!form_get_errors()) {

    $resolution = $form_state['values']['wait_width'] .'x'. $form_state['values']['wait_height'];
    $validators = array(
      'file_validate_is_image' => array(),
      'file_validate_image_resolution' => array($resolution, $resolution),
    );
    $file = file_save_upload('wait_url_upload', $validators);
    if ($file) {
      form_set_value($form['details']['wait_settings']['wait_url_upload'], $file, $form_state);
    }
    else {
      form_set_value($form['details']['wait_settings']['wait_url'], $form['details']['wait_settings']['wait_url']['#value'], $form_state);
      if ($form_state['values']['media_textfields'] && !file_exists($form_state['values']['wait_url'])) {
        form_set_error('wait_url', t('The path is not correct.'));
      }
    }

    // uploads images from image upload fields
    foreach (array('small_url', 'big_url') as $image) {

      if ($image == 'small_url') {
        $resolution = $form_state['values']['flag_width'] .'x'. $form_state['values']['flag_height'];
      }
      else {
        $resolution = $form_state['values']['peel_width'] .'x'. $form_state['values']['peel_height'];
      }
      $validators = array(
        'file_validate_extensions' => array('gif jpg png swf'),
        'file_validate_image_resolution' => array($resolution, $resolution),
      );
      $file = file_save_upload($image .'_upload', $validators);
      if ($file) {
        form_set_value($form['details']['image_settings'][$image .'_upload'], $file, $form_state);
      }
      else {
        form_set_value($form['details']['image_settings'][$image], $form['details']['image_settings'][$image]['#value'], $form_state);
        if ($form_state['values']['media_textfields'] && !file_exists($form_state['values'][$image])) {
          form_set_error($image, t('The path is not correct.'));
        }
      }

    }

    // uploads images from sound upload fields
    foreach (array('load_sound_url', 'open_sound_url', 'close_sound_url') as $sound) {

      $validators = array(
        'file_validate_extensions' => array('mp3'),
      );
      $file = file_save_upload($sound .'_upload', $validators);
      if ($file) {
        form_set_value($form['details']['sound_settings'][$sound .'_upload'], $file, $form_state);
      }
      else {
        form_set_value($form['details']['sound_settings'][$sound], $form['details']['sound_settings'][$sound]['#value'], $form_state);
        if ($form_state['values']['media_textfields'] && $form_state['values'][$sound] &&  !file_exists($form_state['values'][$sound])) {
          form_set_error($sound, t('The path is not correct.'));
        }
      }

    }

  }

  // Remove sounds checked for removal
  if (isset($form_state['values']['load_sound_remove']) && $form_state['values']['load_sound_remove']) {
    form_set_value($form['details']['sound_settings']['load_sound_url'], '', $form_state);
  }
  if (isset($form_state['values']['open_sound_remove']) && $form_state['values']['open_sound_remove']) {
    form_set_value($form['details']['sound_settings']['open_sound_url'], '', $form_state);
  }
  if (isset($form_state['values']['close_sound_remove']) && $form_state['values']['close_sound_remove']) {
    form_set_value($form['details']['sound_settings']['close_sound_url'], '', $form_state);
  }

  // Allow submodules to do is validation phase.
  $modules = module_implements('curlypage_form_validate');
  if (!empty($modules)) {
    foreach ($modules as $module) {
      $func = $module .'_curlypage_form_validate';
      $func($form, $form_state);
    }
  }

}

/**
 * hook_submit: submit function for the curlypage configuration form.
 */
function curlypage_admin_edit_submit($form, &$form_state) {

  // Save the edited curlypage
  if (!form_get_errors()) {

    $new_curlypage = new stdClass();

    if ($form_state['values']['cpid']) {
      $new_curlypage->cpid = $form_state['values']['cpid'];
    }
    else { // we are adding or cloning
      // create new curlypage record
      $new_curlypage->pages = '';
      drupal_write_record('curlypages', $new_curlypage);
      form_set_value($form['cpid'], $new_curlypage->cpid, $form_state);
    }

    $new_curlypage->status                 = $form_state['values']['status'];
    $new_curlypage->name                   = $form_state['values']['name'];
    $new_curlypage->peel_position          = $form_state['values']['peel_position'];
    $new_curlypage->peel_position_model    = $form_state['values']['peel_position_model'];
    $new_curlypage->wait_enable            = $form_state['values']['wait_enable'];
    $new_curlypage->wait_width             = $form_state['values']['wait_width'];
    $new_curlypage->wait_height            = $form_state['values']['wait_height'];
    $new_curlypage->wait_url               = $form_state['values']['wait_url'];
    $new_curlypage->flag_style             = $form_state['values']['flag_style'];
    $new_curlypage->peel_style             = $form_state['values']['peel_style'];
    $new_curlypage->flag_width             = $form_state['values']['flag_width'];
    $new_curlypage->flag_height            = $form_state['values']['flag_height'];
    $new_curlypage->peel_width             = $form_state['values']['peel_width'];
    $new_curlypage->peel_height            = $form_state['values']['peel_height'];
    $new_curlypage->small_url              = $form_state['values']['small_url'];
    $new_curlypage->big_url                = $form_state['values']['big_url'];
    $new_curlypage->mirror                 = $form_state['values']['mirror'];
    $new_curlypage->in_transition          = $form_state['values']['in_transition'];
    $new_curlypage->transition_duration    = $form_state['values']['transition_duration'];
    $new_curlypage->peel_color_style       = $form_state['values']['peel_color_style'];
    $new_curlypage->peel_color             = $form_state['values']['peel_color'];
    $new_curlypage->red_value              = $form_state['values']['red_value'];
    $new_curlypage->green_value            = $form_state['values']['green_value'];
    $new_curlypage->blue_value             = $form_state['values']['blue_value'];
    $new_curlypage->link_enabled           = $form_state['values']['link_enabled'];
    $new_curlypage->link_target            = $form_state['values']['link_target'];
    $new_curlypage->link                   = $form_state['values']['link'];
    $new_curlypage->load_sound_url         = $form_state['values']['load_sound_url'];
    $new_curlypage->open_sound_url         = $form_state['values']['open_sound_url'];
    $new_curlypage->close_sound_url        = $form_state['values']['close_sound_url'];
    $new_curlypage->flag_speed             = $form_state['values']['flag_speed'];
    $new_curlypage->peel_speed             = $form_state['values']['peel_speed'];
    $new_curlypage->automatic_open         = $form_state['values']['automatic_open'];
    $new_curlypage->automatic_close        = $form_state['values']['automatic_close'];
    $new_curlypage->close_button_enable    = $form_state['values']['close_button_enable'];
    $new_curlypage->text_on_close_button   = $form_state['values']['text_on_close_button'];
    $new_curlypage->close_red_value        = $form_state['values']['close_red_value'];
    $new_curlypage->close_green_value      = $form_state['values']['close_green_value'];
    $new_curlypage->close_blue_value       = $form_state['values']['close_blue_value'];
    $new_curlypage->roles_visibility       = $form_state['values']['roles_visibility'];
    $new_curlypage->visibility             = $form_state['values']['visibility'];
    $new_curlypage->pages                  = $form_state['values']['pages'];
    $new_curlypage->curlypage_group        = $form_state['values']['curlypage_group'];
    $new_curlypage->delay                  = $form_state['values']['delay'];
    $new_curlypage->time_slot              = $form_state['values']['time_slot'];
    $new_curlypage->repeat_times           = $form_state['values']['repeat_times'];
    $new_curlypage->open_onclick           = $form_state['values']['open_onclick'];

    // checks if directory exist and creates it if it doesn't
    $dir = file_directory_path() .'/'. CURLYPAGE_PATH_IMAGES;
    file_check_directory($dir, FILE_CREATE_DIRECTORY);

    // Copy any images or sounds uploaded
    foreach (array('wait_url', 'small_url', 'big_url', 'load_sound_url', 'open_sound_url', 'close_sound_url') as $image_sound) {
      $file = $form_state['values'][$image_sound .'_upload'];
      if ($file) {
        $info = pathinfo($file->filename);
        $dest = $dir .'/'. $image_sound .'_'. $new_curlypage->cpid .'.'. $info['extension'];
        file_copy($file, $dest, FILE_EXISTS_RENAME);
        $new_curlypage->$image_sound = $file->filepath;
      }
    }

    drupal_write_record('curlypages', $new_curlypage, 'cpid');

    // Update the persistent variable num_enabled_curlypages that tracks number of curlypages enabled
    if ($form_state['values']['status'] != $form_state['values']['previous_status']) {
      if ($form_state['values']['status']) {
        variable_set('num_enabled_curlypages', variable_get('num_enabled_curlypages', 0) + 1);
      }
      else {
        variable_set('num_enabled_curlypages', variable_get('num_enabled_curlypages', 1) - 1);
      }
    }

    // Save language visibility
    if (module_exists('locale')) {
      db_query("DELETE FROM {curlypage_languages} WHERE cpid = %d", array(':cpid' => $new_curlypage->cpid));
      foreach (array_filter($form_state['values']['languages']) as $language) {
        db_query("INSERT INTO {curlypage_languages} (cpid, language) VALUES (%d, '%s')", array(':cpid' => $new_curlypage->cpid, ':language' => $language));
      }
    }

    // Save roles visibility
    db_query("DELETE FROM {curlypage_roles} WHERE cpid = %d", array(':cpid' => $new_curlypage->cpid));
    foreach (array_filter($form_state['values']['roles']) as $rid) {
      db_query("INSERT INTO {curlypage_roles} (cpid, rid) VALUES (%d, %d)", array(':cpid' => $new_curlypage->cpid, ':rid' => $rid));
    }

    // Save node types visibility
    db_query("DELETE FROM {curlypage_node_types} WHERE cpid = %d", array(':cpid' => $new_curlypage->cpid));
    foreach (array_filter($form_state['values']['types']) as $type) {
      db_query("INSERT INTO {curlypage_node_types} (cpid, type) VALUES (%d, '%s')", array(':cpid' => $new_curlypage->cpid, ':type' => $type));
    }

    // Allow submodules to do is validation phase.
    $modules = module_implements('curlypage_form_submit');
    if (!empty($modules)) {
      foreach ($modules as $module) {
        $func = $module .'_curlypage_form_submit';
        $func($form, $form_state);
      }
    }

    cache_clear_all();
    drupal_set_message(t('The curlypage %name has been saved.', array('%name' => $form_state['values']['name'])));
    $form_state['redirect'] = 'admin/build/curlypage';

  }

  return;
}

/**
 * Deletes images and sounds for specific curlypage.
 */
function _curlypage_delete_images_sounds($cpid) {

  $dir = file_directory_path() .'/'. CURLYPAGE_PATH_IMAGES;
  // if the directory where files reside does not exists nothing to do
  if (!file_check_directory($dir)) {
    return;
  }

  file_scan_directory($dir, '.*url_'. $cpid .'.*', array('.', '..', 'CVS'), 'file_delete', TRUE);

}

/**
 * Menu callback; confirm deletion of a curlypage.
 */
function curlypage_admin_delete($form_state, $curlypage) {
  $form['curlypage'] = array('#type' => 'hidden', '#value' => serialize($curlypage));
  $params = array('%name' => $curlypage->name);
  return confirm_form($form, t('Are you sure you want to delete the curlypage %name?', $params), 'admin/build/curlypage', NULL, t('Delete'), t('Cancel'));
}

function curlypage_admin_delete_submit($form, &$form_state) {
  $curlypage = unserialize($form_state['values']['curlypage']);
  if ($curlypage->status) {
    variable_set('num_enabled_curlypages', variable_get('num_enabled_curlypages', 1) - 1);
  }
  db_query("DELETE FROM {curlypages} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
  db_query("DELETE FROM {curlypage_languages} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
  db_query("DELETE FROM {curlypage_roles} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));
  db_query("DELETE FROM {curlypage_node_types} WHERE cpid = %d", array(':cpid' => $curlypage->cpid));

  _curlypage_delete_images_sounds($curlypage->cpid);

  module_invoke_all('curlypage_delete', $curlypage);

  cache_clear_all();

  drupal_set_message(t('The curlypage %name has been removed.', array('%name' => $curlypage->name)));
  $form_state['redirect'] = 'admin/build/curlypage';
  return;
}

/**
 * Curlypage global settings form
 */
function curlypage_settings() {
  $form = array();

  $description = t("Check this box if you want to be able to configure the media paths directly instead of using the upload fields.");
  $description .= ' '. t("Use absolute paths. Example: sites/default/files/curlypage/small.jpg");

  $form['curlypage_media_textfields'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow media paths'),
    '#default_value' => variable_get('curlypage_media_textfields', 0),
    '#description' => $description,
  );

  $description = t("Curlypage swf files are published with flash player 9 compatibility.");
  $description .= ' '. t("So you can only use flash 9 swf files on your curlypages.");
  $description .= ' '. t("Check this box if you want to use flash 10 swf files on your curlypages.");

  $form['curlypage_flash_v10'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use version 10 swfs'),
    '#default_value' => variable_get('curlypage_flash_v10', 0),
    '#description' => $description,
  );

  $form['curlypage_swfobject_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('swfobject settings'),
  );

  $form['curlypage_swfobject_settings']['curlypage_internal_swfobject'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use internal swfobject'),
    '#default_value' => variable_get('curlypage_internal_swfobject', 0),
    '#description' => t("Check this if you want to use a version of swfobject from your server. Configure the path to the file below."),
  );

  $default_swfobject_path = variable_get('curlypage_swfobject_path', 'sites/default/files/curlypage/swfobject.js');
  $form['curlypage_swfobject_settings']['curlypage_swfobject_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#default_value' => $default_swfobject_path,
    '#size' => 40,
    '#maxlength' => 255,
    '#description' => t("Path to swfobject.js file on your server."),
  );

  return system_settings_form($form);
}

/**
 * Validation of settings form.
 */
function curlypage_settings_validate($form, &$form_state) {
  $path = $form_state['values']['curlypage_swfobject_path'];
  if ($form_state['values']['curlypage_internal_swfobject'] && !file_exists($path)) {
    form_set_error('curlypage_swfobject_path', t('The file is not on that path.'));
  }
}

/**
 * Helper functions for color conversions
 */
function curlypage_hex2rgb($color) {

  if ($color[0] == '#') {
    $color = drupal_substr($color, 1);
  }

  if (drupal_strlen($color) == 6) {
    list($r, $g, $b) = array(
      $color[0] . $color[1],
      $color[2] . $color[3],
      $color[4] . $color[5]
    );
  }
  elseif (drupal_strlen($color) == 3) {
    list($r, $g, $b) = array(
      $color[0] . $color[0],
      $color[1] . $color[1],
      $color[2] . $color[2]
    );
  }
  else {
    return array(0, 0, 0);
  }

  $r = hexdec($r);
  $g = hexdec($g);
  $b = hexdec($b);
  return array($r, $g, $b);
}

function curlypage_rgb2hex($r, $g=-1, $b=-1) {

  if (is_array($r) && sizeof($r) == 3) {
    list($r, $g, $b) = $r;
  }

  $r = intval($r);
  $g = intval($g);
  $b = intval($b);

  $r = dechex($r<0?0:($r>255?255:$r));
  $g = dechex($g<0?0:($g>255?255:$g));
  $b = dechex($b<0?0:($b>255?255:$b));

  $color = (drupal_strlen($r) < 2?'0':'') . $r;
  $color .= (drupal_strlen($g) < 2?'0':'') . $g;
  $color .= (drupal_strlen($b) < 2?'0':'') . $b;
  return '#'. $color;
}
