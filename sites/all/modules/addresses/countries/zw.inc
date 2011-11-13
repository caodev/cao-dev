<?php

/**
 * @file
 * "Zimbabwe" specific data
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
function addresses_province_list_zw() {
  return array(
    'BU' => t('Bulawayo (city)'),
    'HA' => t('Harare (city)'),
    'ML' => t('Manicaland'),
    'MC' => t('Mashonaland Central'),
    'ME' => t('Mashonaland East'),
    'MW' => t('Mashonaland West'),
    'MV' => t('Masvingo'),
    'MN' => t('Matabeleland North'),
    'MS' => t('Matabeleland South'),
    'MD' => t('Midlands')
  );
}
