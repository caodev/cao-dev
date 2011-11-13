<?php

/**
 * @file
 * "Kyrgyzstan" specific data
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
function addresses_province_list_kg() {
  return array(
    'GB' => t('Bishkek'),
    'B' => t('Batken'),
    'C' => t('Chu'),
    'J' => t('Jalal-Abad'),
    'N' => t('Naryn'),
    'O' => t('Osh'),
    'T' => t('Talas'),
    'Y' => t('Ysyk-Kol')
  );
}
