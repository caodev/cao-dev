<?php

/**
 * @file
 * "Namibia" specific data
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
function addresses_province_list_na() {
  return array(
    'CA' => t('Caprivi'),
    'ER' => t('Erongo'),
    'HA' => t('Hardap'),
    'KR' => t('Karas'),
    'KV' => t('Kavango'),
    'KH' => t('Khomas'),
    'KU' => t('Kunene'),
    'OW' => t('Ohangwena'),
    'OK' => t('Omaheke'),
    'OT' => t('Omusati'),
    'ON' => t('Oshana'),
    'OO' => t('Oshikoto'),
    'OJ' => t('Otjozondjupa')
  );
}
