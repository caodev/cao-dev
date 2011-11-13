<?php
/**
 * @author Bruno Massa
 * @file
 * Hold functions that are not important and required oftem.
 */

/**
 * Show the Address using the default view.
 * @ingroup themable
 */
function theme_addresses_cck_formatter_default($element) {
  // Include the important .inc file
  module_load_include('inc', 'addresses');

  // Print the address
  return theme('addresses', $element['#item']);
}

/**
 * Show the Address using the Single Line view.
 * @ingroup themable
 */
function theme_addresses_cck_formatter_single_line($element) {
  // Include the important .inc file
  module_load_include('inc', 'addresses');

  // Print the address using the one-line only theme
  return theme('addresses_address_singleline', $element['#item']);
}
