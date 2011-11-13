<?php
// $Id: block.tags.inc,v 1.2.2.4 2009/05/20 02:58:00 dman Exp $

/**
 * @file
 * block.tags written by dman (user/33240)
 * Allows inline blocks through a BBcode-like syntax
 * Things will display nicely if you add some CSS to support them such as:
 */

/*
  <style>
  .node .content .block {
    width:200px;
    float:right;
    margin:1em;
    padding:1em;
    border:1px solid gray;
  }
  </style>
*/

function _reptag_block_init($context) {
  return array(
  
    "#{BLOCK:([0-9]+)}#e"          => "theme('block', (object)module_invoke('block', 'block', 'view', '\\1'));",
    "#{BLOCK:(.*?):([0-9]+)}#e"    => "theme('block', (object)module_invoke('\\1', 'block', 'view', '\\2'));",
    "#{BLOCK:(.*?):(.+?)}#e"       => "theme('block', (object)_reptag_block_by_subject('\\2','\\1'));",
    "#{BLOCK:(.+?)}#e"             => "theme('block', (object)_reptag_block_by_subject('\\1'));"
    
  );
}

function _reptag_block_info() {
  return array(t('Inline Blocks ({BLOCK:1}, {BLOCK:menu:2} ...)'), FALSE);
}

function _reptag_block_help() {
  return array(
  
    "{BLOCK:1}"                   => "User-defined block 1",
    "{BLOCK:Contact Details}"     => "User-defined block with the given title",
    "{BLOCK:menu:2}"              => "Block 2 supplied by the given module",
    "{BLOCK:image:Random image}"  => "Named block from the given module"
    
  );
}

/**
 * Note that getting block by subject is inefficient.
 * For speed you should always use block by ID.
 * This is easier now that block deltas are strings.
 * 
 * views_block('list') is not idempotent -  it rebuilds its list of available
 * blocks, re-caches etc every single time we ask it to 'list'! This can trigger
 * hundreds of trival DB extras.
 *
 */
function _reptag_block_by_subject($subject, $module = 'block') {
  // Assume we are given the block delta, and can call it directly
  if ($result = module_invoke($module, 'block', 'view', $subject) ) {
    // Need to ensure a block invoked by name knows its own delta
    // so that theming can catch valid IDs later
    $result['module'] = $module;
    $result['delta'] = $subject;
    return $result;
  }
  // Otherwise need to scan for string title matches. 
  $list = module_invoke($module, 'block', 'list');
  foreach ($list as $key => $block) {
    // Search by either admin block label or blocks display label
    if (stristr($block['info'], $subject)) {
      return module_invoke($module, 'block', 'view', $key);
    }
    $block = module_invoke($module, 'block', 'view', $key);
    if (stristr($key, $subject)) {
      return $block;
    }
    if (stristr($block['subject'], $subject)) {
      return $block;
    }
  }
}

/**
 * Call this to add the basic CSS to the page
 */
function _reptag_block_add_css() {
  static $done;
  if (!$done) {
    drupal_set_html_head("
      <style>
      .node .content .block{
        width:200px;
        float:right;
        margin:1em;
        padding:1em;
        border:1px solid gray;
      }
      </style>
    ");
  }
  
  $done = TRUE;
}
