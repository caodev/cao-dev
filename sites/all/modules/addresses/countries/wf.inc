<?php

/**
 * @file
 * "Wallis and Futuna" specific data
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
function addresses_province_list_wf() {
  return array(
    'A' => t('Alo'),
    'S' => t('Sigave'),
    'W' => t('Wallis')
  );
}
