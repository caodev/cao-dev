<?php

/**
 * @file
 * "Iran, Islamic Republic Of" specific data
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
function addresses_province_list_ir() {
  return array(
    'TEH' => t('Tehran'),
    'QOM' => t('Qom'),
    'MKZ' => t('Markazi'),
    'QAZ' => t('Qazvin'),
    'GIL' => t('Gilan'),
    'ARD' => t('Ardabil'),
    'ZAN' => t('Zanjan'),
    'EAZ' => t('East Azarbaijan'),
    'WEZ' => t('West Azarbaijan'),
    'KRD' => t('Kurdistan'),
    'HMD' => t('Hamadan'),
    'KRM' => t('Kermanshah'),
    'ILM' => t('Ilam'),
    'LRS' => t('Lorestan'),
    'KZT' => t('Khuzestan'),
    'CMB' => t('Chahar Mahaal and Bakhtiari'),
    'KBA' => t('Kohkiluyeh and Buyer Ahmad'),
    'BSH' => t('Bushehr'),
    'FAR' => t('Fars'),
    'HRM' => t('Hormozgan'),
    'SBL' => t('Sistan and Baluchistan'),
    'KRB' => t('Kerman'),
    'YZD' => t('Yazd'),
    'EFH' => t('Esfahan'),
    'SMN' => t('Semnan'),
    'MZD' => t('Mazandaran'),
    'GLS' => t('Golestan'),
    'NKH' => t('North Khorasan'),
    'RKH' => t('Razavi Khorasan'),
    'SKH' => t('South Khorasan')
  );
}
