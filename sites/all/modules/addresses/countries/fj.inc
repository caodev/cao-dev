<?php

/**
 * @file
 * "Fiji" specific data
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
function addresses_province_list_fj() {
  return array(
    'C' => t('Central Division'),
    'N' => t('Northern Division'),
    'E' => t('Eastern Division'),
    'W' => t('Western Division'),
    'R' => t('Rotuma')
  );
}
