<?php

/**
 * @file
 * "Bahrain" specific data
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
function addresses_province_list_bh() {
  return array(
    'CAP' => t('Capital'),
    'CEN' => t('Central'),
    'MUH' => t('Muharraq'),
    'NOR' => t('Northern'),
    'SOU' => t('Southern')
  );
}
