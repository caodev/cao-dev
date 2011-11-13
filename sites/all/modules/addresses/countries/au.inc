<?php

/**
 * @file
 * "Australia" specific data
 */

/**
 * Implementation of hook_province_list().
 *
 * Its a hook from Addresses module to list all
 * states/provinces/teritories of a given country
 *
 * @return
 *   Array. states where the keys are the state
 *   code and the value is the state name
 */
function addresses_province_list_au() {
  return array(
    'ACT' => t('Australian Capital Territory'),
    'NSW' => t('New South Wales'),
    'NT' => t('Northern Territory'),
    'QLD' => t('Queensland'),
    'SA' => t('South Australia'),
    'TAS' => t('Tasmania'),
    'VIC' => t('Victoria'),
    'WA' => t('Western Australia')
  );
}

/**
 * Implementation of hook_address_format().
 *
 * Format the address using local preferences. It uses
 * Token module to convert this tokens to their real values.
 *
 * @return
 *   String. The address field tokens
 */
function addresses_address_format_au() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard]
[addresses_city_hcard] [addresses_province_name_hcard] [addresses_postal_code_hcard]
[addresses_country_name_hcard]';
}
