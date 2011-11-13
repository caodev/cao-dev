<?php

/**
 * @file
 * "Tunisia" specific data
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
function addresses_province_list_tn() {
  return array(
    'AR' => t('Ariana'),
    'BJ' => t('Beja'),
    'BA' => t('Ben Arous'),
    'BI' => t('Bizerte'),
    'GB' => t('Gabes'),
    'GF' => t('Gafsa'),
    'JE' => t('Jendouba'),
    'KR' => t('Kairouan'),
    'KS' => t('Kasserine'),
    'KB' => t('Kebili'),
    'KF' => t('Kef'),
    'MH' => t('Mahdia'),
    'MN' => t('Manouba'),
    'ME' => t('Medenine'),
    'MO' => t('Monastir'),
    'NA' => t('Nabeul'),
    'SF' => t('Sfax'),
    'SD' => t('Sidi'),
    'SL' => t('Siliana'),
    'SO' => t('Sousse'),
    'TA' => t('Tataouine'),
    'TO' => t('Tozeur'),
    'TU' => t('Tunis'),
    'ZA' => t('Zaghouan')
  );
}
