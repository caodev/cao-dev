<?php

/**
 * @file
 * "Netherlands" specific data
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
function addresses_province_list_nl() {
  return array(
    'DR' => t('Drenthe'),
    'FL' => t('Flevoland'),
    'FR' => t('Friesland'),
    'GE' => t('Gelderland'),
    'GR' => t('Groningen'),
    'LI' => t('Limburg'),
    'NB' => t('Noord Brabant'),
    'NH' => t('Noord Holland'),
    'OV' => t('Overijssel'),
    'UT' => t('Utrecht'),
    'ZE' => t('Zeeland'),
    'ZH' => t('Zuid Holland')
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
function addresses_address_format_nl() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard]
[addresses_postal_code_hcard] [addresses_province_code_hcard] [addresses_city_hcard]
[addresses_country_name_hcard]';
}
