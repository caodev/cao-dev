<?php

/**
 * @file
 * "Finland" specific data
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
function addresses_province_list_fi() {
  return array(
    'ES' => t('Etela-Suomen laani'),
    'LS' => t('Lansi-Suomen laani'),
    'IS' => t('Ita-Suomen laani'),
    'OU' => t('Oulun laani'),
    'LL' => t('Lapin laani'),
    'AH' => t('Ahvenanmaan laani')
  );
}
