<?php

/**
 * @file
 * "Oman" specific data
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
function addresses_province_list_om() {
  return array(
    'DA' => t('Ad Dakhiliyah'),
    'BA' => t('Al Batinah'),
    'WU' => t('Al Wusta'),
    'SH' => t('Ash Sharqiyah'),
    'ZA' => t('Az Zahirah'),
    'MA' => t('Masqat'),
    'MU' => t('Musandam'),
    'ZU' => t('Zufar')
  );
}
