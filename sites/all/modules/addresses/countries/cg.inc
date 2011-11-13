<?php

/**
 * @file
 * "Congo" specific data
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
function addresses_province_list_cg() {
  return array(
    'BO' => t('Bouenza'),
    'BR' => t('Brazzaville'),
    'CU' => t('Cuvette'),
    'CO' => t('Cuvette-Ouest'),
    'KO' => t('Kouilou'),
    'LE' => t('Lekoumou'),
    'LI' => t('Likouala'),
    'NI' => t('Niari'),
    'PL' => t('Plateaux'),
    'PO' => t('Pool'),
    'SA' => t('Sangha')
  );
}
