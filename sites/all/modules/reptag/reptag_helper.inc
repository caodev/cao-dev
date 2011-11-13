<?php
// $Id: reptag_helper.inc,v 1.2.2.4 2009/04/23 03:51:07 dman Exp $

/**
 * @file
 * Database routines for managing tag lists
 */

define('REPTAG_LOADTAG_DEFAULT',  0);
define('REPTAG_LOADTAG_FORMAT',   1);
define('REPTAG_LOADTAG_EDIT',     2);

/**
 * Function _reptag_language().
 * (get language for the current page request)
 */
function _reptag_language($lang = NULL) {
  global $language;
  return isset($lang) ? $lang : (variable_get('reptag_locale_enable', 0) ? $language->language : language_default('language'));
}

/**
 * Function _reptag_rtid2uid().
 */
function _reptag_rtid2uid($rtid) {
  return db_result(db_query('SELECT uid FROM {reptag_vars} WHERE rtid = %d', $rtid));
}

/**
 * Function _reptag_table_load_tag().
 * (load tags from table)
 */
function _reptag_table_load_tag($rtid, $cleanlevel = REPTAG_LOADTAG_DEFAULT) {
  // Load and format tags
  $reptag = db_fetch_array(db_query('SELECT name, uid FROM {reptag_vars} WHERE rtid = %d', $rtid));
  $result = db_query('SELECT rtid, name, value, language FROM {reptag_vars} WHERE name = \'%s\' AND uid = %d', $reptag['name'], $reptag['uid']);
  while ($var = db_fetch_object($result)) {
    switch ($cleanlevel) {
      case REPTAG_LOADTAG_FORMAT:
        $reptag['tag'] = '$'. substr($var->name, 3, -5) .'$';
        break;
      case REPTAG_LOADTAG_EDIT:
        $reptag['tag'] = substr($var->name, 3, -5);
        break;
      case REPTAG_LOADTAG_DEFAULT:
      default:
        $reptag['tag'] = $var->name;
    }
    $reptag['replacements'][$var->language] = array(
      'rtid' => $var->rtid,
      'replacement' => $var->value
    );
  }
  
  return count($reptag) ? $reptag : NULL;
}

/**
 * Function _reptag_table_load().
 * (load tags from table)
 */
function _reptag_table_load($iid, $cleanlevel = REPTAG_LOADTAG_DEFAULT, $lang = NULL, $limit = NULL) {
  // Build query
  $query = 'SELECT rtid, name, value FROM {reptag_vars} WHERE (uid = '. intval($iid[0]);
  for ($i = 1; $i < count($iid); $i++) {
    $query .= ' OR uid = '. intval($iid[$i]);
  }
  $query .= ') AND language = \''. _reptag_language($lang) .'\'';
  $query .= variable_get('reptag_tableprio', 0) ? ' ORDER BY uid ASC' : ' ORDER BY uid DESC';
  // Load and format tags
  $vars = array();
  $result = isset($limit) ? pager_query($query, $limit) : db_query($query);
  while ($var = db_fetch_object($result)) {
    switch ($cleanlevel) {
      case REPTAG_LOADTAG_FORMAT:
        $vars['$'. substr($var->name, 3, -5) .'$'] = $var->value;
        break;
      case REPTAG_LOADTAG_EDIT:
        $vars[$var->rtid] = array('tag' => substr($var->name, 3, -5), 'replacement' => $var->value);
        break;
      case REPTAG_LOADTAG_DEFAULT:
      default:
        $vars[$var->name] = $var->value;
    }
  }
  
  return $vars;
}

/**
 * Function _reptag_table_add().
 */
function _reptag_table_add($name, $value, $uid, $lang = NULL) {
  $item = array(
     'name' => $name,
     'value' => $value,
     'uid' => $uid,
     'language' => _reptag_language($lang)
  );
  drupal_write_record('reptag_vars', $item);
}

/**
 * Function _reptag_table_update().
 */
