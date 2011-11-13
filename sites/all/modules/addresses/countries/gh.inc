<?php

/**
 * @file
 * "Ghana" specific data
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
function addresses_province_list_gh() {
  return array(
    'AS' => t('Ashanti Region'),
    'BA' => t('Brong-Ahafo Region'),
    'CE' => t('Central Region'),
    'EA' => t('Eastern Region'),
    'GA' => t('Greater Accra Region'),
    'NO' => t('Northern Region'),
    'UE' => t('Upper East Region'),
    'UW' => t('Upper West Region'),
    'VO' => t('Volta Region'),
    'WE' => t('Western Region')
  );
}
