<?php
// $Id: slideshowpro.views.inc,v 1.1 2009/02/26 19:40:00 alexb Exp $

/**
 * @file
 * Views file for Slideshow Pro integration.
 *
 * Contains hook implementations to be discovered by the views module.
 */

/**
 * Implementation of hook_views_plugins.
 */
function slideshowpro_views_plugins() {
  return array(
    'module' => 'slideshowpro',
    'style' => array(
      'slideshowpro_xml' => array(
        'title' => t('SlideShowPro: XML feed'),
        'help' => t('Display the node with the SlideShowPro integration module.'),
        'handler' => 'slideshowpro_plugin_style_xml',
        'theme' => 'slideshowpro_feed',
        'theme file' => 'slideshowpro.theme.inc',
        'theme path' => drupal_get_path('module', 'slideshowpro'),
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'feed',
        'help topic' => 'style-slideshowpro-xml',
      ),
    ),
  );

}