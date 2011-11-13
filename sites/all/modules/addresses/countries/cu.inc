<?php

/**
 * @file
 * "Cuba" specific data
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
function addresses_province_list_cu() {
  return array(
    'IJU' => t('Isla de la Juventud'),
    'PRI' => t('Pinar del Rio'),
    'LHA' => t('La Habana'),
    'CLH' => t('Ciudad de La Habana'),
    'MAT' => t('Matanzas'),
    'CFU' => t('Cienfuegos'),
    'VCL' => t('Villa Clara'),
    'SSP' => t('Sancti Spiritus'),
    'CAV' => t('Ciego de Avila'),
    'CAM' => t('Camaguey'),
    'LTU' => t('Las Tunas'),
    'GRA' => t('Granma'),
    'HOL' => t('Holguin'),
    'SCU' => t('Santiago de Cuba'),
    'GUA' => t('Guantanamo')
  );
}
