<?php

/**
 * @file
 * "Myanmar" specific data
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
function addresses_province_list_mm() {
  return array(
    'AY' => t('Ayeyarwady'),
    'BG' => t('Bago'),
    'MG' => t('Magway'),
    'MD' => t('Mandalay'),
    'SG' => t('Sagaing'),
    'TN' => t('Tanintharyi'),
    'YG' => t('Yangon'),
    'CH' => t('Chin State'),
    'KC' => t('Kachin State'),
    'KH' => t('Kayah State'),
    'KN' => t('Kayin State'),
    'MN' => t('Mon State'),
    'RK' => t('Rakhine State'),
    'SH' => t('Shan State')
  );
}
