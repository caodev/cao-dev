<?php

/**
 * @file
 * "Slovakia" specific data
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
function addresses_province_list_sk() {
  return array(
    'BA' => t('Banskobystricky'),
    'BR' => t('Bratislavsky'),
    'KO' => t('Kosicky'),
    'NI' => t('Nitriansky'),
    'PR' => t('Presovsky'),
    'TC' => t('Trenciansky'),
    'TV' => t('Trnavsky'),
    'ZI' => t('Zilinsky')
  );
}
