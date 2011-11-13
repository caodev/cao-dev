<?php

/**
 * @file
 * "United States Minor Outlying Islands" specific data
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
function addresses_province_list_um() {
  return array(
    'BI' => t('Baker Island'),
    'HI' => t('Howland Island'),
    'JI' => t('Jarvis Island'),
    'JA' => t('Johnston Atoll'),
    'KR' => t('Kingman Reef'),
    'MA' => t('Midway Atoll'),
    'NI' => t('Navassa Island'),
    'PA' => t('Palmyra Atoll'),
    'WI' => t('Wake Island')
  );
}
