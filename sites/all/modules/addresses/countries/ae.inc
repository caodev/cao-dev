<?php

/**
 * @file
 * "United Arab Emirates" specific data
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
function addresses_province_list_ae() {
  return array(
    'AZ' => t('Abu Zaby'),
    'AJ' => t("'Ajman"),
    'FU' => t('Al Fujayrah'),
    'SH' => t('Ash Shariqah'),
    'DU' => t('Dubayy'),
    'RK' => t("R'as al Khaymah"),
    'UQ' => t('Umm al Qaywayn')
  );
}
