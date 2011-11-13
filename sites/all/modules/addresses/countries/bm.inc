<?php

/**
 * @file
 * "Bermuda" specific data
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
function addresses_province_list_bm() {
  return array(
    'DS' => t('Devonshire'),
    'HC' => t('Hamilton City'),
    'HA' => t('Hamilton'),
    'PG' => t('Paget'),
    'PB' => t('Pembroke'),
    'GC' => t('Saint George City'),
    'SG' => t("Saint George's"),
    'SA' => t('Sandys'),
    'SM' => t("Smith's"),
    'SH' => t('Southampton'),
    'WA' => t('Warwick')
  );
}
