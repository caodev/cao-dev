<?php

/**
 * @file
 * "Congo, The Democratic Republic of the" specific data
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
function addresses_province_list_cd() {
  return array(
    'BC' => t('Bas-Congo'),
    'BN' => t('Bandundu'),
    'EQ' => t('Equateur'),
    'KA' => t('Katanga'),
    'KE' => t('Kasai-Oriental'),
    'KN' => t('Kinshasa'),
    'KW' => t('Kasai-Occidental'),
    'MA' => t('Maniema'),
    'NK' => t('Nord-Kivu'),
    'OR' => t('Orientale'),
    'SK' => t('Sud-Kivu')
  );
}
