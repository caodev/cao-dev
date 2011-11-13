<?php
// $Id: reptag_module.inc,v 1.2.2.3 2009/04/23 03:51:07 dman Exp $

/**
 * @file
 * Helper functions for the reptag module
 */

define('REPTAG_PROCALL',      0);
define('REPTAG_PROCSTATIC',   1);
define('REPTAG_PROCDYNAMIC',  2);

/**
 * Function _reptag_module_list().
 * (return a list of available modules)
 */
function _reptag_module_list($rebuild = FALSE, $enabled = FALSE, $proc = REPTAG_PROCALL, $modules = NULL) {
  static $reptag_modules = array();
  // dman 2009-04- this is being called several dozen times. cache it 
  if(!empty($reptag_modules) && ! $rebuild) {
    return $reptag_modules;
  }
  // build query and fetch modules
  $query = $rebuild ? 'SELECT module, enabled, weight, roles FROM {reptag_registry}' : 'SELECT * FROM {reptag_registry}';
  if ($enabled) {
    $query .= ' WHERE enabled = 1';
  }
  switch ($proc) {
    case REPTAG_PROCSTATIC:
      $query .= $enabled ? ' AND' : ' WHERE';
      $query .= ' static = 1';
      break;
    case REPTAG_PROCDYNAMIC:
      $query .= $enabled ? ' AND' : ' WHERE';
      $query .= ' static = 0';
      break;
    default:
  }
  $query .= ' ORDER BY weight ASC, module ASC';
  $result = db_query($query);
  while ($module = db_fetch_array($result)) {
    if (!$modules || in_array($module['module'], $modules)) {
      $reptag_modules[$module['module']] = $module;
      $reptag_modules[$module['module']]['roles'] = unserialize($module['roles']);
    }
  }
  
  // rebuild module registry
  if ($rebuild && !$enabled) {
    $modules_rebuild = _reptag_module_rebuild();
    $reptag_modules = _reptag_array_intersect_key($reptag_modules, $modules_rebuild);
    $reptag_modules = _reptag_array_merge_key($modules_rebuild, $reptag_modules);
    _reptag_module_register($reptag_modules, TRUE);
    uasort($reptag_modules, '_reptag_module_cmp');
  }

  return $reptag_modules;
}

/**
 * Function _reptag_module_cmp().
 * (sort modules by weigth and name)
 */
function _reptag_module_cmp($a, $b) {
  if ($a['weight'] == $b['weight']) {
    return ($a['module'] == $b['module']) ? 0 : (($a['module'] < $b['module']) ? -1 : 1);
  }
  return ($a['weight'] < $b['weight']) ? -1 : 1;
}

/**
 * Function _reptag_module_rebuild().
 * (rebuild the modules list)
 */
function _reptag_module_rebuild() {
  $reptag_modules = array();
  // module (.tags)
  $files = file_scan_directory(drupal_get_path('module', 'reptag'), '\.tags.inc$');
  foreach ($files as $file) {
    include_once($file->filename);
    $module = substr($file->name, 0, -5);
    $function = '_reptag_'. $module .'_info';
    if (function_exists($function)) {
      $reptag_info = $function();
      $reptag_modules[$file->name] = array(
        'module' => $module,
        'path' => $file->filename,
        'static' => is_array($reptag_info) ? $reptag_info[1] : FALSE,
        'description' => check_plain(is_array($reptag_info) ? $reptag_info[0] : $reptag_info),
        'enabled' => FALSE,
        'weight' => 0,
        'roles' => array()
      );
    }
  }
  // other modules (hook_reptag)
  $modules = module_implements('reptag');
  foreach ($modules as $module) {
    $reptag_info = module_invoke($module, 'reptag', 'info');
    $reptag_modules[$module] = array(
      'module' => $module,
      'path' => '',
      'static' => is_array($reptag_info) ? $reptag_info[1] : TRUE,
      'description' => check_plain(is_array($reptag_info) ? $reptag_info[0] : $reptag_info),
      'enabled' => FALSE,
      'weight' => 0,
      'roles' => array()
    );
  }
  
  return $reptag_modules;
}

