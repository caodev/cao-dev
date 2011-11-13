<?php

/**
 * @file
 * "Jamaica" specific data
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
function addresses_province_list_jm() {
  return array(
    'CLA' => t('Clarendon Parish'),
    'HAN' => t('Hanover Parish'),
    'KIN' => t('Kingston Parish'),
    'MAN' => t('Manchester Parish'),
    'POR' => t('Portland Parish'),
    'AND' => t('Saint Andrew Parish'),
    'ANN' => t('Saint Ann Parish'),
    'CAT' => t('Saint Catherine Parish'),
    'ELI' => t('Saint Elizabeth Parish'),
    'JAM' => t('Saint James Parish'),
    'MAR' => t('Saint Mary Parish'),
    'THO' => t('Saint Thomas Parish'),
    'TRL' => t('Trelawny Parish'),
    'WML' => t('Westmoreland Parish')
  );
}
