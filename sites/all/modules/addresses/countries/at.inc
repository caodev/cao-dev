<?php

/**
 * @file
 * "Austria" specific data
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
function addresses_province_list_at() {
  return array(
    'BUR' => t('Burgenland'),
    'KAR' => t('Karnten'),
    'NOS' => t('Niederosterreich'),
    'OOS' => t('Oberosterreich'),
    'SAL' => t('Salzburg'),
    'STE' => t('Steiermark'),
    'TIR' => t('Tirol'),
    'VOR' => t('Vorarlberg'),
    'WIE' => t('Wien')
  );
}
