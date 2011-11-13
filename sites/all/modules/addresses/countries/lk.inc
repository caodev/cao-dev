<?php

/**
 * @file
 * "Sri Lanka" specific data
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
function addresses_province_list_lk() {
  return array(
    'CE' => t('Central'),
    'EA' => t('Eastern'),
    'NC' => t('North Central'),
    'NO' => t('Northern'),
    'NW' => t('North Western'),
    'SA' => t('Sabaragamuwa'),
    'SO' => t('Southern'),
    'UV' => t('Uva'),
    'WE' => t('Western')
  );
}
