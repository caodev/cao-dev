<?php
// $Id: reptag_admin.inc,v 1.16.2.5 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * FAPI and admin UI routines
 */

require_once(drupal_get_path('module', 'reptag') .'/reptag_admin_table.inc');

/**
 * Function _reptag_admin_general_form().
 * (administration pages: general settings)
 */
function _reptag_admin_general_form() {
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General - Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  $form['general']['reptag_preview'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Rep[lacement]Tags in Preview'),
    '#default_value' => variable_get('reptag_preview', 1),
    '#description' => t('Run replacement process for tags on node previews.')
  );
  $form['general']['reptag_showhelp'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show \'Rep[lacement]Tags - Help\' section on add/edit node pages'),
    '#default_value' => variable_get('reptag_showhelp', 1),
    '#description' => t('Display a collapsible fieldset containing all available tags on node forms.')
  );
  $form['general']['reptag_tableprio'] = array(
    '#type' => 'checkbox',
    '#title' => t('Privilege SiteWide tags over User tags'),
    '#default_value' => variable_get('reptag_tableprio', 0),
    '#description' => t('By default users can override site wide tags with their own tags.')
  );
  
  // Cache settings
  $form['general']['cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cache - Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => '2'
  );
  $form['general']['cache']['reptag_cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Partial PageCache'),
    '#default_value' => variable_get('reptag_cache', 0),
    '#description' => t('<i>(recommended at least for high traffic sites)</i><br />
                         Expand static tags on form submission and cache the result. Only dynamic tags are processed on page view.<br />
                         To disable dynamic tags completely check \'Disable Dynamic Replacements\' below.')
  );
  $period = drupal_map_assoc(array(CACHE_TEMPORARY, 60, 180, 300, 600, 900, 1800, 2700, 3600, 10800, 21600, 32400, 43200, 86400, CACHE_PERMANENT), 'format_interval');
  $period[CACHE_TEMPORARY] = t('none');
  $period[CACHE_PERMANENT] = t('permanent');
  $form['general']['cache']['reptag_cache_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Minimum cache lifetime'),
    '#default_value' => variable_get('reptag_cache_lifetime', CACHE_PERMANENT),
    '#options' => $period,
    '#description' => t('Set the minimum cache lifetime before the cache expires.'),
    '#disabled' => !variable_get('reptag_cache', 0)
  );
  $form['general']['cache']['reptag_staticonly'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Dynamic Replacements'),
    '#default_value' => variable_get('reptag_staticonly', 0),
    '#description' => t('Run reptag on form submission only (disables certain modules, e.g. System, Block, ...).<br />
                         Modules affected by this option are marked \'Static\' = \'No\'.'),
    '#disabled' => !variable_get('reptag_cache', 0)
  );
  $form['general']['cache']['reptag_cache_clear_btn'] = array(
    '#type' => 'submit',
    '#value' => t('Clear cache'),
    '#disabled' => !variable_get('reptag_cache', 0),
    '#submit' => array('_reptag_admin_cache_clear')
  );
  // Expert - settings
  $form['general']['expert'] = array(
    '#type' => 'fieldset',
    '#title' => t('Expert - Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => '3'
  );
  $form['general']['expert']['reptag_parametric'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable parametric RepTags'),
    '#default_value' => variable_get('reptag_parametric', 0),
    '#description' => t('Enable parametric RepTags, i.e. \'$TEST{arg1,arg2}$\' => \'Replace with %arg1 and %arg2\'.')
  );
  $form['general']['expert']['reptag_disabled_nids'] = array(
    '#type' => 'textfield',
    '#title' => t('Disable RepTag for certain nodes'),
    '#default_value' => implode(', ', unserialize(variable_get('reptag_disabled_nids', serialize(array())))),
    '#size' => 75,
    '#maxlength' => 255,
    '#description' => t('Enter a list of comma-separated nids to disable RepTag for these nodes.')
  );
  if (module_exists('comment')) {
    $form['general']['expert']['reptag_enable_comments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable RepTag-Support for comments.'),
      '#default_value' => variable_get('reptag_enable_comments', 0),
      '#description' => t('Check this option to allow replacement tags (static tags only) for comments.')
    );
  }
  $form['general']['expert']['reptag_enable_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable RepTag to process node titles'),
    '#default_value' => variable_get('reptag_enable_title', 0),
    '#description' => t('<i>(Node title support is not available for full page rendered nodes!)</i><br />
                         With this option enabled you can select node titles for processing under
                         <a href="!content-types-settings">Content Types</a>.',
                         array('!content-types-settings' => url('admin/settings/reptag/admin/content')))
  );
  $form['general']['expert']['reptag_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Debugging'),
    '#default_value' => variable_get('reptag_debug', 0),
    '#description' => t('Print debug listings (print_r) of module variables.')
  );
  // User Interface
  $form['general']['ui'] = array(
    '#type' => 'fieldset',
    '#title' => t('UserInterface - Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => '4'
  );
  $form['general']['ui']['reptag_javascript'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Javascript/AJAX - Support'),
    '#default_value' => variable_get('reptag_javascript', 1),
    '#description' => t('Enable Javascript/AJAX - Support for administration pages.')
  );
  $form['general']['ui']['reptag_textarea'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use textareas for replacements'),
    '#default_value' => variable_get('reptag_textarea', 1),
    '#description' => t('Use resizable textareas instead of textfields for replacements in tags table.')
  );
  // Locale
  if (module_exists('locale') && (variable_get('language_count', 1) > 1)) {
    $form['general']['locale'] = array(
      '#type' => 'fieldset',
      '#title' => t('Language - Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => '5'
    );
    $form['general']['locale']['reptag_locale_enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable multi-lingual tags'),
      '#default_value' => variable_get('reptag_locale_enable', 0),
      '#description' => t('Allows you to have different sitewide-/user-tags for your languages.')
    );
    $form['general']['locale']['reptag_locale_binding'] = array(
      '#type' => 'checkbox',
      '#title' => t('Bind language to content'),
      '#default_value' => variable_get('reptag_locale_binding', 0),
      '#description' => t('Requires  \'translation\' module to be enabled. By default the negotiated site or user language
                           is used for replacements. With this option the language of the current node is used instead.'),
      '#disabled' => !module_exists('translation')
    );
    $form['general']['locale']['reptag_locale_mode'] = array(
      '#type' => 'select',
      '#title' => t('Language mode'),
      '#default_value' => variable_get('reptag_locale_mode', REPTAG_LOCALE_STRICT),
      '#options' => array(
        REPTAG_LOCALE_STRICT => t('Strict (active language only)'),
        REPTAG_LOCALE_FALLBACK => t('Fallback (active+default language)')
      ),
      '#description' => t('Select \'Fallback\' if you want the tags of the default language to be always available.
                           Otherwise tags that do not exist in the active language remain unaffected.')
    );
  }
  // Integration
  $form['general']['integration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Integration - Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => '6'
  );
  $form['general']['integration']['reptag_workspace'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Workspace - Integration'),
    '#default_value' => variable_get('reptag_workspace', 0),
    '#description' => t('Adds a tab to the user\'s workspace (requires \'Workspace\' module).'),
    '#disabled' => !module_exists('workspace')
  );
  
  return _reptag_admin_form($form, '_reptag_admin_general');
}

/**
 * Function _reptag_admin_clear_cache().
 */
function _reptag_admin_cache_clear($form, &$form_state) {
  _reptag_cache_clear();
}

/**
 * Function _reptag_admin_general_save().
 */
function _reptag_admin_general_save($form, &$form_state) {
  // General
  variable_set('reptag_preview', $form_state['values']['reptag_preview']);
  variable_set('reptag_showhelp', $form_state['values']['reptag_showhelp']);
  variable_set('reptag_tableprio', $form_state['values']['reptag_tableprio']);
  // Cache
  variable_set('reptag_cache', $form_state['values']['reptag_cache']);
  variable_set('reptag_cache_lifetime', $form_state['values']['reptag_cache_lifetime']);
  variable_set('reptag_staticonly', $form_state['values']['reptag_staticonly']);
  // Expert
  variable_set('reptag_parametric', $form_state['values']['reptag_parametric']);
  variable_set('reptag_disabled_nids', serialize(preg_split('/[\s,]+/', $form_state['values']['reptag_disabled_nids'])));
  variable_set('reptag_enable_comments', $form_state['values']['reptag_enable_comments']);
  variable_set('reptag_enable_title', $form_state['values']['reptag_enable_title']);
  variable_set('reptag_debug', $form_state['values']['reptag_debug']);
  // UI
  variable_set('reptag_javascript', $form_state['values']['reptag_javascript']);
  variable_set('reptag_textarea', $form_state['values']['reptag_textarea']);
  // Locale
  variable_set('reptag_locale_enable', $form_state['values']['reptag_locale_enable']);
  variable_set('reptag_locale_mode', $form_state['values']['reptag_locale_mode']);
  // Integration
  $workspace_status = variable_get('reptag_workspace', 0);
  variable_set('reptag_workspace', $form_state['values']['reptag_workspace']);
  if ($workspace_status != $form_state['values']['reptag_workspace']) {
    menu_rebuild();
  }

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Function _reptag_admin_general_reset().
 */
function _reptag_admin_general_reset($form, &$form_state) {
  // General
  variable_set('reptag_preview', 1);
  variable_set('reptag_showhelp', 1);
  variable_set('reptag_tableprio', 0);
  // Cache
  variable_set('reptag_cache', 0);
  variable_set('reptag_cache_lifetime', CACHE_PERMANENT);
  variable_set('reptag_staticonly', 0);
  // Expert
  variable_set('reptag_parametric', 0);
  variable_set('reptag_disabled_nids', serialize(array()));
  variable_set('reptag_enable_comments', 0);
  variable_set('reptag_enable_title', 0);
  variable_set('reptag_debug', 0);
  // UI
  variable_set('reptag_javascript', 1);
  variable_set('reptag_textarea', 1);
  // Locale
  variable_set('reptag_locale_enable', 0);
  variable_set('reptag_locale_mode', REPTAG_LOCALE_STRICT);
  // Integration
  variable_set('reptag_workspace', 0);
  
  drupal_set_message(t('The configuration has been reset to defaults.'));
}

/**
 * Function _reptag_admin_modules_form().
 * (administration pages: module settings)
 */
function _reptag_admin_modules_form() {
  $form['modules'] = array(
    '#type' => 'fieldset',
    '#title' => t('Modules'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#description' => t('This is a list of your installed modules. A growing number of contibuted modules is available
                         <a href="@contrib">here</a>.', array('@contrib' => 'http://www.profix898.de/drupal/reptag/modules'))
  );
  
  // Modules
  $form['modules']['table'] = array(
    '#theme' => 'reptag_table',
    '#header' => array('', t('Enabled'), t('Module'), t('Description'), t('Static'), t('Weight')),
    '#attributes' => array('id' => 'reptag-modules-table'),
    '#tabledrag' => 'weight'
  );
  $modules = _reptag_module_list(TRUE);
  foreach ($modules as $module => $details) {
    $disable_module = variable_get('reptag_cache', 0) && variable_get('reptag_staticonly', 0) && !$details['static'];
    $form['modules']['table'][$module]['space'] = array('#value' => '');
    $form['modules']['table'][$module]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => '',
      '#default_value' => $disable_module ? FALSE : $details['enabled'],
      '#prefix' => '<div align="center">',
      '#suffix' => '</div>',
      '#disabled' => $disable_module
    );
    $form['modules']['table'][$module]['module'] = array(
      '#value' => $module,
      '#prefix' => '<strong>',
      '#suffix' => '</strong>'
    );
    $form['modules']['table'][$module]['description'] = array(
      '#value' => $details['description'],
      '#prefix' => '<i>',
      '#suffix' => '</i>'
    );
    $form['modules']['table'][$module]['static'] = array(
      '#value' => $details['static'] ? t('Yes') : t('No'),
      '#prefix' => '<div align="center">',
      '#suffix' => '</div>'
    );
    $form['modules']['table'][$module]['weight'] = array(
      '#type' => 'weight',
      '#default_value' => $details['weight']
    );
  }
  
  return _reptag_admin_form($form, '_reptag_admin_modules');
}

/**
 * Function _reptag_admin_modules_submit().
 */
function _reptag_admin_modules_save($form, &$form_state) {
  $modules = _reptag_module_list();
  foreach ($form_state['values']['modules']['table'] as $module => $value) {
    $modules[$module]['enabled'] = $value['enabled'];
    $modules[$module]['weight'] = $value['weight'];
    // Check prerequisites
    if ($value['enabled']) {
      if (!_reptag_module_require($modules[$module])) {
        drupal_set_message(t('Module \'!module\' has been disabled!<br />It does not comply with all requirements
                              (e.g. module dependencies, PEAR packages, ...).', array('!module' => $module)), 'error');
        $modules[$module]['enabled'] = FALSE;
      }
    }
  }
  _reptag_module_register($modules);
  drupal_rebuild_theme_registry();
  
  drupal_set_message(t('The configuration options have been saved.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_modules_reset().
 */
function _reptag_admin_modules_reset($form, &$form_state) {
  _reptag_module_reset();
  
  drupal_set_message(t('The configuration has been reset to defaults.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_roles_form().
 * (administration pages: module settings)
 */
function _reptag_admin_roles_form() {
  $form['roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles / Permissions'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE
  );
  
  // Modules (.tags)
  $roles = user_roles();
  $modules = _reptag_module_list();
  ksort($modules);
  $form['roles']['table'] = array(
    '#theme' => 'reptag_table',
    '#header' => array_merge(array(t('Option / Module')), array_values($roles))
  );
  foreach ($modules as $module => $details) {
    $form['roles']['table'][$module]['label'] = array(
      '#value' => t('Module: !module', array('!module' => '<strong>'. $module .'</strong>')),
    );
    foreach (array_keys($roles) as $rid) {
      $form['roles']['table'][$module][$rid] = array(
        '#type' => 'checkbox',
        '#title' => '',
        '#default_value' => in_array($rid, $details['roles']),
        '#prefix' => '<div align="center">',
        '#suffix' => '</div>',
        '#disabled' => $details['enabled'] ? FALSE : TRUE
      );
    }    
  }
  // Spacer
  $form['roles']['table']['spacerB']['label'] = array('#value' => '');
  foreach (array_keys($roles) as $rid) {
    $form['roles']['table']['spacerB'][$rid] = array('#value' => '');
  }
  // Additional permissions
  $form['roles']['table']['plainrep']['label'] = array(
    '#value' => t('Plain text replacements only'),
    '#prefix' => '<strong>',
    '#suffix' => '</strong>'
  );
  foreach (array_keys($roles) as $rid) {
    $form['roles']['table']['plainrep'][$rid] = array(
      '#type' => 'checkbox',
      '#title' => '',
      '#default_value' => in_array($rid, (array)unserialize(variable_get('reptag_plainrep_roles', serialize(array())))),
      '#prefix' => '<div align="center">',
      '#suffix' => '</div>'
    );
  }
  
  // Exclude tags
  $form['roles']['exclude'] = array(
    '#type' => 'fieldset',
    '#title' => t('Exclude Tags'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE
  );
  $form['roles']['exclude']['table'] = array(
    '#theme' => 'reptag_table',
    '#header' => array(t('Exclude for role'), t('Tags'), '', ''),
    '#attributes' => array(
      'id' => 'reptag-exclude-table',
      'description' => t('<em>Enter tags to exclude seperated by \'|\', e.g. \'$MYTAG$\' or \'#{BACK}(.*?){/BACK}#s\'.</em>')
    )
  );
  foreach ($roles as $rid => $role) {
    $form['roles']['exclude']['table'][$rid]['role'] = array(
      '#value' => $role,
      '#prefix' => '<strong>',
      '#suffix' => '</strong>'
    );
    $form['roles']['exclude']['table'][$rid]['tags'] = array(
      '#type' => 'textfield',
      '#default_value' => _reptag_exclude_loadtags_string($rid),
      '#size' => 60,
      '#maxlength' => 1024,
      '#attributes' => array('class' => 'reptag-exclude-tags'),
    );
    $form['roles']['exclude']['table'][$rid]['append'] = array(
      '#type' => 'button',
      '#value' => t('Append'),
      '#attributes' => array('class' => 'reptag-exclude-append')
    );
    $form['roles']['exclude']['table'][$rid]['remove'] = array(
      '#type' => 'button',
      '#value' => t('Remove'),
      '#attributes' => array('class' => 'reptag-exclude-remove')
    );
  }
  
  if (variable_get('reptag_javascript', 1)) {
    $form['roles']['exclude']['exclude-js'] = array(
      '#type' => 'fieldset',
      '#title' => t('Exclude Tags Administration'),
      '#collapsible' => FALSE,
      '#attributes' => array('class' => 'reptag-exclude-wrapper')
    );
    $form['roles']['exclude']['exclude-js']['exclude-add'] = array(
      '#theme' => 'reptag_table',
      '#header' => array(t('Enter tag to exclude:'), ''),
      '#prefix' => '<div id=\'reptag-exclude-add-wrapper\'>',
      '#suffix' => '</div>'
    );
    $form['roles']['exclude']['exclude-js']['exclude-add']['add']['value'] = array(
      '#type' => 'textfield',
      '#title' => '',
      '#default_value' => '',
      '#size' => 50,
      '#maxlength' => 128,
      '#autocomplete_path' => 'reptag/autocomplete_all'
    );
    $form['roles']['exclude']['exclude-js']['exclude-add']['add']['button'] = array(
      '#type' => 'button',
      '#value' => t('Add'),
      '#name' => 'add'
    );
    //
    $form['roles']['exclude']['exclude-js']['exclude-remove'] = array(
      '#value' => '<div id=\'reptag-exclude-remove-wrapper\'></div>',
    );
  }
  
  return _reptag_admin_form($form, '_reptag_admin_roles');
}

/**
 * Function _reptag_admin_roles_save().
 */
function _reptag_admin_roles_save($form, &$form_state) {
  // Save roles configuration
  $modules = _reptag_module_list();
  foreach ($form_state['values']['roles']['table'] as $module => $role) {
    $roles = array();
    foreach ($role as $rid => $value) {
      if ($value) {
        $roles[] = $rid;
      }
    }
    if ($module == 'plainrep') {
      variable_set('reptag_plainrep_roles', serialize($roles));
    }
    else {
      $modules[$module]['roles'] = $roles;
    }
  }
  _reptag_module_register($modules);
  
  // Save exclude tags
  foreach ($form_state['values']['roles']['exclude']['table'] as $rid => $data) {
    if (is_array($data)) {
      _reptag_exclude_storetags_string($rid, $data['tags']);
    }
    else {
      _reptag_exclude_storetags_string($rid, $data);
    }
  }

  drupal_set_message(t('The configuration options have been saved.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_roles_reset().
 */
function _reptag_admin_roles_reset($form, &$form_state) {
  // Reset roles configuration
  $modules = _reptag_module_list();
  foreach ($form_state['values']['roles']['table'] as $module => $role) {
    $modules[$module]['roles'] = array();
  }
  _reptag_module_register($modules);
  variable_set('reptag_plainrep_roles', serialize(array(DRUPAL_ANONYMOUS_RID)));
  
  // Reset exclude tags
  foreach ($form_state['values']['roles']['exclude']['table'] as $rid => $data) {
    _reptag_exclude_storetags($rid, array());
  }
  
  drupal_set_message(t('The configuration has been reset to defaults.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_content_form().
 * (administration pages: content type settings)
 */
function _reptag_admin_content_form() {
  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content Types'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#description' => t('Choose the content fields to be processed. Reptag can only run on text fields.<br />
                         Unselecting all fields for a content type will disable reptag for that particular type.')
  );
  
  if (module_exists('content')) {
    _content_type_info(TRUE);
    $content_types = content_types();
  }
  else {
    $content_types = node_get_types('types');
    drupal_set_message(t('You only have the \'Body\' field available for selection because <a href="@cck">CCK</a>
                          is not installed.', array('@cck' => 'http://drupal.org/project/cck')), 'notice');
  }
  
  foreach ($content_types as $type) {
    $type = (array)$type;
    $fieldset = array(
      '#type' => 'fieldset',
      '#title' => ucfirst($type['name']),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE
    );
    $fieldset['table'] = array(
      '#theme' => 'reptag_table',
      '#header' => array(t('Field Label'), t('Type / Widget'), t('Process')),
      '#parents' => array('content', $type['type'])
    );
    $fields = (array)unserialize(variable_get('reptag_type_'. $type['type'] .'_fields', serialize(array('body'))));
    // Title field
    if ($type['has_title'] && variable_get('reptag_enable_title', 0)) {
      $fieldset['table']['title']['label'] = array(
        '#value' => isset($type['title_label']) ? $type['title_label'] : t('Title')
      );
      $fieldset['table']['title']['type'] = array('#value' => t('text'));
      $fieldset['table']['title']['process'] = array(
        '#type' => 'checkbox',
        '#title' => '',
        '#default_value' => in_array('title', $fields)
      );
    }
    // Body field
    if ($type['has_body']) {
      $fieldset['table']['body']['label'] = array(
        '#value' => isset($type['body_label']) ? $type['body_label'] : t('Body')
      );
      $fieldset['table']['body']['type'] = array('#value' => t('text'));
      $fieldset['table']['body']['process'] = array(
        '#type' => 'checkbox',
        '#title' => '',
        '#default_value' => in_array('body', $fields)
      );
    }
    // CCK fields
    if (isset($type['fields'])) {
      // Handle fields in fieldgroups
      if (module_exists('fieldgroup')) {
        $group_prefix = array();
        $groups = fieldgroup_groups($type['type']);
        foreach ($groups as $group) {
          foreach ($group['fields'] as $field => $field_info) {
            $group_prefix[$field] = $field_info['group_name'];
          }
        }
      }
      foreach ($type['fields'] as $field => $field_info) {
        if (isset($group_prefix[$field])) {
          $field = $group_prefix[$field] .'/'. $field;
        }
        $fieldset['table'][$field]['label'] = array('#value' => $field_info['widget']['label']);
        if ($field_info['type'] == $field_info['widget']['type']) {
          $fieldset['table'][$field]['type'] = array('#value' => $field_info['type']);
        }
        else {
          $fieldset['table'][$field]['type'] = array(
            '#value' => $field_info['type'] .' / '. $field_info['widget']['type']
          );
        }
        $fieldset['table'][$field]['process'] = array(
          '#type' => 'checkbox',
          '#title' => '',
          '#default_value' => ($field_info['type'] != 'text') ? FALSE : in_array($field, $fields),
          '#disabled' => ($field_info['type'] != 'text') ? TRUE : FALSE
        );
      }
    }
    $form['content'][$type['type']] = $fieldset;
  }
  
  return _reptag_admin_form($form, '_reptag_admin_content');
}

/**
 * Function _reptag_admin_content_save().
 */
function _reptag_admin_content_save($form, &$form_state) {
  // Save fields configuration
  foreach ($form_state['values']['content'] as $type => $fields) {
    $enabled = array();
    foreach ($fields as $field => $value) {
      if ($value['process']) {
        $enabled[] = $field;
      }
    }
    variable_set('reptag_type_'. $type .'_fields', serialize($enabled));
  }
  
  drupal_set_message(t('The configuration options have been saved.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_content_reset().
 */
function _reptag_admin_content_reset($form, &$form_state) {
  // Reset fields configuration
  foreach ($form_state['values']['content'] as $type => $fields) {
    variable_set('reptag_type_'. $type .'_fields', serialize(array('content/body/#value')));
  }

  drupal_set_message(t('The configuration has been reset to defaults.'));
  _reptag_cache_clear(t('The cache has been flushed to reflect the new configuration.'));
}

/**
 * Function _reptag_admin_form().
 * (add hidden fields for ajax support and default buttons) 
 */
function _reptag_admin_form($form, $base = NULL) {
  // Include JS (if configured)
  if (variable_get('reptag_javascript', 1)) {
    $settings = array(
      'callback'      => base_path() .'index.php?q=admin/settings/reptag/ajax/',
      'images'        => base_path() . drupal_get_path('module', 'reptag') .'/images/',
      'htmlLoad'      => theme('reptag_dialog'),
      'multilingual'  => variable_get('reptag_locale_enable', 0) && (variable_get('language_count', 1) >= 2)
    );
    drupal_add_js(array('reptag' => $settings), 'setting');
    drupal_add_js(drupal_get_path('module', 'reptag') .'/js/reptag.js');
  }
  // Include CSS
  drupal_add_css(drupal_get_path('module', 'reptag') .'/css/reptag.css');
  
  // Default buttons
  if (isset($base)) {
    $form['buttons']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
      '#submit' => array($base .'_save')
    );
    $form['buttons']['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Reset to defaults'),
      '#submit' => array($base .'_reset')
    );
  }
  
  return $form;
}

/**
 * Function theme_reptag_table().
 */
function theme_reptag_table($form) {
  $rows = array();
  $header = isset($form['#header']) ? $form['#header'] : array();
  $attributes = isset($form['#attributes']) ? $form['#attributes'] : array();
  $tabledrag = isset($form['#tabledrag']) ? $form['#tabledrag'] : FALSE;
  
  if ($tabledrag && isset($attributes['id'])) {
    drupal_add_tabledrag($attributes['id'], 'order', 'sibling', $attributes['id'] .'-'. $tabledrag);
  }
  
  if (isset($attributes['description'])) {
    $rows[] = array(array('data' => $attributes['description'], 'colspan' => count($header), 'class' => 'message'));
    unset($attributes['description']);
  }
  
  foreach (element_children($form) as $key) {
    $row = array();
    foreach (element_children($form[$key]) as $item) {
      if ($tabledrag && $tabledrag == $item) {
        $form[$key][$item]['#attributes'] = array('class' => $attributes['id'] .'-'. $tabledrag);
      }
      $row[] = drupal_render($form[$key][$item]);
    }
    $rows[] = $tabledrag ? array('data' => $row, 'class' => 'draggable') : $row;
  }

  if (empty($rows)) {
    $message = check_plain(isset($form['#empty']) ? $form['#empty'] : t('There are no items in the table.'));
    $rows[] = array(array('data' => $message, 'colspan' => count($header), 'align' => 'center', 'class' => 'message'));
  }
  
  return count($rows) ? theme('table', $header, $rows, $attributes) : '';
}
