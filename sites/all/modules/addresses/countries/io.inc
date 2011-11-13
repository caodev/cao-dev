<?php

/**
 * @file
 * "British Indian Ocean Territory" specific data
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
function addresses_province_list_io() {
  return array(
    'PB' => t('Peros Banhos'),
    'SI' => t('Salomon Islands'),
    'NI' => t('Nelsons Island'),
    'TB' => t('Three Brothers'),
    'EA' => t('Eagle Islands'),
    'DI' => t('Danger Island'),
    'EG' => t('Egmont Islands'),
    'DG' => t('Diego Garcia')
  );
}
