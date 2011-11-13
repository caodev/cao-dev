<?php

/**
 * @file
 * "Nicaragua" specific data
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
function addresses_province_list_ni() {
  return array(
    'BO' => t('Boaco'),
    'CA' => t('Carazo'),
    'CD' => t('Chinandega'),
    'CT' => t('Chontales'),
    'ES' => t('Esteli'),
    'GR' => t('Granada'),
    'JI' => t('Jinotega'),
    'LE' => t('Leon'),
    'MD' => t('Madriz'),
    'MN' => t('Managua'),
    'MS' => t('Masaya'),
    'MT' => t('Matagalpa'),
    'NS' => t('Nueva Segovia'),
    'RV' => t('Rivas'),
    'SJ' => t('Rio San Juan'),
    'AN' => t('Region Autonoma del Atlantico Norte'),
    'AS' => t('Region Autonoma del Atlantico Sur')
  );
}
