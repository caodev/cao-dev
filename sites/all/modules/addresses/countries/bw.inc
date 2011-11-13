<?php

/**
 * @file
 * "Botswana" specific data
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
function addresses_province_list_bw() {
  return array(
    'CE' => t('Central'),
    'GH' => t('Ghanzi'),
    'KD' => t('Kgalagadi'),
    'KT' => t('Kgatleng'),
    'KW' => t('Kweneng'),
    'NG' => t('Ngamiland'),
    'NE' => t('North East'),
    'NW' => t('North West'),
    'SE' => t('South East'),
    'SO' => t('Southern')
  );
}
