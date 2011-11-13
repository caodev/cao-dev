<?php

/**
 * @file
 * "Angola" specific data
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
function addresses_province_list_ao() {
  return array(
    'BGO' => t('Bengo'),
    'BGU' => t('Benguela province'),
    'BIE' => t('Bie'),
    'CAB' => t('Cabinda'),
    'CCU' => t('Cuando-Cubango'),
    'CNO' => t('Cuanza Norte'),
    'CUS' => t('Cuanza Sul'),
    'CNN' => t('Cunene'),
    'HUA' => t('Huambo province'),
    'HUI' => t('Huila province'),
    'LUA' => t('Luanda'),
    'LNO' => t('Lunda Norte'),
    'LSU' => t('Lunda Sul'),
    'MAL' => t('Malange'),
    'MOX' => t('Moxico'),
    'NAM' => t('Namibe'),
    'UIG' => t('Uige'),
    'ZAI' => t('Zaire')
  );
}
