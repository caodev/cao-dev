<?php

/**
 * @file
 * "Moldova, Republic of" specific data
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
function addresses_province_list_md() {
  return array(
    'GA' => t('Gagauzia'),
    'CU' => t('Chisinau'),
    'BA' => t('Balti'),
    'CA' => t('Cahul'),
    'ED' => t('Edinet'),
    'LA' => t('Lapusna'),
    'OR' => t('Orhei'),
    'SO' => t('Soroca'),
    'TI' => t('Tighina'),
    'UN' => t('Ungheni'),
    'SN' => t('Stînga Nistrului')
  );
}
