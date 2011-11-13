<?php

/**
 * @file
 * "Syrian Arab Republic" specific data
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
function addresses_province_list_sy() {
  return array(
    'HA' => t('Al Hasakah'),
    'LA' => t('Al Ladhiqiyah'),
    'QU' => t('Al Qunaytirah'),
    'RQ' => t('Ar Raqqah'),
    'SU' => t('As Suwayda'),
    'DA' => t('Dara'),
    'DZ' => t('Dayr az Zawr'),
    'DI' => t('Dimashq'),
    'HL' => t('Halab'),
    'HM' => t('Hamah'),
    'HI' => t('Hims'),
    'ID' => t('Idlib'),
    'RD' => t('Rif Dimashq'),
    'TA' => t('Tartus')
  );
}
