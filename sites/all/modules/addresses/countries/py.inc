<?php

/**
 * @file
 * "Paraguay" specific data
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
function addresses_province_list_py() {
  return array(
    'AG' => t('Alto Paraguay'),
    'AN' => t('Alto Parana'),
    'AM' => t('Amambay'),
    'AS' => t('Asuncion'),
    'BO' => t('Boqueron'),
    'CG' => t('Caaguazu'),
    'CZ' => t('Caazapa'),
    'CN' => t('Canindeyu'),
    'CE' => t('Central'),
    'CC' => t('Concepcion'),
    'CD' => t('Cordillera'),
    'GU' => t('Guaira'),
    'IT' => t('Itapua'),
    'MI' => t('Misiones'),
    'NE' => t('Neembucu'),
    'PA' => t('Paraguari'),
    'PH' => t('Presidente Hayes'),
    'SP' => t('San Pedro')
  );
}
