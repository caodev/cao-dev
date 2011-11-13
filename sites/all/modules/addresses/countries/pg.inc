<?php

/**
 * @file
 * "Papua New Guinea" specific data
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
function addresses_province_list_pg() {
  return array(
    'BV' => t('Bougainville'),
    'CE' => t('Central'),
    'CH' => t('Chimbu'),
    'EH' => t('Eastern Highlands'),
    'EB' => t('East New Britain'),
    'ES' => t('East Sepik'),
    'EN' => t('Enga'),
    'GU' => t('Gulf'),
    'MD' => t('Madang'),
    'MN' => t('Manus'),
    'MB' => t('Milne Bay'),
    'MR' => t('Morobe'),
    'NC' => t('National Capital'),
    'NI' => t('New Ireland'),
    'NO' => t('Northern'),
    'SA' => t('Sandaun'),
    'SH' => t('Southern Highlands'),
    'WE' => t('Western'),
    'WH' => t('Western Highlands'),
    'WB' => t('West New Britain')
  );
}