/**
 * Function _reptag_module_register().
 * (register a module / update a module's registry)
 */
function _reptag_module_register($modules, $reset = FALSE) {
  if ($reset) {
    db_query('DELETE FROM {reptag_registry}');
  }
  foreach ($modules as $module => $details) {
    $details['module'] = $module;
    $details['roles'] = serialize($details['roles']);
    if ($reset) {
      drupal_write_record('reptag_registry', $details);
    }
    else {
      drupal_write_record('reptag_registry', $details, 'module');
    }
  }
}

/**
 * Function _reptag_module_reset().
 */
function _reptag_module_reset() {
  _reptag_module_register(_reptag_module_rebuild(), TRUE);
}

/**
 * Function _reptag_module_invoke().
 */
function _reptag_module_invoke() {
  static $modules = array();
  
  $args = func_get_args();
  $module = array_shift($args);
  $hook = array_shift($args);
  
  if (!is_array($module)) {
    $module = array(
      'module' => $module,
      'path' => $modules[$module],
    );
  }
  else {
    // include the .tags file once
    if ($module['path'] && !isset($modules[$module['module']])) {
      include_once($module['path']);
    }
    // cache the path
    $modules[$module['module']] = $module['path'];
  }
  
  // call the module hook
  if (empty($module['path'])) {
    if ($hook != 'process') {
      array_unshift($args, $hook);
    }
    $function = ($hook == 'process') ? 'reptag_process' : 'reptag';
    if (module_hook($module['module'], $function)) {
      return call_user_func_array($module['module'] .'_'. $function, $args);
    }
  }
  else {
    $function = '_reptag_'. substr($module['module'], 0, -5) .'_'. $hook;
    if (function_exists($function)) {
      return call_user_func_array($function, $args);
    }
  }
  
  return FALSE;
}

/**
 * Function _reptag_module_require().
 */
function _reptag_module_require($module) {
  if (!empty($module['path'])) {
    include_once($module['path']);
  }
  
  $require_func = '_reptag_'. substr($module['module'], 0, -5) .'_require';
  if (function_exists($require_func)) {
    return $require_func();
  }
  
  return TRUE;
}

/**
 * Function _reptag_module_access().
 * (filter modules by permissions/roles)
 */
function _reptag_module_access($modules, $roles = NULL) {
  global $user;
  # dman 2009-04 - $user object already knows its roles 
  #if (!$roles) {
  #  $roles = _reptag_user_get_roles($user->uid);
  #}
  $roles = array_keys($user->roles);

  foreach ($modules as $module => $details) {
    if (!(array_intersect($details['roles'], $roles) || $user->uid == 1)) {
      unset($modules[$module]);
    }
  }
  
  return $modules;
}

/**
 * Function _reptag_module_tags().
 * (fetch all available tags)
 */
function _reptag_module_tags($proc = REPTAG_PROCALL, $roles = NULL, $content = NULL, $modules = NULL) {
  $module_tags = array();
  
  $modules = _reptag_module_list(FALSE, TRUE, $proc, $modules);
  $modules = _reptag_module_access($modules, $roles);
  foreach ($modules as $module => $details) {
    $module_tags[$module] = _reptag_module_invoke($details, 'init', $content);
  }
  
  return array_filter($module_tags);
}

/**
 * Function _reptag_module_help().
 */
function _reptag_module_help($roles = NULL, $modules = NULL) {
  $helptags = array();
  
  $modules = _reptag_module_list(FALSE, TRUE, REPTAG_PROCALL, $modules);
  $modules = _reptag_module_access($modules, $roles);
  foreach ($modules as $module => $details) {
    $helptags[$module] = _reptag_module_invoke($details, 'help');
  }
  
  return array_filter($helptags);
}
