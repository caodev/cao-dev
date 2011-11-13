<?php

/**
 * @file
 * "Iraq" specific data
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
function addresses_province_list_iq() {
  return array(
    'BD' => t('Baghdad'),
    'SD' => t('Salah ad Din'),
    'DY' => t('Diyala'),
    'WS' => t('Wasit'),
    'MY' => t('Maysan'),
    'BA' => t('Al Basrah'),
    'DQ' => t('Dhi Qar'),
    'MU' => t('Al Muthanna'),
    'QA' => t('Al Qadisyah'),
    'BB' => t('Babil'),
    'KB' => t('Al Karbala'),
    'NJ' => t('An Najaf'),
    'AB' => t('Al Anbar'),
    'NN' => t('Ninawa'),
    'DH' => t('Dahuk'),
    'AL' => t('Arbil'),
    'TM' => t("At Ta'mim"),
    'SL' => t('As Sulaymaniyah')
  );
}
