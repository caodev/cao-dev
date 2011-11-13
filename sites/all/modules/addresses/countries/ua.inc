<?php

/**
 * @file
 * "Ukraine" specific data
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
function addresses_province_list_ua() {
  return array(
    'CK' => t('Cherkasy'),
    'CH' => t('Chernihiv'),
    'CV' => t('Chernivtsi'),
    'CR' => t('Crimea'),
    'DN' => t("Dnipropetrovs'k"),
    'DO' => t("Donets'k"),
    'IV' => t("Ivano-Frankivs'k"),
    'KL' => t('Kharkiv Kherson'),
    'KM' => t("Khmel'nyts'kyy"),
    'KR' => t('Kirovohrad'),
    'KV' => t('Kiev'),
    'KY' => t('Kyyiv'),
    'LU' => t("Luhans'k"),
    'LV' => t("L'viv"),
    'MY' => t('Mykolayiv'),
    'OD' => t('Odesa'),
    'PO' => t('Poltava'),
    'RI' => t('Rivne'),
    'SE' => t('Sevastopol'),
    'SU' => t('Sumy'),
    'TE' => t("Ternopil'"),
    'VI' => t('Vinnytsya'),
    'VO' => t("Volyn'"),
    'ZK' => t('Zakarpattya'),
    'ZA' => t('Zaporizhzhya'),
    'ZH' => t('Zhytomyr')
  );
}
