<?php

/**
 * @file
 * "Trinidad and Tobago" specific data
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
function addresses_province_list_tt() {
  return array(
    'CT' => t('Couva/Tabaquite/Talparo'),
    'DM' => t('Diego Martin'),
    'MR' => t('Mayaro/Rio Claro'),
    'PD' => t('Penal/Debe'),
    'PT' => t('Princes Town'),
    'SG' => t('Sangre Grande'),
    'SL' => t('San Juan/Laventille'),
    'SI' => t('Siparia'),
    'TP' => t('Tunapuna/Piarco'),
    'PS' => t('Port of Spain'),
    'SF' => t('San Fernando'),
    'AR' => t('Arima'),
    'PF' => t('Point Fortin'),
    'CH' => t('Chaguanas'),
    'TO' => t('Tobago')
  );
}
