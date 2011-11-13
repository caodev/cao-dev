<?php
// $Id: node.tags.inc,v 1.2.2.3 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Node content and data display tags
 */

define('REPTAG_NODE_LEVELS', 10);

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_node_init($node) {
  return array(
  
    "#{NID}#"               => $node->nid,
    "#{VID}#"               => $node->vid,
    "#{VNAME}#"             => _reptag_node_get_vname($node->vid),
    "#{CREATED}#"           => format_date($node->created, 'small'),
    "#{CHANGED}#"           => format_date($node->changed, 'small'),
    "#{REVISION}#"          => format_date($node->revision_timestamp, 'small'),
    "#{TITLE}#"             => $node->title,
    "#{AUTHOR}#"            => $node->name,
    "#{NODE:([0-9]+)}#e"    => "_reptag_node_embed(\\1);",
    "#{NODE:(.+?)}#e"       => "_reptag_node_embed_by_title('\\1');"
    
  );
}

function _reptag_node_info() {
  return array(t('Node Info (NID, CREATED, AUTHOR, ...)'), TRUE);
}

function _reptag_node_help() {
  return array(
  
    "{NID}"                     => "73",
    "{VID}"                     => "2",
    "{VNAME}"                   => "vocabulary of current node",
    "{CREATED}"                 => format_date('1130530021', 'small'),
    "{CHANGED}"                 => format_date('1140040286', 'small'),
    "{REVISION}"                => format_date('1140040286', 'small'),
    "{TITLE}"                   => "title of current node",
    "{AUTHOR}"                  => "author of current node",
    "{NODE:1}"                  => "embed node by nid",
    "{NODE:Node Title}"         => "embed node by title"
  
  );
}

function _reptag_node_theme() {
  return array(
    'reptag_node_embed' => array(
      'file' => 'node.tags.inc',
      'path' => drupal_get_path('module', 'reptag') .'/tags',
      'arguments' => array('node' => NULL)
    )
  );
}

function _reptag_node_get_vname($vid) {
  $result = db_query("SELECT name FROM {vocabulary} WHERE vid = '%d'", $vid);
  $var = db_fetch_object($result);
  
  return isset($var->name) ? check_plain($var->name) : '';
}

function _reptag_node_embed_by_title($title) {
  $result = db_query(db_rewrite_sql("SELECT n.nid FROM {node} n WHERE LOWER(title) = LOWER('%s')"), trim($title));
  if ($node = db_fetch_object($result)) {
    return _reptag_node_embed($node->nid);
  }

  return '';
}

function _reptag_node_embed($nid) {
  static $level = 0;

  // Allow recursive inclusion of REPTAG_NODE_LEVELS levels
  if ($level++ >= REPTAG_NODE_LEVELS) {
    return '';
  }
  
  if ($nid && $node = node_load($nid)) {
    if (node_access('view', $node)) {
      $node = node_build_content($node, FALSE, TRUE);
      $node->body = drupal_render($node->content);
      // Allow modules to modify the fully-built node.
      node_invoke_nodeapi($node, 'alter', FALSE, TRUE);

      return theme('reptag_node_embed', $node);
    }
  }

  return '';
}

function theme_reptag_node_embed($node) {
  $output  = '<div class="node-embedded">';
  $output .= '<h2 class="title">'. check_plain($node->title) .'</h2>';
  $output .= $node->body;
  $output .= '</div>';
  
  return $output;
}
