<?php

/**
 * @file
 * "Sweden" specific data
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
function addresses_province_list_se() {
  return array(
    'ST' => t('Stockholm'),
    'UP' => t('Uppsala'),
    'SO' => t('Södermanland'),
    'OG' => t('Östergotland'),
    'JO' => t('Jönköping'),
    'KR' => t('Kronoberg'),
    'KA' => t('Kalmar'),
    'GO' => t('Gotland'),
    'BL' => t('Blekinge'),
    'SK' => t('Skåne'),
    'HA' => t('Halland'),
    'VG' => t('Västra Götaland'),
    'VL' => t('Värmland'),
    'OR' => t('Örebro'),
    'VM' => t('Västmanland'),
    'DA' => t('Dalarna'),
    'GA' => t('Gävleborg'),
    'VN' => t('Västernorrland'),
    'JA' => t('Jämtland'),
    'VB' => t('Västerbotten'),
    'NO' => t('Norrbotten')
  );
}
