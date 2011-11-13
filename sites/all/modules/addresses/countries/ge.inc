<?php

/**
 * @file
 * "Georgia" specific data
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
function addresses_province_list_ge() {
  return array(
    'AB' => t('Abkhazia'),
    'AJ' => t('Ajaria'),
    'TB' => t('Tbilisi'),
    'GU' => t('Guria'),
    'IM' => t('Imereti'),
    'KA' => t('Kakheti'),
    'KK' => t('Kvemo Kartli'),
    'MM' => t('Mtskheta-Mtianeti'),
    'RL' => t('Racha Lechkhumi and Kvemo Svaneti'),
    'SZ' => t('Samegrelo-Zemo Svaneti'),
    'SJ' => t('Samtskhe-Javakheti'),
    'SK' => t('Shida Kartli')
  );
}
