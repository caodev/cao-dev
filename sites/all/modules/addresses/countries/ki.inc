<?php

/**
 * @file
 * "Kiribati" specific data
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
function addresses_province_list_ki() {
  return array(
    'AG' => t('Abaiang'),
    'AM' => t('Abemama'),
    'AK' => t('Aranuka'),
    'AO' => t('Arorae'),
    'BA' => t('Banaba'),
    'BE' => t('Beru'),
    'bT' => t('Butaritari'),
    'KA' => t('Kanton'),
    'KR' => t('Kiritimati'),
    'KU' => t('Kuria'),
    'MI' => t('Maiana'),
    'MN' => t('Makin'),
    'ME' => t('Marakei'),
    'NI' => t('Nikunau'),
    'NO' => t('Nonouti'),
    'ON' => t('Onotoa'),
    'TT' => t('Tabiteuea'),
    'TR' => t('Tabuaeran'),
    'TM' => t('Tamana'),
    'TW' => t('Tarawa'),
    'TE' => t('Teraina')
  );
}
