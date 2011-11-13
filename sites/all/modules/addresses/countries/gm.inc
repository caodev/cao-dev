<?php

/**
 * @file
 * "Gambia" specific data
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
function addresses_province_list_gm() {
  return array(
    'BJ' => t('Banjul'),
    'BS' => t('Basse'),
    'BR' => t('Brikama'),
    'JA' => t('Janjangbure'),
    'KA' => t('Kanifeng'),
    'KE' => t('Kerewan'),
    'KU' => t('Kuntaur'),
    'MA' => t('Mansakonko'),
    'LR' => t('Lower River'),
    'CR' => t('Central River'),
    'NB' => t('North Bank'),
    'UR' => t('Upper River'),
    'WE' => t('Western')
  );
}
