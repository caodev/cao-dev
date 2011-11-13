<?php

/**
 * @file
 * "Germany" specific data
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
function addresses_province_list_de() {
  return array(
    'BB' => t('Brandenburg'),
    'BE' => t('Berlin'),
    'BW' => t('Baden-Württemberg'),
    'BY' => t('Bayern'),
    'HB' => t('Bremen'),
    'HE' => t('Hessen'),
    'HH' => t('Hamburg'),
    'MV' => t('Mecklenburg-Vorpommern'),
    'NI' => t('Niedersachsen'),
    'NW' => t('Nordrhein-Westfalen'),
    'RP' => t('Rheinland-Pfalz'),
    'SH' => t('Schleswig-Holstein'),
    'SL' => t('Saarland'),
    'SN' => t('Sachsen'),
    'ST' => t('Sachsen-Anhalt'),
    'TH' => t('Thüringen')
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
function addresses_address_format_de() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard]
[addresses_postal_code_hcard] [addresses_city_hcard]
[addresses_country_name_hcard]';
}
