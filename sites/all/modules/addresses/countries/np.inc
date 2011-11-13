<?php

/**
 * @file
 * "Nepal" specific data
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
function addresses_province_list_np() {
  return array(
    'BA' => t('Bagmati'),
    'BH' => t('Bheri'),
    'DH' => t('Dhawalagiri'),
    'GA' => t('Gandaki'),
    'JA' => t('Janakpur'),
    'KA' => t('Karnali'),
    'KO' => t('Kosi'),
    'LU' => t('Lumbini'),
    'MA' => t('Mahakali'),
    'ME' => t('Mechi'),
    'NA' => t('Narayani'),
    'RA' => t('Rapti'),
    'SA' => t('Sagarmatha'),
    'SE' => t('Seti')
  );
}
