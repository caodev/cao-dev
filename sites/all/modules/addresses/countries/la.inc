<?php

/**
 * @file
 * "Lao People's Democratic Republic" specific data
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
function addresses_province_list_la() {
  return array(
    'VT' => t('Vientiane'),
    'AT' => t('Attapu'),
    'BK' => t('Bokeo'),
    'BL' => t('Bolikhamxai'),
    'CH' => t('Champasak'),
    'HO' => t('Houaphan'),
    'KH' => t('Khammouan'),
    'LM' => t('Louang Namtha'),
    'LP' => t('Louangphabang'),
    'OU' => t('Oudomxai'),
    'PH' => t('Phongsali'),
    'SL' => t('Salavan'),
    'SV' => t('Savannakhet'),
    'VI' => t('Vientiane'),
    'XA' => t('Xaignabouli'),
    'XE' => t('Xekong'),
    'XI' => t('Xiangkhoang'),
    'XN' => t('Xaisomboun')
  );
}
