<?php
/**
 * @file
 * Provide a Galleria display style for Views. This file is autoloaded by views.
 */

/**
  * Implementation of hook_views_plugin().
  */
function views_galleria_views_plugins() {
  return array(
    'style' => array(
      'views_galleria' => array(
        'title' => t('Views Galleria'),
        'theme' => 'views_view_galleria',
        'help' => t('Creates a Galleria style gallery.'),
        'handler' => 'views_galleria_style_plugin',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
