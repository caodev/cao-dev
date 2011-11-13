<?php

/**
 * @file
 * "Cocos (Keeling) Islands" specific data
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
function addresses_province_list_cc() {
  return array(
    'D' => t('Direction Island'),
    'H' => t('Home Island'),
    'O' => t('Horsburgh Island'),
    'S' => t('South Island'),
    'W' => t('West Island')
  );
}
