<?php
// $Id: format.tags.inc,v 1.2.2.1 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Markup and formatting tags
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_format_init($context) {
  return array(
  
      "#{H([1-4])}(.*?){/H[1-4]}#s"       => "<h\\1>\\2</h\\1>",
      
      "#{B}(.*?){/B}#s"                   => "<strong>\\1</strong>",
      "#{I}(.*?){/I}#s"                   => "<i>\\1</i>",
      "#{U}(.*?){/U}#s"                   => "<span style='text-decoration:underline'>\\1</span>",
      
      "#{COLOR:(.*?)}(.*?){/COLOR}#s"     => "<span style='color:\\1'>\\2</span>",
      "#{FONT:(.*?)}(.*?){/FONT}#s"       => "<span style='font-family:\\1'>\\2</span>",
      "#{SIZE:([0-9]*)}(.*?){/SIZE}#s"    => "<span style='font-size:\\1px'>\\2</span>",
      
      "#{LEFT}(.*?){/LEFT}#s"             => "<div align='left'>\\1</div>",
      "#{RIGHT}(.*?){/RIGHT}#s"           => "<div align='right'>\\1</div>",
      "#{CENTER}(.*?){/CENTER}#s"         => "<div align='center'>\\1</div>",
  
      "#{IDENT}(.*?){/IDENT}#s"           => "<ul>\\1</ul>",
      "#{LI}(.*?){/LI}#s"                 => "<ul><li>\\1</li></ul>",
      "#{BR/}#"                           => "<br />",
  
      "#{SUB}(.*?){/SUB}#s"               => "<sub>\\1</sub>",
      "#{SUP}(.*?){/SUP}#s"               => "<sup>\\1</sup>",
      "#{UPPER}(.*?){/UPPER}#s"           => "''.strtoupper(\'\\1\').''"
  
  );
}

function _reptag_format_info() {
  return array(t('Simple Format Tags (B, I, COLOR, ...)'), TRUE);
}

function _reptag_format_help() {
  return array(
  
      "{H(1-4)}Headline 2{/H(1-4)}"          => "<h2>Headline 2</h2>",
      
      "{B}strong{/B}"                        => "<strong>strong</strong>",
      "{I}italic{/I}"                        => "<i>italic</i>",
      "{U}underline{/U}"                     => "<span style='text-decoration:underline'>underline</span>",
      
      "{COLOR:#F00}Red{/COLOR}"              => "<span style='color:#F00'>Red</span>",
      "{FONT:courier}Courier{/FONT}"         => "<span style='font-family:courier'>Courier</span>",
      "{SIZE:18}font-size 18{/SIZE}"         => "<span style='font-size:18px'>font-size 18</span>",
      
      "{LEFT}left{/LEFT}"                    => "<div align='left'>left</div>",
      "{RIGHT}right{/RIGHT}"                 => "<div align='right'>right</div>",
      "{CENTER}center{/CENTER}"              => "<div align='center'>center</div>",
  
      "text{IDENT}ident{/IDENT}"             => "text<ul>ident</ul>",
      "{LI}li{/LI}"                          => "<ul><li>list</li></ul>",
      "line{BR/}break"                       => "line<br />break",
      
      "text{SUB}sub{/SUB}"                   => "text<sub>sub</sub>",
      "text{SUP}sup{/SUP}"                   => "text<sup>sup</sup>",
      "{UPPER}text{/UPPER}"                  => strtoupper('text')    
  
  );
}
