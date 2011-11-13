<?php

/**
 * @file
 * "Libyan Arab Jamahiriya" specific data
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
function addresses_province_list_ly() {
  return array(
    'AJ' => t('Ajdabiya'),
    'AZ' => t("Al 'Aziziyah"),
    'FA' => t('Al Fatih'),
    'JA' => t('Al Jabal al Akhdar'),
    'JU' => t('Al Jufrah'),
    'KH' => t('Al Khums'),
    'KU' => t('Al Kufrah'),
    'NK' => t('An Nuqat al Khams'),
    'AS' => t("Ash Shati'"),
    'AW' => t('Awbari'),
    'ZA' => t('Az Zawiyah'),
    'BA' => t('Banghazi'),
    'DA' => t('Darnah'),
    'GD' => t('Ghadamis'),
    'GY' => t('Gharyan'),
    'MI' => t('Misratah'),
    'MZ' => t('Murzuq'),
    'SB' => t('Sabha'),
    'SW' => t('Sawfajjin'),
    'SU' => t('Surt'),
    'TL' => t('Tarabulus (Tripoli)'),
    'TH' => t('Tarhunah'),
    'TU' => t('Tubruq'),
    'YA' => t('Yafran'),
    'ZL' => t('Zlitan')
  );
}
