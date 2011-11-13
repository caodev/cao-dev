<?php

/**
 * @file
 * "Belize" specific data
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
function addresses_province_list_bz() {
  return array(
    'BZ' => t('Belize District'),
    'CY' => t('Cayo District'),
    'CR' => t('Corozal District'),
    'OW' => t('Orange Walk District'),
    'SC' => t('Stann Creek District'),
    'TO' => t('Toledo District')
  );
}
