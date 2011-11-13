<?php

/**
 * @file
 * "Brunei Darussalam" specific data
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
function addresses_province_list_bn() {
  return array(
    'BEL' => t('Belait'),
    'BRM' => t('Brunei and Muara'),
    'TEM' => t('Temburong'),
    'TUT' => t('Tutong')
  );
}
