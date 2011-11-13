<?php

/**
 * @file
 * "Tanzania, United Republic of" specific data
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
function addresses_province_list_tz() {
  return array(
    'AR' => t('Arusha'),
    'DS' => t('Dar es Salaam'),
    'DO' => t('Dodoma'),
    'IR' => t('Iringa'),
    'KA' => t('Kagera'),
    'KI' => t('Kigoma'),
    'KJ' => t('Kilimanjaro'),
    'LN' => t('Lindi'),
    'MY' => t('Manyara'),
    'MR' => t('Mara'),
    'MB' => t('Mbeya'),
    'MO' => t('Morogoro'),
    'MT' => t('Mtwara'),
    'MW' => t('Mwanza'),
    'PN' => t('Pemba North'),
    'PS' => t('Pemba South'),
    'PW' => t('Pwani'),
    'RK' => t('Rukwa'),
    'RV' => t('Ruvuma'),
    'SH' => t('Shinyanga'),
    'SI' => t('Singida'),
    'TB' => t('Tabora'),
    'TN' => t('Tanga'),
    'ZC' => t('Zanzibar Central/South'),
    'ZN' => t('Zanzibar North'),
    'ZU' => t('Zanzibar Urban/West')
  );
}
