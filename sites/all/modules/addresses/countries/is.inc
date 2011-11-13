<?php

/**
 * @file
 * "Iceland" specific data
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
function addresses_province_list_is() {
  return array(
    'AL' => t('Austurland'),
    'HF' => t('Hofuoborgarsvaeoi'),
    'NE' => t('Norourland eystra'),
    'NV' => t('Norourland vestra'),
    'SL' => t('Suourland'),
    'SN' => t('Suournes'),
    'VF' => t('Vestfiroir'),
    'VL' => t('Vesturland')
  );
}
