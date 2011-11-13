<?php

/**
 * @file
 * "Sierra Leone" specific data
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
function addresses_province_list_sl() {
  return array(
    'E' => t('Eastern'),
    'N' => t('Northern'),
    'S' => t('Southern'),
    'W' => t('Western')
  );
}
