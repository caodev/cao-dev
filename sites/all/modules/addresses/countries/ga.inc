<?php

/**
 * @file
 * "Gabon" specific data
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
function addresses_province_list_ga() {
  return array(
    'ES' => t('Estuaire'),
    'HO' => t('Haut-Ogooue'),
    'MO' => t('Moyen-Ogooue'),
    'NG' => t('Ngounie'),
    'NY' => t('Nyanga'),
    'OI' => t('Ogooue-Ivindo'),
    'OL' => t('Ogooue-Lolo'),
    'OM' => t('Ogooue-Maritime'),
    'WN' => t('Woleu-Ntem')
  );
}
