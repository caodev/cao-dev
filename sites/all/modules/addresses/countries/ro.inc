<?php

/**
 * @file
 * "Romania" specific data
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
function addresses_province_list_ro() {
  return array(
    'AB' => t('Alba'),
    'AR' => t('Arad'),
    'AG' => t('Arges'),
    'BC' => t('Bacau'),
    'BH' => t('Bihor'),
    'BN' => t('Bistrita-Nasaud'),
    'BT' => t('Botosani'),
    'BR' => t('Braila'),
    'BV' => t('Brasov'),
    'B'  => t('Bucuresti'),
    'BZ' => t('Buzau'),
    'CR' => t('Calarasi'),
    'CS' => t('Caras-Severin'),
    'CJ' => t('Cluj'),
    'CT' => t('Constanta'),
    'CV' => t('Covasna'),
    'DB' => t('Dambovita'),
    'DJ' => t('Dolj'),
    'GL' => t('Galati'),
    'GR' => t('Giurgiu'),
    'GJ' => t('Gorj'),
    'HR' => t('Harghita'),
    'HD' => t('Hunedoara'),
    'IL' => t('Ialomita'),
    'IS' => t('Iasi'),
    'IF' => t('Ilfov'),
    'MM' => t('Maramures'),
    'MH' => t('Mehedinti'),
    'MS' => t('Mures'),
    'NT' => t('Neamt'),
    'OT' => t('Olt'),
    'PH' => t('Prahova'),
    'SJ' => t('Salaj'),
    'SM' => t('Satu Mare'),
    'SB' => t('Sibiu'),
    'SV' => t('Suceava'),
    'TR' => t('Teleorman'),
    'TM' => t('Timis'),
    'TL' => t('Tulcea'),
    'VS' => t('Vaslui'),
    'VL' => t('Valcea'),
    'VN' => t('Vrancea')
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
function addresses_address_format_ro() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_street_hcard]
[addresses_additional_hcard]
[addresses_postal_code_hcard] [addresses_city_hcard], [addresses_province_name_hcard]
[addresses_country_name_hcard]';
}
