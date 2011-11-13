<?php

/**
 * @file
 * "Saudia Arabia" specific data
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
function addresses_province_list_sa() {
  return array(
    'BH' => t('Al Bahah'),
    'HS' => t('Al Hudud ash Shamaliyah'),
    'JF' => t('Al Jawf'),
    'MD' => t('Al Madinah'),
    'QS' => t('Al Qasim'),
    'RD' => t('Ar Riyad'),
    'AQ' => t('Ash Sharqiyah (Eastern Province)'),
    'AS' => t("'Asir"),
    'HL' => t("Ha'il"),
    'JZ' => t('Jizan'),
    'ML' => t('Makkah'),
    'NR' => t('Najran'),
    'TB' => t('Tabuk')
  );
}
