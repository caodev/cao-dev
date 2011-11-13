<?php
// $Id: slideshowpro.theme.inc,v 1.1 2009/02/26 19:40:00 alexb Exp $

/**
 * @file
 * Theme file for Slideshow Pro integration.
 *
 * Contains theme functions registered by hook_theme().
 */

/**
 * Display the XML document.
 */
function theme_slideshowpro_feed($view, $options, $type) {
  global $base_url;

  $title_caption = &$options['title_caption'];
  $current_display = &$view->display[$view->current_display];

  $size = 'preview';

  /*

  I cannot figure out what this is for!?

  foreach ($view->filter as $filter) {
    if ($filter['field'] == 'slideshowpro.tid') {
      $size = $filter['options'];
    }
  }

  */
  
  $album_terms = array();
  $albums = array();
  $output = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
  $output .= "<gallery>\n";

  foreach ($view->result as $n) {

    $node = node_load($n->nid);
    $tids = array();

    if (module_exists('taxonomy')) {
      if ($n->tid) {
        $tids = array($n->tid);
        $album_terms[$n->tid] = taxonomy_get_term($n->tid);
      }
      // If no image gallery tid was passed in and image gallery is installed, get tids from node.
      else if (module_exists('image_gallery')) {
        foreach ($node->taxonomy as $term) {
          if ($term->vid == _image_gallery_get_vid()) {
            $album_terms[$term->tid] = $term;
            $tids[] = $term->tid;
          }
        }
      }
    }

    // Stick images with no album in an album called "In no album"
    if (!count($tids)) {
      $tids = array(0);
      $album->name = t('In no album');
      $album_terms[0] = $album;
    }

    $image = theme('slideshowpro_xml_image', $node, $size, $title_caption);

    // An image can be in more than one album.
    foreach ($tids as $tid) { 
      $albums[$tid][] = $image;
    }

  }

  ksort($albums);

  foreach ($albums as $tid => $images) {
    $output .= slideshowpro_xml_album($album_terms[$tid], $images);
  }

  $output .= "</gallery>\n";

  drupal_set_header('Content-Type: text/xml; charset=utf-8');
  print $output;

  module_invoke_all('exit');
  exit;
}

/**
 * Format an image.
 */
function theme_slideshowpro_xml_image(&$node, $size = 'preview', $title_caption = 0) {
  $output = '<img src="%src" title="%title" caption="%caption" link="%link" target="_blank" tn="%thumb" />'."\n";
  $variables = array(
    '%src' => slideshowpro_get_image_path() . basename($node->images[$size]), 
    '%title' => check_plain($node->title),
    '%caption' => $title_caption ? trim(check_plain($node->title)) : trim(check_plain(truncate_utf8($node->body, 100, TRUE, TRUE))), 
    '%link' => url('node/'. $node->nid, array('absolute' => TRUE)),
    '%thumb' => slideshowpro_get_image_path() . basename($node->images['thumbnail']),
  );
  return strtr($output, $variables);
}

/**
 * Theme output.
 */
function theme_slideshowpro_embed($output, $id) {
  return '<div class="slideshowpro" id="slideshowpro-'. $id .'">'. $output .'</div>';
}
