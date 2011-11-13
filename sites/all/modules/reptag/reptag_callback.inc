<?php
// $Id: reptag_callback.inc,v 1.1.2.2 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Utility for the Admin UI
 */

require_once(drupal_get_path('module', 'reptag') .'/reptag_admin.inc');
require_once(drupal_get_path('module', 'reptag') .'/reptag_admin_table.inc');

/**
 * Function _reptag_callback().
 */
function _reptag_callback($op, $param, $nojs = FALSE) {
  global $user;
  
  $title = FALSE;
  $multilang = (variable_get('reptag_locale_enable', 0) && (variable_get('language_count', 1) >= 2));
  
  // Call js callback routines (add, remove, edit, ...)
  switch ($op) {
    case 'tagadmin':
      $dialog = TRUE;
      $title = ($param == 'user') ? t('Add new user tag') : t('Add new site tag');
      if (is_numeric($param)) {
        $title = _reptag_rtid2uid($param) ? t('Edit user tag') : t('Edit site tag');
      }
      $result = drupal_get_form('_reptag_admin_addedit_form', $param);
      break;
    case 'refresh':
      $_GET['q'] = 'admin/settings/reptag/'. $param;
      $_GET['page'] = isset($_POST['page']) ? $_POST['page'] : '';
      $uid = ($param == 'user') ? $user->uid : 0;
      $lang = empty($_POST['language']) ? NULL : $_POST['language'];
      $result = drupal_get_form('_reptag_admin_table_builder', $uid, $lang);
      break;
  }
  
  if (!$nojs) {
    if ($messages = drupal_get_messages('error')) {
      drupal_json((object)array('success' => FALSE, 'errors' => $messages['error']));
    }
    else {
      $html = $title ? theme('reptag_dialog', $result, t('Rep[lacement]Tags Dialog: ') . $title) : $result;
      drupal_json((object)array('success' => TRUE, 'html' => $html));
    }
    exit();
  }
  
  //
  drupal_set_title(t('Rep[lacement]Tags: ') . $title);
  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l(t('Rep[lacement]Tags'), $_REQUEST['destination']);
  drupal_set_breadcrumb($breadcrumb);
  $fieldset = array(
    '#title' => '',
    '#value' => isset($result) ? $result : $html,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#attributes' => array()
  );
  
  return theme('fieldset', $fieldset);
}
