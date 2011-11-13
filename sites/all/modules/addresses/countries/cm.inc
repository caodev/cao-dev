<?php

/**
 * @file
 * "Cameroon" specific data
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
function addresses_province_list_cm() {
  return array(
    'ADA' => t('Adamawa Province'),
    'CEN' => t('Centre Province'),
    'EST' => t('East Province'),
    'EXN' => t('Extreme North Province'),
    'LIT' => t('Littoral Province'),
    'NOR' => t('North Province'),
    'NOT' => t('Northwest Province'),
    'OUE' => t('West Province'),
    'SUD' => t('South Province'),
    'SOU' => t('Southwest Province')
  );
}