function _reptag_table_update($rtid, $name, $value, $uid, $lang = NULL) {
  $item = array(
     'rtid' => $rtid,
     'name' => $name,
     'value' => $value,
     'uid' => $uid,
     'language' => _reptag_language($lang)
  );
  drupal_write_record('reptag_vars', $item, 'rtid');
}

/**
 * Function _reptag_table_del_name().
 */
function _reptag_table_del_name($name, $uid, $lang = NULL, $all = FALSE) {
  $query  = 'DELETE FROM {reptag_vars} WHERE name = \'%s\' AND uid = %d';
  if (!isset($lang) && !$all) {
    $lang = _reptag_language();
  }
  $query .= isset($lang) ? (' AND language = \''. $lang .'\'') : '';
  db_lock_table('reptag_vars');
  db_query($query, $name, $uid);
  db_unlock_tables();
}

/**
 * Function _reptag_table_del().
 */
function _reptag_table_del($rtid) {
  db_lock_table('reptag_vars');
  db_query('DELETE FROM {reptag_vars} WHERE rtid = %d', $rtid);
  db_unlock_tables();
}

/**
 * Function _reptag_table_clear().
 * (remove all tags for a specified user)
 */
function _reptag_table_clear($uid) {
  $query = 'DELETE FROM {reptag_vars} WHERE uid = %d';
  db_lock_table('reptag_vars');
  db_query($query, $uid);
  db_unlock_tables();
}

/**
 * Function _reptag_tags_implode().
 */
function _reptag_tags_implode($tags) {
  $tags = array_filter($tags);
  $tags = implode('|', $tags);
  return $tags;
}

/**
 * Function _reptag_exclude_loadtags().
 * (load exclude tags from variable)
 */
function _reptag_exclude_loadtags($rid) {
  $tags = unserialize(variable_get('reptag_exclude_r'. $rid, serialize(array())));
  return $tags;
}

/**
 * Function _reptag_exclude_loadtags_string().
 * (load exclude tags from variable into a string)
 */
function _reptag_exclude_loadtags_string($rid) {
  $tags = _reptag_exclude_loadtags($rid);
  $tags = _reptag_tags_implode($tags);
  return $tags;
}

/**
 * Function _reptag_exclude_storetags().
 * (store exclude tags to variable)
 */
function _reptag_exclude_storetags($rid, $tags) {
  variable_set('reptag_exclude_r'. $rid, serialize($tags));
}

/**
 * Function _reptag_exclude_storetags_string().
 * (explode string and store exclude tags to variable)
 */
function _reptag_exclude_storetags_string($rid, $tags) {
  $tags = explode('|', $tags);
  _reptag_exclude_storetags($rid, $tags);
}

/**
 * Function _reptag_user_get_roles().
 * (get roles for a specified user)
 */
function _reptag_user_get_roles($uid) {
  # dman 2009-04 - added minor caching
  static $user_roles = array();
  if(isset($user_roles[$uid])) {
    return $user_roles[$uid];
  }

  $roles = array();
  switch ($uid) {
    case 0: // anonymous user
      $roles[] = DRUPAL_ANONYMOUS_RID;
      break;
    case 1: // administrator
      $roles[] = DRUPAL_AUTHENTICATED_RID;
      $result = db_query('SELECT DISTINCT rid FROM {users_roles}');
      while ($rid = db_fetch_object($result)) {
        $roles[] = $rid->rid;
      }
      break;
    default: // authenticated user
      $roles[] = DRUPAL_AUTHENTICATED_RID;
      $result = db_query('SELECT rid FROM {users_roles} WHERE uid = %d', $uid);
      while ($rid = db_fetch_object($result)) {
        $roles[] = $rid->rid;
      }
  }

  $user_roles[$uid] = $roles;
  return $roles;
}

/**
 * Function _reptag_cache_cid().
 * (calculate the cache identifier)
 */
function _reptag_cache_cid($node, $fields, $teaser) {
  return 'n'. $node->nid . ($teaser ? 't:' : ':') .
    (isset($node->vid) ? 'v'. $node->vid : 'c'. $node->cid) .':'. md5(serialize($fields)) .':'. _reptag_language();
}

/**
 * Function _reptag_cache_set().
 * (store node into reptag cache)
 */
