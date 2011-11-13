<?php

/**
 * @file
 * "Czech Republic" specific data
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
function addresses_province_list_cz() {
  return array(
    'JC' => t('South Bohemian Region (Jihocesky kraj)'),
    'JM' => t('South Moravian Region (Jihomoravsky kraj)'),
    'KA' => t('Carlsbad Region  (Karlovarsky kraj)'),
    'VY' => t('Vysoc(ina Region (kraj Vysoc(ina)'),
    'KR' => t('Hradec Kralove Region (Kralovehradecky kraj)'),
    'LI' => t('Liberec Region (Liberecky kraj)'),
    'MO' => t('Moravian-Silesian Region (Moravskoslezsky kraj)'),
    'OL' => t('Olomouc Region (Olomoucky kraj)'),
    'PA' => t('Pardubice Region (Pardubicky kraj)'),
    'PL' => t('Plzen( Region Plzensky kraj)'),
    'PR' => t('Prague - the Capital (Praha - hlavni mesto)'),
    'ST' => t('Central Bohemian Region (Stredocesky kraj)'),
    'US' => t('Usti nad Labem Region (Ustecky kraj)'),
    'ZL' => t('Zlin Region (Zlinsky kraj)')
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
function addresses_address_format_cz() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard]
[addresses_city_hcard]
[addresses_postal_code_hcard]
[addresses_country_name_hcard]';
}
