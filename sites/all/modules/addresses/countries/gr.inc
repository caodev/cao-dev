<?php

/**
 * @file
 * "Greece" specific data
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
function addresses_province_list_gr() {
  return array(
    'AT' => t('Attica'),
    'CN' => t('Central Greece'),
    'CM' => t('Central Macedonia'),
    'CR' => t('Crete'),
    'EM' => t('East Macedonia and Thrace'),
    'EP' => t('Epirus'),
    'II' => t('Ionian Islands'),
    'NA' => t('North Aegean'),
    'PP' => t('Peloponnesos'),
    'SA' => t('South Aegean'),
    'TH' => t('Thessaly'),
    'WG' => t('West Greece'),
    'WM' => t('West Macedonia')
  );
}
