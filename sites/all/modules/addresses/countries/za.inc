<?php

/**
 * @file
 * "South Africa" specific data
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
function addresses_province_list_za() {
  return array(
    'WC' => t('Western Cape'),
    'NC' => t('Northern Cape'),
    'EC' => t('Eastern Cape'),
    'KN' => t('KwaZulu-Natal'),
    'FS' => t('Free State'),
    'NW' => t('North West'),
    'GT' => t('Gauteng'),
    'MP' => t('Mpumalanga'),
    'LP' => t('Limpopo')
  );
}
