<?php
// $Id: itunes.admin.inc,v 1.8 2010/05/25 15:30:57 drewish Exp $

/**
 * @file
 * Admin settings for iTunes.
 */

/**
 * Settings form.
 */
function itunes_admin_settings() {
  $node_types = node_get_types();
  $content_module_exists = module_exists('content');
  $content_types = $content_module_exists ? content_types() : array();

  // Build a list of node types that iTunes could operate on.
  $options = array();
  foreach ($node_types as $type) {
    $options[$type->type] = $type->name;
  }
  $form['itunes_types'] = array(
    '#title' => t('Enable iTunes fields'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('itunes_types', array('audio')),
  );

  // If FileField is enabled allow selection of the enclosure's source.
  if ($content_module_exists && module_exists('filefield')) {
    $fields = variable_get('itunes_enclosure_source', array());
    $form['itunes_enclosure_source'] = array(
      '#tree' => TRUE,
    );
    // Build the node's filefield selector.
    foreach ($node_types as $type) {
      $content = $content_types[$type->type];
      $options = array(NULL => t('- None -'));
      foreach ($content['fields'] as $field_name => $field) {
        if ($field['type'] == 'filefield' || $field['type'] == 'emaudio') {
          $options[$field_name] = $field['widget']['label'];
        }
      }
      $form['itunes_enclosure_source'][$type->type] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => empty($fields[$type->type]) ? NULL : $fields[$type->type],
        '#access' => count($options) > 1,
      );
    }
  }

  // If taxonomy is enabled allow selection of the tags' source.
  if (module_exists('taxonomy')) {
    $vocabs = variable_get('itunes_keyword_source', array());
    $form['itunes_keyword_source'] = array(
      '#tree' => TRUE,
    );
    foreach ($node_types as $type) {
      $type_vocabs = taxonomy_get_vocabularies($type->type);
      $options = array(NULL => t('- None -'));
      foreach ($type_vocabs as $vid => $vocab) {
        $options[$vid] = $vocab->name;
      }
      $form['itunes_keyword_source'][$type->type] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => empty($vocabs[$type->type]) ? NULL : $vocabs[$type->type],
        '#access' => count($options) > 1,
      );
    }
  }

  // Allow selection of the author's source.
  $author_source = variable_get('itunes_author_source', array());
  $form['itunes_author_source'] = array(
    '#tree' => TRUE,
  );
  foreach ($node_types as $type) {
    $options = array(
      NULL => t('- None -'),
      'node_author' => t('Node author'),
    );
    if ($content_module_exists) {
      $content = $content_types[$type->type];
      foreach ($content['fields'] as $field_name => $field) {
        if ($field['type'] == 'text' && $field['widget']['type'] == 'text_textfield') {
          $options[$field_name] = $field['widget']['label'];
        }
        elseif ($field['type'] == 'userreference') {
          $options[$field_name] = $field['widget']['label'];
        }
      }
    }
    $form['itunes_author_source'][$type->type] = array(
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => empty($author_source[$type->type]) ? NULL : $author_source[$type->type],
    );
  }

  $form = system_settings_form($form);
  $form['#validate'][] = 'itunes_admin_settings_validate';
  $form['#theme'] = 'itunes_admin_settings';
  return $form;
}

function itunes_admin_settings_validate($form, &$form_state) {
  // Retrieve selected types - Forms API sets the value of unselected checkboxes to 0.
  $form_state['values']['itunes_types'] = array_keys(array_filter($form_state['values']['itunes_types']));
}

function theme_itunes_admin_settings($form) {
  $rows = array();
  $header = array($form['itunes_types']['#title']);
  unset($form['itunes_types']['#title']);

  $has_filefields = FALSE;
  $has_vocabularies = FALSE;
  foreach (element_children($form['itunes_types']) as $key) {
    $row = array(drupal_render($form['itunes_types'][$key]));
    if (isset($form['itunes_enclosure_source'][$key])) {
      $row[] = drupal_render($form['itunes_enclosure_source'][$key]);
      $has_filefields = TRUE;
    }
    if (isset($form['itunes_keyword_source'][$key])) {
      $row[] = drupal_render($form['itunes_keyword_source'][$key]);
      $has_vocabularies = TRUE;
    }
    $row[] = drupal_render($form['itunes_author_source'][$key]);

    $rows[] = $row;
  }

  if ($has_filefields) {
    $header[] = t('FileField to list in RSS feeds');
  }
  if ($has_vocabularies) {
    $header[] = t('Vocabulary to use as keywords');
  }
  $header[] = t('Source to use as author');

  return theme('table', $header, $rows) . drupal_render($form);
}