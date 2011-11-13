<?php

/**
 * @file
 * "Marshall Islands" specific data
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
function addresses_province_list_mh() {
  return array(
    'ALG' => t('Ailinginae'),
    'ALL' => t('Ailinglaplap'),
    'ALK' => t('Ailuk'),
    'ARN' => t('Arno'),
    'AUR' => t('Aur'),
    'BKR' => t('Bikar'),
    'BKN' => t('Bikini'),
    'BKK' => t('Bokak'),
    'EBN' => t('Ebon'),
    'ENT' => t('Enewetak'),
    'EKB' => t('Erikub'),
    'JBT' => t('Jabat'),
    'JLT' => t('Jaluit'),
    'JEM' => t('Jemo'),
    'KIL' => t('Kili'),
    'KWJ' => t('Kwajalein'),
    'LAE' => t('Lae'),
    'LIB' => t('Lib'),
    'LKP' => t('Likiep'),
    'MJR' => t('Majuro'),
    'MLP' => t('Maloelap'),
    'MJT' => t('Mejit'),
    'MIL' => t('Mili'),
    'NMK' => t('Namorik'),
    'NAM' => t('Namu'),
    'RGL' => t('Rongelap'),
    'RGK' => t('Rongrik'),
    'TOK' => t('Toke'),
    'UJA' => t('Ujae'),
    'UJL' => t('Ujelang'),
    'UTK' => t('Utirik'),
    'WTH' => t('Wotho'),
    'WTJ' => t('Wotje')
  );
}
