<?php
// $Id: slideshowpro_plugin_style_xml.inc,v 1.1 2009/02/26 19:40:00 alexb Exp $

/**
 * @file
 * Views file for Slideshow Pro integration XML style plugin.
 *
 * Contains class to be discovered by the views module.
 */

/**
 * Style plugin to render slideshowpro xml.
 */
class slideshowpro_plugin_style_xml extends views_plugin_style {

  function option_definition() {
    $options = parent::option_definition();
    $options['title_caption'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['title_caption'] = array(
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['title_caption']),
      '#title' => t('Use image title as SSP caption and hide SSP title'),
      '#description' => t("Check this box if you would like to use the image title as caption. The image title will show up in SSP's caption area, the SSP title will be hidden."),
    );
  }

  /**
   * Return an array of additional XHTML elements to add to the channel.
   *
   * @return
   *   An array that can be passed to format_xml_elements().
  */ 
  function get_channel_elements() {
    return array();
  }

  function render() {
    if (empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }
    $rows = '';

    // This will be filled in by the row plugin and is used later on in the
    // theming output.
    $this->namespaces = array();

    // Fetch any additional elements for the channel and merge in their
    // namespaces.
    $this->channel_elements = $this->get_channel_elements();
    foreach ($this->channel_elements as $element) {
      if (isset($element['namespace'])) {
        $this->namespaces = array_merge($this->namespaces, $element['namespace']);
      }
    }

    foreach ($this->view->result as $row) {
      $rows .= $this->row_plugin->render($row);
    }

    return theme($this->theme_functions(), $this->view, $this->options, $rows);
  }
}