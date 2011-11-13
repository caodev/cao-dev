<?php

/**
 * @file
 * "Ireland" specific data
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
function addresses_province_list_ie() {
  return array(
    'DB' => t('Dublin'),
    'WK' => t('Wicklow'),
    'WX' => t('Wexford'),
    'CW' => t('Carlow'),
    'KD' => t('Kildare'),
    'MT' => t('Meath'),
    'LT' => t('Louth'),
    'MG' => t('Monaghan'),
    'CV' => t('Cavan'),
    'LF' => t('Longford'),
    'WM' => t('Westmeath'),
    'OF' => t('Offaly'),
    'LA' => t('Laois'),
    'KK' => t('Kilkenny'),
    'WF' => t('Waterford'),
    'CK' => t('Cork'),
    'KR' => t('Kerry'),
    'LM' => t('Limerick'),
    'TP' => t('Tipperary'),
    'CL' => t('Clare'),
    'GW' => t('Galway'),
    'MY' => t('Mayo'),
    'RC' => t('Roscommon'),
    'SL' => t('Sligo'),
    'LR' => t('Leitrim'),
    'DG' => t('Donegal')
  );
}
