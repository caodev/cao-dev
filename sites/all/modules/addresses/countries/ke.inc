<?php

/**
 * @file
 * "Kenya" specific data
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
function addresses_province_list_ke() {
  return array(
    'CE' => t('Central'),
    'CO' => t('Coast'),
    'EA' => t('Eastern'),
    'NA' => t('Nairobi Area'),
    'NE' => t('North Eastern'),
    'NY' => t('Nyanza'),
    'RV' => t('Rift Valley'),
    'WE' => t('Western')
  );
}
