<?php

/**
 * @file
 * "Turkmenistan" specific data
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
function addresses_province_list_tm() {
  return array(
    'A' => t('Ahal Welayaty'),
    'B' => t('Balkan Welayaty'),
    'D' => t('Dashhowuz Welayaty'),
    'L' => t('Lebap Welayaty'),
    'M' => t('Mary Welayaty')
  );
}
