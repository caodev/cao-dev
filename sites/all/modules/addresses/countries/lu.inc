<?php

/**
 * @file
 * "Luxembourg" specific data
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
function addresses_province_list_lu() {
  return array(
    'DD' => t('Diekirch'),
    'DC' => t('Clervaux'),
    'DR' => t('Redange'),
    'DV' => t('Vianden'),
    'DW' => t('Wiltz'),
    'GG' => t('Grevenmacher'),
    'GE' => t('Echternach'),
    'GR' => t('Remich'),
    'LL' => t('Luxembourg'),
    'LC' => t('Capellen'),
    'LE' => t('Esch-sur-Alzette'),
    'LM' => t('Mersch')
  );
}
