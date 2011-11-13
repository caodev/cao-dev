<?php

/**
 * @file
 * "Kazakhstan" specific data
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
function addresses_province_list_kz() {
  return array(
    'ALA' => t('Almaty'),
    'AST' => t('Astana'),
    'ALM' => t('Almaty'),
    'AKM' => t('Aqmola'),
    'AKT' => t('Aqtobe'),
    'ATY' => t('Atyrau'),
    'ZAP' => t('Baty Qazaqstan'),
    'MAN' => t('Mangghystau'),
    'YUZ' => t('Ongtustik Qazaqstan'),
    'PAV' => t('Paylodar'),
    'KAR' => t('Qaraghandy'),
    'KUS' => t('Qustanay'),
    'KZY' => t('Qyzylorda'),
    'VOS' => t('Shyghys Qazaqstan'),
    'SEV' => t('Soltustik Qazaqstan'),
    'ZHA' => t('Zhambyl')
  );
}
