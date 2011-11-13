<?php

/**
 * @file
 * "Mozambique" specific data
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
function addresses_province_list_mz() {
  return array(
    'CD' => t('Cabo Delgado'),
    'GZ' => t('Gaza'),
    'IN' => t('Inhambane'),
    'MN' => t('Manica'),
    'MC' => t('Maputo (city)'),
    'MP' => t('Maputo'),
    'NA' => t('Nampula'),
    'NI' => t('Niassa'),
    'SO' => t('Sofala'),
    'TE' => t('Tete'),
    'ZA' => t('Zambezia')
  );
}
