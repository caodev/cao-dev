<?php
// $Id: reptag_process.inc,v 1.26.2.8 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Processing functions for the reptag module. Find, choose, include and execute
 * the appropriate callbacks.
 */

require_once(drupal_get_path('module', 'reptag') .'/reptag_helper.inc');
require_once(drupal_get_path('module', 'reptag') .'/reptag_module.inc');

/**
 * Simple (wrapper) function for text replacements
 * (You can use reptag_replace() to process a piece of text instead
 *  of calling reptag_process() directly)
 *
 * @param $text
 *   The text/content to be processed.
 * @param $procall
 *   By default only static tags are replaced using reptag_replace(),
 *   set $procall = TRUE to use all tags (static + dynamic) instead. 
 */
function reptag_replace($text, $procall = FALSE) {
  global $user;
  
  $content = new stdClass();
  $content->uid = $user->uid;
  $content->text = $text;
  reptag_process($content, array('text'), $procall ? REPTAG_PROCALL : REPTAG_PROCSTATIC);
  
  return $content->text;
}

/**
 * Simple (wrapper) function for replacements in object fields
 * (You can use reptag_field_replace() to process a field of an object
 *  instead of calling reptag_process() directly)
 *
 * @param $content
 *   The object containing the field and optional context.
 * @param $field
 *   The name of the field in $content to be processed.
 * @param $procall
 *   By default only static tags are replaced using reptag_field_replace(),
 *   set $procall = TRUE to use all tags (static + dynamic) instead.
 *
 * Example:
 *   If you want to process a field of the node object in a template of your
 *   theme, the use of this function is pretty convenient.
 *     <?php print reptag_field_replace($node, 'myfield'); ?>
 */
function reptag_field_replace($content, $field, $procall = FALSE) {
  global $user;

  $content->uid = isset($content->uid) ? $content->uid : $user->uid;
  reptag_process($content, array($field), $procall ? REPTAG_PROCALL : REPTAG_PROCSTATIC);

  return $content->$field;
}

/**
 * Perform the actual reptag processing
 * (This function does all the filter/replacement stuff)
 *
 * @param $content
 *   An object containing the content (and its context) to be processed.    
 * @param $fields
 *   An array containing all fields (or field pathes) of $content to be processed
 *    e.g. 'fieldA' for $content->fieldA
 *         'fieldA/fieldB' for $content->fieldA->fieldB
 *         'fieldA/fieldB/fieldC' for $content->fieldA->fieldB-fieldC etc.
 *         (this also works when $content is not an object but an array) 
 * @param $proc
 *   An integer to set the processing mode (e.g. REPTAG_PROCALL, ...).
 * @param $modules
 *   An array containing the names of all modules to be used
 *    e.g. array('system.tags', 'node.tags')
 * @param $lang
 *   The language code (e.g. 'de') of the replacements to use.
 *   Omit this parameter to use the language of the current page request (auto-negotiate)
 *
 *   See DEVELOPER.TXT for detailed information  
 */
