<?php

/**
 * @file
 * "French Southern Territories" specific data
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
function addresses_province_list_tf() {
  return array(
    'C' => t('Iles Crozet'),
    'K' => t('Iles Kerguelen'),
    'A' => t('Ile Amsterdam'),
    'P' => t('Ile Saint-Paul'),
    'D' => t('Adelie Land')
  );
}
