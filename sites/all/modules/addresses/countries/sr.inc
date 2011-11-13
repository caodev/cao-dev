<?php

/**
 * @file
 * "Suriname" specific data
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
function addresses_province_list_sr() {
  return array(
    'BR' => t('Brokopondo'),
    'CM' => t('Commewijne'),
    'CR' => t('Coronie'),
    'MA' => t('Marowijne'),
    'NI' => t('Nickerie'),
    'PA' => t('Para'),
    'PM' => t('Paramaribo'),
    'SA' => t('Saramacca'),
    'SI' => t('Sipaliwini'),
    'WA' => t('Wanica')
  );
}
