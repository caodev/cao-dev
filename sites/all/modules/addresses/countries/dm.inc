<?php

/**
 * @file
 * "Dominica" specific data
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
function addresses_province_list_dm() {
  return array(
    'AND' => t('Saint Andrew Parish'),
    'DAV' => t('Saint David Parish'),
    'GEO' => t('Saint George Parish'),
    'JOH' => t('Saint John Parish'),
    'JOS' => t('Saint Joseph Parish'),
    'LUK' => t('Saint Luke Parish'),
    'MAR' => t('Saint Mark Parish'),
    'PAT' => t('Saint Patrick Parish'),
    'PAU' => t('Saint Paul Parish'),
    'PET' => t('Saint Peter Parish')
  );
}
