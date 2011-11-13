<?php

/**
 * @file
 * "Mauritius" specific data
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
function addresses_province_list_mu() {
  return array(
    'BR' => t('Beau Bassin-Rose Hill'),
    'CU' => t('Curepipe'),
    'PU' => t('Port Louis'),
    'QB' => t('Quatre Bornes'),
    'VP' => t('Vacoas-Phoenix'),
    'AG' => t('Agalega Islands'),
    'CC' => t('Cargados Carajos Shoals (Saint Brandon Islands)'),
    'RO' => t('Rodrigues'),
    'BL' => t('Black River'),
    'FL' => t('Flacq'),
    'GP' => t('Grand Port'),
    'MO' => t('Moka'),
    'PA' => t('Pamplemousses'),
    'PW' => t('Plaines Wilhems'),
    'PL' => t('Port Louis'),
    'RR' => t('Riviere du Rempart'),
    'SA' => t('Savanne')
  );
}
