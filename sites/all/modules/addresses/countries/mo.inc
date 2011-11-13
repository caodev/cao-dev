<?php

/**
 * @file
 * "Macau" specific data
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
function addresses_province_list_mo() {
  return array(
    'OLF' => t('Our Lady Fatima Parish'),
    'ANT' => t('St. Anthony Parish'),
    'LAZ' => t('St. Lazarus Parish'),
    'CAT' => t('Cathedral Parish'),
    'LAW' => t('St. Lawrence Parish')
  );
}
