<?php

/**
 * @file
 * "Saint Vincent and the Grenadines" specific data
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
function addresses_province_list_vc() {
  return array(
    'C' => t('Charlotte'),
    'R' => t('Grenadines'),
    'A' => t('Saint Andrew'),
    'D' => t('Saint David'),
    'G' => t('Saint George'),
    'P' => t('Saint Patrick')
  );
}
