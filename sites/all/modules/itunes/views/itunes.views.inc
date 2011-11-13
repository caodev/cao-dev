<?php
// $Id: itunes.views.inc,v 1.1 2010/05/20 22:55:48 drewish Exp $

/**
 * @file
 * Views includes.
 */

/**
 * Implementation of hook_views_plugins().
 */
function itunes_views_plugins() {
  return array(
    'module' => 'itunes',
    'style' => array(
      'itunes_rss' => array(
        'title' => t('iTunes RSS Feed'),
        'help' => t('Generates an RSS feed from a view with extra iTunes specific attributes.'),
        'handler' => 'itunes_plugin_style_rss',
        'path' => drupal_get_path('module', 'itunes') . '/views',
        'theme' => 'views_view_rss',
        'parent' => 'rss',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'feed',
      ),
    ),
  );
}