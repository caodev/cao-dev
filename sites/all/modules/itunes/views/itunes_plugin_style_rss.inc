<?php
// $Id: itunes_plugin_style_rss.inc,v 1.2 2010/09/13 19:00:31 drewish Exp $

/**
 * @file
 * Contains the RSS style plugin.
 */

/**
 * iTunes specific style plugin to render an RSS feed.
 *
 * @ingroup views_style_plugins
 */
class itunes_plugin_style_rss extends views_plugin_style_rss {
  function option_definition() {
    $options = parent::option_definition();

    $options['subtitle'] = array('default' => '', 'translatable' => TRUE);
    $options['summary'] = array('default' => '', 'translatable' => TRUE);
    $options['author'] = array('default' => '', 'translatable' => TRUE);
    $options['copyright'] = array('default' => '', 'translatable' => TRUE);
    $options['image_url'] = array('default' => '', 'translatable' => FALSE);
    $options['explicit'] = array('default' => 0, 'translatable' => FALSE);
    $options['block'] = array('default' => 0, 'translatable' => FALSE);
    $options['owner_name'] = array('default' => '', 'translatable' => FALSE);
    $options['owner_email'] = array('default' => '', 'translatable' => FALSE);
    $options['categories'] = array('default' => array('', '', ''), 'translatable' => FALSE);
    $options['keywords'] = array('default' => '', 'translatable' => TRUE);
    $options['new_feed_url'] = array('default' => '', 'translatable' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['subtitle'] = array(
      '#type' => 'textfield',
      '#title' => t('Subtitle'),
      '#default_value' => $this->options['subtitle'],
      '#maxlength' => 255,
      '#description' => t("The contents of this tag are shown in the Description column in iTunes. The subtitle displays best if it is only a few words long."),
    );
    $form['summary'] = array(
      '#type' => 'textarea',
      '#title' => t('Summary'),
      '#default_value' => $this->options['summary'],
      '#maxlength' => 4000,
      '#rows' => 5,
      '#description' => t('The contents of this tag are shown in a separate window that appears when the "circled i" in the Description column is clicked. It also appears on the iTunes page for your podcast.'),
    );
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#default_value' => $this->options['author'],
      '#maxlength' => 255,
      '#description' => t("This is shown in the Artist column in iTunes."),
    );
    $form['copyright'] = array(
      '#type' => 'textfield',
      '#title' => t('Copyright'),
      '#default_value' => $this->options['copyright'],
      '#maxlength' => 255,
      '#description' => t('i.e. "&#xA9; 2005 John Doe"'),
    );
    $form['image_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Image URL'),
      '#default_value' => $this->options['image_url'],
      '#maxlength' => 255,
      '#description' => t('This specifies the artwork for your podcast. iTunes prefers square .jpg images that are at least 300 x 300 pixels, which is different than what is specified for the standard RSS image tag. iTunes supports images in JPEG and PNG formats. The URL must end in ".jpg" or ".png". If you change your podcast’s image, also change the file’s name. iTunes may not change the image if it checks your feed and the image URL is the same.'),
    );
    $form['new_feed_url'] = array(
      '#type' => 'textfield',
      '#title' => t('New Feed URL'),
      '#default_value' => $this->options['new_feed_url'],
      '#maxlength' => 255,
      '#description' => t('Podcasters occasionally need to move their feed from one location to another. To do so without losing subscribers, you must convey the change directly to all users who are subscribed to your feed. Specify the <a href="http://www.apple.com/itunes/podcasts/specs.html#changing">new feed url tag</a> here if desired.'),
    );
    $form['explicit'] = array(
      '#type' => 'select', '#title' => t('Explicit'),
      '#options' => array(0 => 'Unspecified', ITUNES_EXPLICIT_YES => 'Yes', ITUNES_EXPLICIT_CLEAN => 'Clean'),
      '#default_value' => $this->options['explicit'],
      '#description' => t('If select "yes", an "explicit" parental advisory graphic will appear next to your podcast artwork on the iTunes Music Store, and in the Name column in iTunes. If you select "clean", the parental advisory type is considered Clean, meaning that no explicit language or adult content is included anywhere in the episode, and a "clean" graphic will appear.'),
    );
    $form['block'] = array(
      '#type' => 'checkbox', '#title' => t('Hide'),
      '#default_value' => $this->options['block'],
      '#description' => t('Check this to prevent the entire podcast from appearing in the iTunes Podcast directory.'),
    );
    $form['owner_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => $this->options['owner_name'],
      '#maxlength' => 255,
      '#description' => t("Apple uses this information to contact the owner of the podcast for communication specifically about their podcast. It will not be publicly displayed but it may be picked up by spammers."),
    );
    $form['owner_email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email'),
      '#default_value' => $this->options['owner_email'],
      '#maxlength' => 255,
    );
    $category_options = array('' => t('- None selected -'));
    foreach (itunes_categories() as $top_level => $children) {
      $category_options[] = (object) array(
        'option' => array($top_level => $top_level)
      );
      foreach ($children as $second_level) {
        $category_options[] = (object) array(
          'option' => array($top_level . '|' . $second_level => ' - ' . $second_level)
        );
      }
    }
    $form['categories'] = array(
      '#type' => 'fieldset',
      '#title' => t('Categories'),
      '#collapsible' => TRUE,
      '#description' => '<p>'. t('There are two ways to browse podcast subject categories on iTunes: click Browse in the Quick Links box or click a selection in the Category box. The former method leads to a text-based table, while the latter leads to pages that include the podcast art.') .'</p>'
        .'<p>'. t('For placement within the older, text-based browse system, podcast feeds may list up to 3 category/subcategory pairs. (For example, "Music" counts as 1, as does "Business > Careers.") For placement within the newer browse system based on Category links, however, and for placement within the Top Podcasts lists that appear in the right column of most podcast pages, only the first category listed in the feed is used.') .'</p>',
    );
    $form['categories'][0] = array(
      '#type' => 'select',
      '#title' => t('First Category'),
      '#default_value' => $this->options['categories'][0],
      '#options' => $category_options,
    );
    $form['categories'][1] = array(
      '#type' => 'select',
      '#title' => t('Second Category'),
      '#default_value' => $this->options['categories'][1],
      '#options' => $category_options,
    );
    $form['categories'][2] = array(
      '#type' => 'select',
      '#title' => t('Third Category'),
      '#default_value' => $this->options['categories'][2],
      '#options' => $category_options,
    );
    $form['keywords'] = array(
      '#type' => 'textfield',
      '#title' => t('Keywords'),
      '#default_value' => $this->options['keywords'],
      '#maxlength' => 4000,
      '#description' => t('This tag allows users to search on a maximum of 12 text keywords. Use commas to separate keywords.'),
    );
  }

  function options_validate(&$form, &$form_state) {
    if (!empty($form_state['values']['style_options']['image_url'])) {
      if (!valid_url($form_state['values']['style_options']['image_url'])) {
        form_set_error('image_url', t('The image URL must be a valid URL.'));
      }
      else {
        $url = parse_url($form_state['values']['style_options']['image_url']);
        $ext = drupal_strtolower(pathinfo($url['path'], PATHINFO_EXTENSION));
        if (!isset($url['path']) || ($ext != 'jpg' && $ext != 'png')) {
          form_set_error('image_url', t('The URL must specify a file ending with <code>.jpg</code> or <code>.png</code>.'));
        }
      }
    }
    if (!empty($form_state['values']['style_options']['owner_email'])) {
      if (!valid_email_address($form_state['values']['style_options']['owner_email'])) {
        form_set_error('owner_email', t('The owner email must be a valid email address.'));
      }
    }
    if (!empty($form_state['values']['style_options']['keywords'])) {
      if (substr_count($form_state['values']['style_options']['keywords'], ',') > 11) {
        form_set_error('keywords', t('Only 12 keywords are allowed.'));
      }
    }
  }

  function get_channel_elements() {
    $extra = parent::get_channel_elements();

    // Try to add an atom self link to make feed validators happy.
    if ($path = $this->display->handler->get_path()) {
      $extra[] = array(
        'namespace' => array('xmlns:atom' => 'http://www.w3.org/2005/Atom'),
        'key' => 'atom:link',
        'attributes' => array(
          'href' => url($path, array('absolute' => TRUE)),
          'rel' => 'self',
          'type' => 'application/rss+xml',
        ),
      );
    }

    // Specify the namespace in this element because it is always included so
    // we can omit it from subsequent elements.
    $extra[] = array(
      'namespace' => array('xmlns:itunes' => 'http://www.itunes.com/dtds/podcast-1.0.dtd'),
      'key' => 'itunes:explicit',
      'value' => itunes_explicit($this->options['explicit']),
    );
    if ($this->options['copyright']) {
      $extra[] = array(
        'key' => 'copyright',
        'value' => $this->options['copyright'],
      );
    }
    if ($this->options['author']) {
      $extra[] = array(
        'key' => 'itunes:author',
        'value' => $this->options['author'],
      );
    }
    if ($this->options['image_url']) {
      $extra[] = array(
        'key' => 'itunes:image',
        'attributes' => array('href' => $this->options['image_url']),
        'value' => NULL,
      );
    }
    if ($this->options['new_feed_url']) {
      $extra[] = array(
        'key' => 'itunes:new-feed-url',
        'value' => $this->options['new_feed_url'],
      );
    }
    if ($this->options['subtitle']) {
      $extra[] = array(
        'key' => 'itunes:subtitle',
        'value' => $this->options['subtitle'],
      );
    }
    if ($this->options['summary']) {
      $extra[] = array(
        'key' => 'itunes:summary',
        'value' => $this->options['summary'],
      );
    }
    if ($this->options['block']) {
      $extra[] = array(
        'key' => 'itunes:block',
        'value' => 'yes',
      );
    }
    if ($this->options['owner_name'] && $this->options['owner_email']) {
      $extra[] = array(
        'key' => 'itunes:owner',
        'value' => array(
          array(
            'key' => 'itunes:name',
            'value' => $this->options['owner_name'],
          ),
          array(
            'key' => 'itunes:email',
            'value' => $this->options['owner_email'],
          ),
        ),
      );
    }
    // We've got up to three categories which can consist of a parent and
    // child stored as "Parent" or "Parent|Child". We need to split them up and
    // create nested elements.
    foreach ($this->options['categories'] as $category) {
      if ($category) {
        $parts = explode('|', $category);
        $element = array(
          'key' => 'itunes:category',
          'attributes' => array('text' => $parts[0]),
          'value' => NULL,
        );
        if (isset($parts[1])) {
          $element['value'][] = array(
            'key' => 'itunes:category',
            'attributes' => array('text' => $parts[1]),
            'value' => NULL,
          );
        }
        $extra[] = $element;
      }
    }
    if ($this->options['keywords']) {
      $extra[] = array(
        'key' => 'itunes:keywords',
        'value' => $this->options['keywords'],
      );
    }

    return $extra;
  }
}
