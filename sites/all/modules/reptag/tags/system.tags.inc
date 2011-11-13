<?php
// $Id: system.tags.inc,v 1.2.2.3 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Tags for global and system values. See also token.module
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_system_init($context) {
  global $user;

  return array(
  
    "#{DATETIME_LONG}#"                 => format_date(time(), 'large'),
    "#{DATETIME_MEDIUM}#"               => format_date(time(), 'medium'),
    "#{DATETIME_SHORT}#"                => format_date(time(), 'small'),
    
    "#{DATE_XLONG}#"                    => strftime('%A, %B %d %Y'),
    "#{DATE_LONG}#"                     => strftime('%a %b %d %Y'),
    "#{DATE_MEDIUM}#"                   => strftime('%b %d %Y'),
    "#{DATE_SHORT}#"                    => strftime('%x'),
    "#{DATE}#"                          => strftime('%x'),
    
    "#{TIME_LONG}#"                     => date('H:i:s'),
    "#{TIME_LONG_AMPM}#"                => date('h:i:s a'),
    "#{TIME_SHORT}#"                    => date('H:i'),
    "#{TIME_SHORT_AMPM}#"               => date('h:i a'),
    
    "#{BREADCRUMB}#"                    => theme('breadcrumb', drupal_set_breadcrumb()),
    "#{SITE}#"                          => variable_get('site_name', 'Drupal'),
    "#{PAGE}#"                          => request_uri(),
    
    // Use @ to quiet PHP notices if the user is anonymous
    "#{USERNAME}#"                      => @_reptag_system_user($user->name),
    "#{USERID}#"                        => $user->uid,
    "#{USERMAIL}#"                      => @$user->mail,
    "#{USER_CREATED}#"                  => @format_date($user->created, 'small'),
    "#{USER_ACCESS}#"                   => @format_date($user->access, 'small'),
    "#{USER_LOGIN}#"                    => @format_date($user->login, 'small'),
    "#{USER_SESSION}#"                  => @date('H:i', (time() - $user->login)),
    "#{USERLANG}#"                      => @_reptag_language(),
    
    //"#{PHP\}(.*?)\{/PHP\}#se"    => "''. _reptag_system_php_exec(stripslashes('\\1')) .''",
    "#{PHP:(.*?)\}#e"                    => "'<?php include(\''. stripslashes('\\1') .'\'); ?>'"
  );
}

function _reptag_system_info() {
  return t('Global Tags incl. Date, Time, User, Site, ...');
}

function _reptag_system_help() {
  global $user, $language;
  
  return array(

    "{DATETIME_LONG}"                 => format_date(time(), 'large'),
    "{DATETIME_MEDIUM}"               => format_date(time(), 'medium'),
    "{DATETIME_SHORT}"                => format_date(time(), 'small'),

    "{DATE_XLONG}"                    => strftime('%A, %B %d %Y'),
    "{DATE_LONG}"                     => strftime('%a %b %d %Y'),
    "{DATE_MEDIUM}"                   => strftime('%b %d %Y'),
    "{DATE_SHORT}"                    => strftime('%x'),
    "{DATE}"                          => strftime('%x'),

    "{TIME_LONG}"                     => date('H:i:s'),
    "{TIME_LONG_AMPM}"                => date('h:i:s a'),
    "{TIME_SHORT}"                    => date('H:i'),
    "{TIME_SHORT_AMPM}"               => date('h:i a'),

    "{BREADCRUMB}"                    => implode(' > ', array(l(t('Home'), 'node'), l(t('RepTag'), $_GET['q']))),
    "{SITE}"                          => variable_get('site_name', 'Drupal'),
    "{PAGE}"                          => request_uri(),

    "{USERNAME}"                      => _reptag_system_user($user->name),
    "{USERID}"                        => $user->uid,
    "{USERMAIL}"                      => $user->mail,
    "{USER_CREATED}"                  => format_date($user->created, 'small'),
    "{USER_ACCESS}"                   => format_date($user->access, 'small'),
    "{USER_LOGIN}"                    => format_date($user->login, 'small'),
    "{USER_SESSION}"                  => date('H:i', (time() - $user->login)),
    "{USERLANG}"                      => $language->language,

  );
}

function _reptag_system_user($name) {
  return empty($name) ? variable_get('anonymous', t('anonymous')) : $name;
}

/*
//disabled for security reasons
function _reptag_system_php_exec($code) {
  if (php_check_syntax($code)) {
    ob_start();
    exec($code);
    $output = ob_get_contents();
    ob_end_clean();
    return $output;
  } else {
    return '';
  }
}
*/
