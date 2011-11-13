<?php

/**
 * @file
 * "Benin" specific data
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
function addresses_province_list_bj() {
  return array(
    'AL' => t('Alibori'),
    'AK' => t('Atakora'),
    'AQ' => t('Atlantique'),
    'BO' => t('Borgou'),
    'CO' => t('Collines'),
    'DO' => t('Donga'),
    'KO' => t('Kouffo'),
    'LI' => t('Littoral'),
    'MO' => t('Mono'),
    'OU' => t('Oueme'),
    'PL' => t('Plateau'),
    'ZO' => t('Zou')
  );
}
