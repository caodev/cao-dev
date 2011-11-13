<?php

/**
 * @file
 * "Uruguay" specific data
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
function addresses_province_list_uy() {
  return array(
    'AR' => t('Artigas'),
    'CA' => t('Canelones'),
    'CL' => t('Cerro Largo'),
    'CO' => t('Colonia'),
    'DU' => t('Durazno'),
    'FS' => t('Flores'),
    'FA' => t('Florida'),
    'LA' => t('Lavalleja'),
    'MA' => t('Maldonado'),
    'MO' => t('Montevideo'),
    'PA' => t('Paysandu'),
    'RN' => t('Rio Negro'),
    'RV' => t('Rivera'),
    'RO' => t('Rocha'),
    'SL' => t('Salto'),
    'SO' => t('Soriano'),
    'SJ' => t('San Jose'),
    'TT' => t('Treinta y Tres')
  );
}
