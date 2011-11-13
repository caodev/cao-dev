<?php
// $Id: links.tags.inc,v 1.2.2.2 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Link and URL tags
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_links_init($context) {
  return array(
    
    "#{BACK}(.*?){/BACK}#s"                         => "<a href='javascript:history.back()'>\\1</a>",
    
    "#{MAIL[\s:]+(.*?)}(.*?){/MAIL}#s"              => "<a href='mailto:\\1'>\\2</a>",
    "#{MAILEX[\s:]+(.*?) (.*?)}(.*?){/MAILEX}#s"    => "<a href='mailto:\\1?subject=\\2'>\\3</a>",
    
    "#{URL}www\.(.*?){/URL}#s"                      => "<a href='http://www.\\1'>\\1</a>",
    "#{URL}(.*?){/URL}#s"                           => "<a href='\\1'>\\1</a>",
    "#{URL[\s:=]+www\.(.*?)}(.*?){/URL}#s"          => "<a href='http://www.\\1'>\\2</a>",
    "#{URL[\s:=]+(.*?)}(.*?){/URL}#s"               => "<a href='\\1'>\\2</a>",
    
    "#{INT[\s:]+(.*?)}(.*?){/INT}#se"               => "l('\\2', '\\1')",
    "#{EXT[\s:]+(.*?)}(.*?){/EXT}#s"                => "<a href='\\1' target='_blank'>\\2</a>",
    
    "#{NODE[\s:]+(.*?)}(.*?){/NODE}#se"             => "l('\\2', 'node/\\1')",
    "#{FORUM[\s:]+(.*?)}(.*?){/FORUM}#se"           => "l('\\2', 'forum/\\1')",
    "#{TAXOTERM[\s:]+(.*?)}(.*?){/TAXOTERM}#se"     => "l('\\2', 'taxonomy/term/\\1')",
    "#{TAXOMENU[\s:]+(.*?)}(.*?){/TAXOMENU}#se"     => "l('\\2', 'taxonomy_menu/\\1')",
    "#{TAXOMENU:V([0-9]*)}(.*?){/TAXOMENU}#se"      => "l('\\2', 'taxonomy_menu/\\1')",
    "#{TAXOMENU:T([0-9]*)}(.*?){/TAXOMENU}#se"      => "_reptag_links_taxomenu('\\2', \\1)"
    
  );
}

function _reptag_links_info() {
  return array(t('Links & Navigation (INT, EXT, MAIL, ...)'), TRUE);
}

function _reptag_links_help() {
  return array( 
    
    "{BACK}Back{/BACK}"                                   => "<a href=\"javascript:history.back()\">Back</a>",
    
    "{MAIL:mail@drupal}Send eMail{/MAIL}"                 => "<a href=\"mailto:mail@drupal\">Send eMail</a>",
    "{MAILEX:mail@drupal This is a subject}Send eMail with subject{/MAILEX}"
            => "<a href=\"mailto:mail@drupal?subject=This is a subject\">Send eMail with subject</a>",
          
    "{URL}www.google.com{/URL}"                           => "<a href='http://www.google.com'>www.google.com</a>",
    "{URL}http://www.google.com{/URL}"                    => "<a href='http://www.google.com'>http://www.google.com</a>",
    "{URL:www.google.com}Google{/URL}"                    => "<a href='http://www.google.com'>Google</a>",
    "{URL:http://www.google.com}Google{/URL}"             => "<a href='http://www.google.com'>Google</a>",
  
    "{INT:admin/settings/reptag}Settings{/INT}"           => l('Settings', 'admin/settings/reptag'),
    "{EXT:http://www.google.com}Google{/EXT}"             => "<a href=\"http://www.google.com\" target=\"_blank\">Google</a>",
    
    "{NODE:20}link to node 20{/NODE}"                     => l('link to node 20', 'node/20'),
    "{FORUM:8}link to forum 8{/FORUM}"                    => l('link to forum 8', 'forum/8'),
    "{TAXOTERM:54}link to term{/TAXOTERM}"                => l('link to term 54', 'taxonomy/term/54'),
    "{TAXOMENU:2/6}link to taxonomy_menu{/TAXOMENU}"      => l('link to vocabulary 26', 'taxonomy_menu/2/6'),
    "{TAXOMENU:V2}link to taxonomy_menu{/TAXOMENU}"       => l('link to vocabulary 2', 'taxonomy_menu/2'),
    "{TAXOMENU:T12}link to taxonomy_menu{/TAXOMENU}"      => l('link to term 12', 'taxonomy_menu/x/y/12'),
    
  );
}

function _reptag_links_taxomenu($text, $tid) {
  $parents = taxonomy_get_parents_all($tid);
  foreach ($parents as $term => $tobj) {
    $path = $tobj->tid .'/'. $path;
  }
  $path = 'taxonomy_menu/'. $tobj->vid .'/'. $path;
  
  return l($text, $path);
}
