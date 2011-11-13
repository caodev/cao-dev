<?php

/**
  * Implementation of views_plugin_style().
  */
class views_galleria_style_plugin extends views_plugin_style {

  /**
   * Set default options
   */
  function options(&$options) {
    $options['back_next_buttons'] = 0;
  }

  function options_form(&$form, &$form_state) {

    $form['back_next_buttons'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display back and next buttons when the mouse is over the area.'),
      '#default_value' => $this->options['back_next_buttons'],
    );
  }
}