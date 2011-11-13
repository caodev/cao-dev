<?php

/**
 * @file
 * "Madagascar" specific data
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
function addresses_province_list_mg() {
  return array(
    'AN' => t('Antananarivo province'),
    'AS' => t('Antsiranana province'),
    'FN' => t('Fianarantsoa province'),
    'MJ' => t('Mahajanga province'),
    'TM' => t('Toamasina province'),
    'TL' => t('Toliara province')
  );
}
