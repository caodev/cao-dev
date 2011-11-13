<?php

/**
 * @file
 * "Heard Island and McDonald Islands" specific data
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
function addresses_province_list_hm() {
  return array(
    'F' => t('Flat Island'),
    'M' => t('McDonald Island'),
    'S' => t('Shag Island'),
    'H' => t('Heard Island')
  );
}
