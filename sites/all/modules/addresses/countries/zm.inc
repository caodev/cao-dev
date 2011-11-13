<?php

/**
 * @file
 * "Zambia" specific data
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
function addresses_province_list_zm() {
  return array(
    'CE' => t('Central Province'),
    'CB' => t('Copperbelt Province'),
    'EA' => t('Eastern Province'),
    'LP' => t('Luapula Province'),
    'LK' => t('Lusaka Province'),
    'NO' => t('Northern Province'),
    'NW' => t('North-Western Province'),
    'SO' => t('Southern Province'),
    'WE' => t('Western Province')
  );
}
