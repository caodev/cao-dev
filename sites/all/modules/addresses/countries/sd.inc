<?php

/**
 * @file
 * "Sudan" specific data
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
function addresses_province_list_sd() {
  return array(
    'ANL' => t("A'ali an Nil"),
    'BAM' => t('Al Bahr al Ahmar'),
    'BRT' => t('Al Buhayrat'),
    'JZR' => t('Al Jazirah'),
    'KRT' => t('Al Khartum'),
    'QDR' => t('Al Qadarif'),
    'WDH' => t('Al Wahdah'),
    'ANB' => t('An Nil al Abyad'),
    'ANZ' => t('An Nil al Azraq'),
    'ASH' => t('Ash Shamaliyah'),
    'BJA' => t('Bahr al Jabal'),
    'GIS' => t("Gharb al Istiwa'iyah"),
    'GBG' => t('Gharb Bahr al Ghazal'),
    'GDA' => t('Gharb Darfur'),
    'GKU' => t('Gharb Kurdufan'),
    'JDA' => t('Janub Darfur'),
    'JKU' => t('Janub Kurdufan'),
    'JQL' => t('Junqali'),
    'KSL' => t('Kassala'),
    'NNL' => t('Nahr an Nil'),
    'SBG' => t('Shamal Bahr al Ghazal'),
    'SDA' => t('Shamal Darfur'),
    'SKU' => t('Shamal Kurdufan'),
    'SIS' => t("Sharq al Istiwa'iyah"),
    'SNR' => t('Sinnar'),
    'WRB' => t('Warab')
  );
}
