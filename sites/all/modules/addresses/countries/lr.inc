<?php

/**
 * @file
 * "Liberia" specific data
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
function addresses_province_list_lr() {
  return array(
    'BI' => t('Bomi'),
    'BG' => t('Bong'),
    'GB' => t('Grand Bassa'),
    'CM' => t('Grand Cape Mount'),
    'GG' => t('Grand Gedeh'),
    'GK' => t('Grand Kru'),
    'LO' => t('Lofa'),
    'MG' => t('Margibi'),
    'ML' => t('Maryland'),
    'MS' => t('Montserrado'),
    'NB' => t('Nimba'),
    'RC' => t('River Cess'),
    'SN' => t('Sinoe')
  );
}
