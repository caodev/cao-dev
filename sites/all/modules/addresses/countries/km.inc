<?php

/**
 * @file
 * "Comoros" specific data
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
function addresses_province_list_km() {
  return array(
    'G' => t('Grande Comore'),
    'A' => t('Anjouan'),
    'M' => t('Moheli')
  );
}