function reptag_process(&$content, $fields = array('text'), $proc = REPTAG_PROCALL, $modules = NULL, $lang = NULL) {
  // Return immediately on empty $fields array
  if (empty($fields)) {
    return;
  }
  
  // Set default user if no uid is provided
  if (!isset($content->uid)) {
    $content->uid = 0; // anonymous user
  }
  
  // Get roles associated with current node
  $content_roles = _reptag_user_get_roles($content->uid);
  
  // Load module tags
  $reptags = _reptag_module_tags($proc, $content_roles, $content, $modules);
  if ($proc == REPTAG_PROCDYNAMIC && empty($reptags)) {
    return;
  }
  
  // Load exclude tags
  $exclude_tags = array();
  foreach ($content_roles as $rid) {
    $rid_tags = _reptag_exclude_loadtags($rid);
    $exclude_tags = array_filter(array_merge($exclude_tags, $rid_tags));
  }
  
  // Filter exclude_tags from reptags
  $reptags = _reptag_filter_exclude($reptags, $exclude_tags);
  
  // Load side-wide and user tags from tables
  if ($proc != REPTAG_PROCDYNAMIC) {

    $iid = array(0, $content->uid);
    if (!isset($lang) && variable_get('reptag_locale_binding', 0) && isset($content->language)) {
      $lang = $content->language;
    }
    $reptag_table = _reptag_table_load($iid, REPTAG_LOADTAG_DEFAULT, $lang);
    
    // Load tags of default language and merge in
    if (variable_get('reptag_locale_enable', 0)
      && (variable_get('reptag_locale_mode', REPTAG_LOCALE_STRICT) == REPTAG_LOCALE_FALLBACK)
      && (_reptag_language() != language_default('language'))) {
      $default_tags = _reptag_table_load($iid, REPTAG_LOADTAG_DEFAULT, language_default('language'));
      $reptag_table = array_merge($default_tags, $reptag_table);
    }
    
    // Remove all html tags for plain text roles
    $plainrep_roles = unserialize(variable_get('reptag_plainrep_roles', serialize(array())));
    if (array_intersect($plainrep_roles, $content_roles)) {
      foreach ($reptag_table as $tag => $repl) {
        $reptag_table[$tag] = check_plain(strip_tags($repl));
      }
    }
    
    // Filter exclude_tags from reptag_table
    foreach ($exclude_tags as $key) {
      $key = '#\\'. strtoupper(substr($key, 0, -1)) .'\$#si'; 
      unset($reptag_table[$key]);
    }
    
    // Prepare regexp for parametric tags
    if (variable_get('reptag_parametric', 0)) {
      _reptag_parametric_prepare($reptag_table);
    }
    
  }
  
  // Debug
  if (variable_get('reptag_debug', 0)) {
    _reptag_debug($fields, 'Fields');
    _reptag_debug($reptags, 'Module RepTags');
    _reptag_debug($reptag_table, 'Table RepTags');
    _reptag_debug($content, 'Content');
  }
  
  // Iterate over all $fields
  foreach ($fields as $field) {

    // Point to the text/string to be processed
    $text =& _reptag_content_field($content, $field);
    // Only continue with a valid (non-empty) string
    if (!is_string($text) || empty($text)) {
      continue;
    }
    
    // Process table tags
    if ($proc != REPTAG_PROCDYNAMIC) {
      $text = preg_replace(array_keys($reptag_table), array_values($reptag_table), $text);
    }
    
    // Process module tags
    foreach ($reptags as $module => $tags) {
      $result = _reptag_module_invoke($module, 'process', $text, $tags, $content);
      $text = $result ? $result : preg_replace(array_keys($tags), array_values($tags), $text);
    }
    
  }
}

/**
 * Function _reptag_parametric_prepare().
 */
function _reptag_parametric_prepare(&$tags) {
  $parametric_tags = array();
  foreach ($tags as $tag => $replacement) {
    $matches = array();
    if (preg_match('/\\\\\$([^{]+){([^}]+)}\\\\\$/', $tag, $matches)) {
      $args = preg_split('/[,]/', $matches[2]);
      $num_args = count($args);
      foreach ($args as $idx => $arg) {
        $search = '/%'. trim($arg) .'/i';
        $replace = '\\\\'. (string)($idx + 1) .'\\\\'. (string)($num_args + $idx + 1);
        $replacement = preg_replace($search, $replace, $replacement);
      }
      $args_fill[0] = implode('[\s]*,[\s]*', array_fill(0, $num_args, '\'(.*)\''));
      $args_fill[1] = implode('[\s]*,[\s]*', array_fill(0, $num_args, '(.*)'));
      $parametric_tags['/\$'. $matches[1] .'{(?(?=\')'. $args_fill[0] .'|'. $args_fill[1] .')}\$/i'] = $replacement;
      unset($tags[$tag]);
    }
  }
  $tags = array_merge($tags, $parametric_tags);
}

/**
 * Function _reptag_filter_exclude().
 */
function _reptag_filter_exclude($reptags, $exclude_tags) {
  foreach ($reptags as $module => $tags) {
    $matches = array_intersect(array_keys($tags), array_values($exclude_tags));
    foreach ($matches as $key) {
      unset($reptags[$module][$key]);
    }
  }
  
  return $reptags; 
}
