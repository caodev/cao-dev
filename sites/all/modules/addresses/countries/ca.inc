<?php

/**
 * @file
 * "Canada" specific data
 */

/**
 * Returns an associative array of states/territories where
 *   -> the keys are integers starting from 1
 *   -> the values are the English names for those states/territories
 *
 * The states are grouped together at the beginning of the array and sorted
 * alphabetically.
 *
 * The territories are grouped together at the end of the array and sorted
 * alphabetically.
 *
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
function addresses_province_list_ca() {
  return array(
    'AB' => t('Alberta'),
    'BC' => t('British Columbia'),
    'MB' => t('Manitoba'),
    'NB' => t('New Brunswick'),
    'NL' => t('Newfoundland and Labrador'),
    'NS' => t('Nova Scotia'),
    'ON' => t('Ontario'),
    'PE' => t('Prince Edward Island'),
    'QC' => t('Quebec'),
    'SK' => t('Saskatchewan'),
    'NT' => t('Northwest Territories'),
    'NU' => t('Nunavut'),
    'YT' => t('Yukon Territory')
  );
}
