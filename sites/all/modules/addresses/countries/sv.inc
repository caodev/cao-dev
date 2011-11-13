<?php

/**
 * @file
 * "El Salvador" specific data
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
function addresses_province_list_sv() {
  return array(
    'AH' => t('Ahuachapan'),
    'CA' => t('Cabanas'),
    'CH' => t('Chalatenango'),
    'CU' => t('Cuscatlan'),
    'LB' => t('La Libertad'),
    'PZ' => t('La Paz'),
    'UN' => t('La Union'),
    'MO' => t('Morazan'),
    'SM' => t('San Miguel'),
    'SS' => t('San Salvador'),
    'SA' => t('Santa Ana'),
    'SV' => t('San Vicente'),
    'SO' => t('Sonsonate'),
    'US' => t('Usulutan')
  );
}
