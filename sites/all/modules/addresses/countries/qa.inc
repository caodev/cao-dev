<?php

/**
 * @file
 * "Qatar" specific data
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
function addresses_province_list_qa() {
  return array(
    'DW' => t('Ad Dawhah'),
    'GW' => t('Al Ghuwayriyah'),
    'JM' => t('Al Jumayliyah'),
    'KR' => t('Al Khawr'),
    'WK' => t('Al Wakrah'),
    'RN' => t('Ar Rayyan'),
    'JB' => t('Jarayan al Batinah'),
    'MS' => t('Madinat ash Shamal'),
    'UD' => t("Umm Sa'id"),
    'UL' => t('Umm Salal')
  );
}
