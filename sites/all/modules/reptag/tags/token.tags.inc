<?php
// $Id: token.tags.inc,v 1.1.2.1 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * User-defined Token tags
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_token_init($context) {
  return array('');
}

function _reptag_token_info() {
  return array(t('Token (Integration of the Token module)'), FALSE);
}

function _reptag_token_help() {
  return theme_token_help('node');
}

function _reptag_token_require() {
  return module_exists('token');  
}

function _reptag_token_process($text, $tags, $context) {  
  return token_replace($text, 'node', $context);
}
