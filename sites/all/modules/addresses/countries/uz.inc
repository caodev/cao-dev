<?php

/**
 * @file
 * "Uzbekistan" specific data
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
function addresses_province_list_uz() {
  return array(
    'AN' => t('Andijon'),
    'BU' => t('Buxoro'),
    'FA' => t("Farg'ona"),
    'JI' => t('Jizzax'),
    'NG' => t('Namangan'),
    'NW' => t('Navoiy'),
    'QA' => t('Qashqadaryo'),
    'QR' => t("Qoraqalpog'iston Republikasi"),
    'SA' => t('Samarqand'),
    'SI' => t('Sirdaryo'),
    'SU' => t('Surxondaryo'),
    'TK' => t('Toshkent city'),
    'TO' => t('Toshkent region'),
    'XO' => t('Xorazm')
  );
}
