<?php
// $Id: reptag_admin_table.inc,v 1.1.2.4 2009/01/08 03:24:01 dman Exp $

/** 
 * @file
 * Utility CRUD and rendering functions for the reptag admin UI
 */

define('RETAG_PAGER_LENGTH',  25);

/**
 * Function _reptag_admin_site_form().
 * (tags administration: site-wide tags)
 */
function _reptag_admin_site_form(&$form_state) {
  $form['site'] = array(
    '#type' => 'fieldset',
    '#title' => t('SiteWide - Rep[lacement]Tags'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  $form['site'][] = _reptag_admin_tags_form($form_state);
  
  return _reptag_admin_form($form);
}

/**
 * Function _reptag_admin_user_form().
 * (tags administration: user tags)
 */
function _reptag_admin_user_form(&$form_state) {
  global $user;  
  $form['user'] = array(
    '#type' => 'fieldset',
    '#title' => t('User - Rep[lacement]Tags'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  $form['user'][] = _reptag_admin_tags_form($form_state, $user->uid);
  
  return _reptag_admin_form($form);
}

/**
 * Function _reptag_admin_table_form().
 * (tags administration: table form)
 */
function _reptag_admin_tags_form(&$form_state, $uid = 0, $lang = NULL) {
  // Language switcher
  $lang = isset($lang) ? $lang : arg(4);
  $languages = language_list('enabled');
  $lang = array_key_exists($lang, $languages[1]) ? $lang : language_default('language');
  $form['headbar'] = array('#theme' => 'reptag_table_headbar');
  if (variable_get('reptag_locale_enable', 0)) {
    foreach ($languages[1] as $language) {
      $links[$language->language] = l(
        $language->native,
        'admin/settings/reptag/'. ($uid ? 'user' : 'site') . (($language->language == language_default('language')) ? '' : '/'. $language->language)
      );
    }
    $form['headbar'] = array(
      '#value' => theme('submenu', $links),
      '#prefix' => '<div class=\'reptag-headbar\'>',
      '#suffix' => '</div>',
    );
  }
  
  // Include JS (for js-based tags administration)
  if (variable_get('reptag_javascript', 1)) {
    drupal_add_js('misc/jquery.form.js');
    drupal_add_js(drupal_get_path('module', 'reptag') .'/js/jquery.blockUI.js');
    $settings = array(
      'mode' => $uid ? 'user' : 'site',
      'language' => isset($lang) ? $lang : ''
    );
    drupal_add_js(array('reptag' => $settings), 'setting');
  }
  
  // Include the actual table
  $form = array_merge($form, _reptag_admin_table_builder($form_state, $uid, $lang));
  $form['tags']['#prefix'] = '<div id=\'reptag-tags-admin-wrapper\'>';
  $form['tags']['#suffix'] = '</div>';
  
  $form['addbtn'] = array(
    '#type' => 'image_button',
    '#title' => t('Add'),
    '#src' => drupal_get_path('module', 'reptag') .'/images/add.png',
    '#attributes' => array('class' => 'reptag-tags-add'),
    '#submit' => array('_reptag_admin_tags_nojs'),
    '#url' => 'admin/settings/reptag/nojs/tagadmin/'. ($uid ? 'user' : 'site')
  );
  
  return $form;
}

/**
 * Function _reptag_admin_table_builder().
 */
function _reptag_admin_table_builder(&$form_state, $uid = 0, $lang = NULL) {
  $form['tags'] = array(
    '#tree' => TRUE,
    '#parents' => array()
  );
  $form['tags']['table'] = array(
    '#theme' => 'reptag_table',
    '#header' => array(t('Tag'), '', t('Replacement'), '', ''),
    '#empty' => t('There are currently no tags defined.'),
    '#attributes' => array('id' => 'reptag-tags-admin-table')
  );
  
  $multilang = variable_get('reptag_locale_enable', 0) && (variable_get('language_count', 1) >= 2);
  
  // Load tags table
  $reptag_table = _reptag_table_load(array($uid), REPTAG_LOADTAG_EDIT, $lang, RETAG_PAGER_LENGTH);
  foreach ($reptag_table as $rtid => $item) {
    $form['tags']['table'][$rtid]['tag'] = array(
      '#type' => 'textfield',
      '#default_value' => $item['tag'],
      '#size' => 20,
      '#maxlength' => 255,
      '#attributes' => array('readonly' => 'readonly')
    );
    $form['tags']['table'][$rtid]['arrow'] = array(
      '#value' => '<img src="'. base_path() . drupal_get_path('module', 'reptag') .'/images/arrow.png" alt="" />'
    );
    if (variable_get('reptag_textarea', 1)) {
      $form['tags']['table'][$rtid]['replacement'] = array(
        '#type' => 'textarea',
        '#default_value' => $item['replacement'],
        '#rows' => 1,
        '#cols' => 60,
        '#maxlength' => 1024,
        '#attributes' => $multilang ? array('readonly' => 'readonly') : array()
      );
    }
    else {
      $form['tags']['table'][$rtid]['replacement'] = array(
        '#type' => 'textfield',
        '#default_value' => $item['replacement'],
        '#size' => 65,
        '#maxlength' => 1024,
        '#attributes' => $multilang ? array('readonly' => 'readonly') : array()
      );
    }
    $form['tags']['table'][$rtid]['edit'] = array(
      '#type' => 'image_button',
      '#title' => t('Edit'),
      '#src' => drupal_get_path('module', 'reptag') .'/images/edit.png',
      '#attributes' => array('class' => 'reptag-tags-edit'),
      '#submit' => $multilang ? array('_reptag_admin_tags_nojs') : array('_reptag_admin_tags_edit'),
      '#url' => 'admin/settings/reptag/nojs/tagadmin/'. $rtid,
      '#rtid' => $rtid
    );
    $form['tags']['table'][$rtid]['delete'] = array(
      '#type' => 'image_button',
      '#title' => t('Delete'),
      '#src' => drupal_get_path('module', 'reptag') .'/images/delete.png',
      '#attributes' => array('class' => 'reptag-tags-delete'),
      '#submit' => array('_reptag_admin_tags_delete'),
      '#rtid' => $rtid
    );
  }
  
  if (count($reptag_table)) {
    $form['tags']['pager'] = array('#value' => theme('pager', array(), RETAG_PAGER_LENGTH));
  }
  
  $form['uid'] = array('#type' => 'value', '#value' => $uid);

  return $form;
}

/**
 * Function _reptag_admin_addedit_form().
 * (tags administration: add/edit tags)
 */
function _reptag_admin_addedit_form(&$form_state, $rtid) {
  global $user;
  
  //
  $type = 'add';
  $uid = ($rtid == 'user') ? $user->uid : 0;
  if (is_numeric($rtid)) {
    $type = 'edit';
    $reptag = _reptag_table_load_tag($rtid, REPTAG_LOADTAG_EDIT);
    $uid = $reptag['uid'];
  }
  
  $form[$type] = array(
    '#tree' => TRUE,
    '#parents' => array()
  );
  
  $multilang = variable_get('reptag_locale_enable', 0) && (variable_get('language_count', 1) >= 2);
  if (!$multilang) {
    $form[$type]['table'] = array(
      '#theme' => 'reptag_table',
      '#header' => array(t('Tag'), '', t('Replacement')),
      '#attributes' => array('id' => 'reptag-tags-admin-'. $type)
    );
    $form[$type]['table'][$type]['tag'] = array(
      '#type' => 'textfield',
      '#default_value' => isset($reptag) ? $reptag['tag'] : '',
      '#size' => 20,
      '#maxlength' => 255
    );
    $form[$type]['table'][$type]['arrow'] = array(
      '#value' => '<img src="'. base_path() . drupal_get_path('module', 'reptag') .'/images/arrow.png" alt="" />'
    );
    if (variable_get('reptag_textarea', 1)) {
      $form[$type]['table'][$type]['replacement'] = array(
        '#type' => 'textarea',
        '#default_value' => isset($reptag) ? $reptag['replacements']['en']['replacement'] : '',
        '#rows' => 3,
        '#cols' => 60,
        '#maxlength' => 1024
      );
    }
    else {
      $form[$type]['table'][$type]['replacement'] = array(
        '#type' => 'textfield',
        '#default_value' => isset($reptag) ? $reptag['replacements']['en']['replacement'] : '',
        '#size' => 65,
        '#maxlength' => 1024
      );
    }
    $form[$type]['table'][$type]['rtid'] = array(
      '#type' => 'value',
      '#value' => isset($reptag) ? $reptag['replacements']['en']['rtid'] : '',
    );
  }
  else {
    $form[$type]['table'] = array('#theme' => 'reptag_table_multi');
    $form[$type]['table']['tag']['tag']['label'] = array('#value' => t('Tag'));
    $form[$type]['table']['tag']['tag']['arrow'] = array(
      '#value' => '<img src="'. base_path() . drupal_get_path('module', 'reptag') .'/images/arrow.png" alt="" />'
    );
    $form[$type]['table']['tag']['tag']['tag'] = array(
      '#type' => 'textfield',
      '#default_value' => isset($reptag) ? $reptag['tag'] : '',
      '#size' => 20,
      '#maxlength' => 255,
      '#parents' => array('table', $type, 'tag')
    );
    $languages = language_list('enabled');
    foreach ($languages[1] as $language) {
      $form[$type]['table']['replacements']['#section'] = t('Replacements');
      $form[$type]['table']['replacements'][$language->language]['label'] = array(
        '#value' => $language->native
      );
      $form[$type]['table']['replacements'][$language->language]['arrow'] = array(
        '#value' => '<img src="'. base_path() . drupal_get_path('module', 'reptag') .'/images/arrow.png" alt="" />'
      );
      if (variable_get('reptag_textarea', 1)) {
        $form[$type]['table']['replacements'][$language->language]['replacement'] = array(
          '#type' => 'textarea',
          '#default_value' => isset($reptag['replacements'][$language->language]) ? $reptag['replacements'][$language->language]['replacement'] : '',
          '#rows' => 3,
          '#cols' => 60,
          '#maxlength' => 1024,
          '#parents' => array('table', $type, 'replacements', $language->language, 'replacement')
        );
      }
      else {
        $form[$type]['table']['replacements'][$language->language]['replacement'] = array(
          '#type' => 'textfield',
          '#default_value' => isset($reptag['replacements'][$language->language]) ? $reptag['replacements'][$language->language]['replacement'] : '',
          '#size' => 65,
          '#maxlength' => 1024,
          '#parents' => array('table', $type, 'replacements', $language->language, 'replacement')
        );
      }
      $form[$type]['table']['replacements'][$language->language]['rtid'] = array(
        '#type' => 'value',
        '#value' => isset($reptag['replacements'][$language->language]) ? $reptag['replacements'][$language->language]['rtid'] : '',
        '#parents' => array('table', $type, 'replacements', $language->language, 'rtid')
      );
    }
  }
  
  $form['uid'] = array('#type' => 'value', '#value' => $uid);
  $form[$type .'btn'] = array(
    '#type' => 'image_button',
    '#title' => is_numeric($rtid) ? t('Edit') : t('Add'),
    '#src' => drupal_get_path('module', 'reptag') .'/images/'. $type .'.png',
    '#attributes' => array('class' => 'reptag-tags-'. $type),
    '#submit' => array('_reptag_admin_tags_'. $type)
  );
  
  return $form;
}

/**
 * Function _reptag_admin_tags_nojs().
 */
function _reptag_admin_tags_nojs($form, &$form_state) {
  if (isset($form_state['clicked_button']['#url'])) {
    drupal_goto($form_state['clicked_button']['#url'], drupal_get_destination());
  }
}

/**
 * Function _reptag_admin_tags_save().
 */
function _reptag_admin_tags_save($form, &$form_state) {
  _reptag_admin_tags_add($form, $form_state);
  _reptag_admin_tags_edit($form, $form_state);
}

/**
 * Function _reptag_admin_tags_reset().
 */
function _reptag_admin_tags_reset($form, &$form_state) {
  _reptag_table_clear($form_state['values']['uid']);
}

/**
 * Function _reptag_admin_tags_add().
 */
function _reptag_admin_tags_add($form, &$form_state) {
  if (isset($form_state['values']['table']['add']) && !empty($form_state['values']['table']['add']['tag'])) {
    $reptag = $form_state['values']['table']['add'];
    if (isset($reptag['replacement'])) {
      _reptag_table_add('#\$'. strtoupper($reptag['tag']) .'\$#si', $reptag['replacement'], $form_state['values']['uid']);
    }
    else {
      foreach ($reptag['replacements'] as $lang => $replacement) {
        _reptag_table_add('#\$'. strtoupper($reptag['tag']) .'\$#si', $replacement['replacement'], $form_state['values']['uid'], $lang);
      }
    }
  }
}

/**
 * Function _reptag_admin_tags_edit().
 */
function _reptag_admin_tags_edit($form, &$form_state) {
  if (isset($form_state['values']['table'])) {
    foreach ($form_state['values']['table'] as $key => $reptag) {
      $reptag['rtid'] = isset($reptag['rtid']) ? $reptag['rtid'] : $key;
      if (isset($reptag['replacement'])) {
        _reptag_table_update($reptag['rtid'], '#\$'. strtoupper($reptag['tag']) .'\$#si', $reptag['replacement'], $form_state['values']['uid']);
      }
      else {
        foreach ($reptag['replacements'] as $lang => $replacement) {
          if ($replacement['rtid']) {
            if (empty($reptag['tag']) || empty($replacement['replacement'])) {
              _reptag_table_del($replacement['rtid']);
            }
            else {
              _reptag_table_update($replacement['rtid'], '#\$'. strtoupper($reptag['tag']) .'\$#si', $replacement['replacement'], $form_state['values']['uid'], $lang);
            }
          }
          else {
            if (!empty($reptag['tag']) && !empty($replacement['replacement'])) {
              _reptag_table_add('#\$'. strtoupper($reptag['tag']) .'\$#si', $replacement['replacement'], $form_state['values']['uid'], $lang);
            }
          }
        }
      }
    }
  }
}

/**
 * Function _reptag_admin_tags_delete().
 */
function _reptag_admin_tags_delete($form, &$form_state) {
  if (isset($form_state['clicked_button']['#rtid'])) {
    _reptag_table_del($form_state['clicked_button']['#rtid']);
  }
}

/**
 * Function theme_reptag_table_multi().
 */
function theme_reptag_table_multi($form) {
  $header = isset($form['#header']) ? $form['#header'] : array();
  $attributes = isset($form['#attributes']) ? $form['#attributes'] : array();

  $rows = array();
  foreach (element_children($form) as $section) {
    if (isset($form[$section]['#section'])) {
      $rows[] = array(array('data' => check_plain($form[$section]['#section']), 'class' => 'region', 'colspan' => count($header)));
    }
    foreach (element_children($form[$section]) as $key) {
      $row = array();
      foreach (element_children($form[$section][$key]) as $item) {
        $row[] = drupal_render($form[$section][$key][$item]);
      }
      $rows[] = $row;
    }
  }
  
  return count($rows) ? theme('table', $header, $rows, $attributes) : '';
}
