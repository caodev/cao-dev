<?php

/**
 * @file
 * "Armenia" specific data
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
function addresses_province_list_am() {
  return array(
    'AGT' => t('Aragatsotn'),
    'ARR' => t('Ararat'),
    'ARM' => t('Armavir'),
    'GEG' => t("Geghark'unik'"),
    'KOT' => t("Kotayk'"),
    'LOR' => t('Lorri'),
    'SHI' => t('Shirak'),
    'SYU' => t("Syunik'"),
    'TAV' => t('Tavush'),
    'VAY' => t("Vayots' Dzor"),
    'YER' => t('Yerevan')
  );
}
