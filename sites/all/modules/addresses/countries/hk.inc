<?php

/**
 * @file
 * "Hong Kong" specific data
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
function addresses_province_list_hk() {
  return array(
    'HCW' => t('Central and Western Hong Kong Island'),
    'HEA' => t('Eastern Hong Kong Island'),
    'HSO' => t('Southern Hong Kong Island'),
    'HWC' => t('Wan Chai Hong Kong Island'),
    'KKC' => t('Kowloon City Kowloon'),
    'KKT' => t('Kwun Tong Kowloon'),
    'KSS' => t('Sham Shui Po Kowloon'),
    'KWT' => t('Wong Tai Sin Kowloon'),
    'KYT' => t('Yau Tsim Mong Kowloon'),
    'NIS' => t('Islands New Territories'),
    'NKT' => t('Kwai Tsing New Territories'),
    'NNO' => t('North New Territories'),
    'NSK' => t('Sai Kung New Territories'),
    'NST' => t('Sha Tin New Territories'),
    'NTP' => t('Tai Po New Territories'),
    'NTW' => t('Tsuen Wan New Territories'),
    'NTM' => t('Tuen Mun New Territories'),
    'NYL' => t('Yuen Long New Territories')
  );
}
