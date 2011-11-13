<?php

/**
 * @file
 * "Poland" specific data
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
function addresses_province_list_pl() {
  return array(
    'DO' => t('Dolnoslaskie'),
    'KP' => t('Kujawsko-Pomorskie'),
    'LO' => t('Lodzkie'),
    'LL' => t('Lubelskie'),
    'LU' => t('Lubuskie'),
    'ML' => t('Malopolskie'),
    'MZ' => t('Mazowieckie'),
    'OP' => t('Opolskie'),
    'PP' => t('Podkarpackie'),
    'PL' => t('Podlaskie'),
    'PM' => t('Pomorskie'),
    'SL' => t('Slaskie'),
    'SW' => t('Swietokrzyskie'),
    'WM' => t('Warminsko-Mazurskie'),
    'WP' => t('Wielkopolskie'),
    'ZA' => t('Zachodniopomorskie')
  );
}