function _reptag_cache_set($node, $fields, $teaser = FALSE) {
  $cache = array();
  foreach ($fields as $field) {
    $cache[$field] = _reptag_content_field($node, $field);
  }
  if (count($cache)) {
    $cid = _reptag_cache_cid($node, $fields, $teaser);
    cache_set($cid, $cache, 'cache_reptag', variable_get('reptag_cache_lifetime', CACHE_PERMANENT));
  }
}

/**
 * Function _reptag_cache_get().
 * (retrieve a node from reptag cache)
 */
function _reptag_cache_get($node, $fields, $teaser = FALSE) {
  $cid = _reptag_cache_cid($node, $fields, $teaser);
  if ($cache = cache_get($cid, 'cache_reptag')) {
    // Does cache contain valid data?
    if (empty($cache->data)) {
      return FALSE;
    }
    // Unserialize data and override fields
    $cache = $cache->data;
    foreach ($fields as $field) {
      if (isset($cache[$field])) {
        $field_content = &_reptag_content_field($node, $field);
        $field_content = $cache[$field];
      }
    }
    return TRUE;
  }

  return FALSE;
}

/**
 * Function _reptag_cache_del().
 * (remove a node from reptag cache)
 */
function _reptag_cache_del($node, $fields) {
  $node = (object)$node;
  $cid = _reptag_cache_cid($node, $fields, TRUE);
  cache_set($cid, '', 'cache_reptag', CACHE_TEMPORARY);
  $cid = _reptag_cache_cid($node, $fields, FALSE);
  cache_set($cid, '', 'cache_reptag', CACHE_TEMPORARY);
}

/**
 * Function _reptag_cache_clear().
 */
function _reptag_cache_clear($msg = NULL) {
  if (variable_get('reptag_cache', 0)) {
    cache_clear_all('*', 'cache_reptag', TRUE);
    drupal_set_message(isset($msg) ? $msg : t('The cache has been flushed.'));
  }
}

/**
 * Function _reptag_match_tags().
 * (filter $tags containing $string)
 */
function _reptag_match_tags($string, $tags) {
  $matches = array();
  foreach ($tags as $tag) {
    if (!(strpos($tag, $string) === FALSE)) {
      $matches[$tag] = check_plain($tag);
    }
  }

  return $matches;
}

/**
 * Function _reptag_content_field().
 * (point $text to the $field path of $content)
 */
function &_reptag_content_field(&$content, $field) {
  $text = &$content;
  $elements = explode('/', $field);
  foreach ($elements as $element) {
    if (is_array($text)) {
      $text = &$text[$element];
    }
    elseif (is_object($text)) {
      $text = &$text->$element;
    }
    else {
      $text = NULL;
    }
  }

  return $text;
}

/**
 * Function _reptag_debug().
 */
function _reptag_debug($output, $label = NULL, $html = FALSE) {
  if (variable_get('reptag_debug', 0) && user_access('administer site configuration')) {
    // Output debug log into a collapsible fieldset
    $fieldset = array(
      '#title' => t('Rep[lacement]Tags Debug') . (isset($label) ? (': '. check_plain($label)) : ''),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#value' => '<pre>'. ($html ? $output : htmlspecialchars(print_r($output, TRUE))) .'</pre>',
    );
    drupal_set_content('content', theme('fieldset', $fieldset));
  }
}

/**
 * Function _reptag_array_intersect_key().
 * (PHP4+5 array_intersect_key()-like replacement)
 */
function _reptag_array_intersect_key($a, $b) {
   foreach (array_keys($a) as $key) {
      if (!isset($b[$key])) {
        unset($a[$key]);
      }
   }

   return $a;
}

/**
 * Function _reptag_array_merge_key().
 * (PHP4+5 array_merge_key()-like replacement)
 */
function _reptag_array_merge_key($a, $b) {
  foreach ($b as $key => $value) {
    if (is_array($value)) {
      $a[$key] = _reptag_array_merge_key($a[$key], $value);
    }
    else {
      $a[$key] = $value;
    }
  }

  return $a;
}
