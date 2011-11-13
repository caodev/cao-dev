<?php

/**
 * @file
 * "Cambodia" specific data
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
function addresses_province_list_kh() {
  return array(
    'PP' => t('Phnom Penh'),
    'PS' => t('Preah Seihanu (Kompong Som or Sihanoukville)'),
    'PA' => t('Pailin'),
    'KB' => t('Keb'),
    'BM' => t('Banteay Meanchey'),
    'BA' => t('Battambang'),
    'KM' => t('Kampong Cham'),
    'KN' => t('Kampong Chhnang'),
    'KU' => t('Kampong Speu'),
    'KO' => t('Kampong Som'),
    'KT' => t('Kampong Thom'),
    'KP' => t('Kampot'),
    'KL' => t('Kandal'),
    'KK' => t('Kaoh Kong'),
    'KR' => t('Kratie'),
    'MK' => t('Mondul Kiri'),
    'OM' => t('Oddar Meancheay'),
    'PU' => t('Pursat'),
    'PR' => t('Preah Vihear'),
    'PG' => t('Prey Veng'),
    'RK' => t('Ratanak Kiri'),
    'SI' => t('Siemreap'),
    'ST' => t('Stung Treng'),
    'SR' => t('Svay Rieng'),
    'TK' => t('Takeo')
  );
}
