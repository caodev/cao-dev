<?php

/**
 * @file
 * "Bolivia" specific data
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
function addresses_province_list_bo() {
  return array(
    'BEN' => t('Departmento Beni'),
    'CHU' => t('Departmento Chuquisaca'),
    'COC' => t('Departmento Cochabamba'),
    'LPZ' => t('Departmento La Paz'),
    'ORU' => t('Departmento Oruro'),
    'PAN' => t('Departmento Pando'),
    'POT' => t('Departmento Potosi'),
    'SCZ' => t('Departmento Santa Cruz'),
    'TAR' => t('Departmento Tarija')
  );
}
