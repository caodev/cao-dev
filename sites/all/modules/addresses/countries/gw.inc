<?php

/**
 * @file
 * "Guinea-Bissau" specific data
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
function addresses_province_list_gw() {
  return array(
    'BF' => t('Bafata Region'),
    'BB' => t('Biombo Region'),
    'BS' => t('Bissau Region'),
    'BL' => t('Bolama Region'),
    'CA' => t('Cacheu Region'),
    'GA' => t('Gabu Region'),
    'OI' => t('Oio Region'),
    'QU' => t('Quinara Region'),
    'TO' => t('Tombali Region')
  );
}
