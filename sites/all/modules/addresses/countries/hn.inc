<?php

/**
 * @file
 * "Honduras" specific data
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
function addresses_province_list_hn() {
  return array(
    'AT' => t('Atlantida'),
    'CH' => t('Choluteca'),
    'CL' => t('Colon'),
    'CM' => t('Comayagua'),
    'CP' => t('Copan'),
    'CR' => t('Cortes'),
    'PA' => t('El Paraiso'),
    'FM' => t('Francisco Morazan'),
    'GD' => t('Gracias a Dios'),
    'IN' => t('Intibuca'),
    'IB' => t('Islas de la Bahia (Bay Islands)'),
    'PZ' => t('La Paz'),
    'LE' => t('Lempira'),
    'OC' => t('Ocotepeque'),
    'OL' => t('Olancho'),
    'SB' => t('Santa Barbara'),
    'VA' => t('Valle'),
    'YO' => t('Yoro')
  );
}
