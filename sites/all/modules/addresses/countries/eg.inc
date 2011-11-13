<?php

/**
 * @file
 * "Egypt" specific data
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
function addresses_province_list_eg() {
  return array(
    'DHY' => t('Ad Daqahliyah'),
    'BAM' => t('Al Bahr al Ahmar'),
    'BHY' => t('Al Buhayrah'),
    'FYM' => t('Al Fayyum'),
    'GBY' => t('Al Gharbiyah'),
    'IDR' => t('Al Iskandariyah'),
    'IML' => t("Al Isma'iliyah"),
    'JZH' => t('Al Jizah'),
    'MFY' => t('Al Minufiyah'),
    'MNY' => t('Al Minya'),
    'QHR' => t('Al Qahirah'),
    'QLY' => t('Al Qalyubiyah'),
    'WJD' => t('Al Wadi al Jadid'),
    'SHQ' => t('Ash Sharqiyah'),
    'SWY' => t('As Suways'),
    'ASW' => t('Aswan'),
    'ASY' => t('Asyut'),
    'BSW' => t('Bani Suwayf'),
    'BSD' => t("Bur Sa'id"),
    'DMY' => t('Dumyat'),
    'JNS' => t("Janub Sina'"),
    'KSH' => t('Kafr ash Shaykh'),
    'MAT' => t('Matruh'),
    'QIN' => t('Qina'),
    'SHS' => t("Shamal Sina'"),
    'SUH' => t('Suhaj')
  );
}
