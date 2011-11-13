<?php

/**
 * @file
 * "Togo" specific data
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
function addresses_province_list_tg() {
  return array(
    'K' => t('Kara'),
    'P' => t('Plateaux'),
    'S' => t('Savanes'),
    'C' => t('Centrale'),
    'M' => t('Maritime')
  );
}
