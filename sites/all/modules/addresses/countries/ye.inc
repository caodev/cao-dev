<?php

/**
 * @file
 * "Yemen" specific data
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
function addresses_province_list_ye() {
  return array(
    'AB' => t('Abyan'),
    'AD' => t('Adan'),
    'AM' => t('Amran'),
    'BA' => t('Al Bayda'),
    'DA' => t('Ad Dali'),
    'DH' => t('Dhamar'),
    'HD' => t('Hadramawt'),
    'HJ' => t('Hajjah'),
    'HU' => t('Al Hudaydah'),
    'IB' => t('Ibb'),
    'JA' => t('Al Jawf'),
    'LA' => t('Lahij'),
    'MA' => t("Ma'rib"),
    'MR' => t('Al Mahrah'),
    'MW' => t('Al Mahwit'),
    'SD' => t("Sa'dah"),
    'SN' => t("San'a"),
    'SH' => t('Shabwah'),
    'TA' => t("Ta'izz")
  );
}
