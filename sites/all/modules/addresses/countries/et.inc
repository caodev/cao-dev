<?php

/**
 * @file
 * "Ethiopia" specific data
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
function addresses_province_list_et() {
  return array(
    'AF' => t('Afar'),
    'AH' => t('Amhara'),
    'BG' => t('Benishangul-Gumaz'),
    'GB' => t('Gambela'),
    'HR' => t('Hariai'),
    'OR' => t('Oromia'),
    'SM' => t('Somali'),
    'SN' => t('Southern Nations - Nationalities and Peoples Region'),
    'TG' => t('Tigray'),
    'AA' => t('Addis Ababa'),
    'DD' => t('Dire Dawa')
  );
}
