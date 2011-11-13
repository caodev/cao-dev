<?php

/**
 * @file
 * "Grenada" specific data
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
function addresses_province_list_gd() {
  return array(
    'A' => t('Saint Andrew'),
    'D' => t('Saint David'),
    'G' => t('Saint George'),
    'J' => t('Saint John'),
    'M' => t('Saint Mark'),
    'P' => t('Saint Patrick'),
    'C' => t('Carriacou'),
    'Q' => t('Petit Martinique')
  );
}
