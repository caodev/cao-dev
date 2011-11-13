<?php

/**
 * @file
 * "Lesotho" specific data
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
function addresses_province_list_ls() {
  return array(
    'BE' => t('Berea'),
    'BB' => t('Butha-Buthe'),
    'LE' => t('Leribe'),
    'MF' => t('Mafeteng'),
    'MS' => t('Maseru'),
    'MH' => t("Mohale's Hoek"),
    'MK' => t('Mokhotlong'),
    'QN' => t("Qacha's Nek"),
    'QT' => t('Quthing'),
    'TT' => t('Thaba-Tseka')
  );
}
