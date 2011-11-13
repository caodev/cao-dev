<?php

/**
 * @file
 * "Belarus" specific data
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
function addresses_province_list_by() {
  return array(
    'BR' => t('Brest voblast'),
    'HO' => t('Homyel voblast'),
    'HR' => t('Hrodna voblast'),
    'MA' => t('Mahilyow voblast'),
    'MI' => t('Minsk voblast'),
    'VI' => t('Vitsebsk voblast')
  );
}
