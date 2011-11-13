<?php

/**
 * @file
 * "Cape Verde" specific data
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
function addresses_province_list_cv() {
  return array(
    'BV' => t('Boa Vista'),
    'BR' => t('Brava'),
    'CS' => t('Calheta de Sao Miguel'),
    'MA' => t('Maio'),
    'MO' => t('Mosteiros'),
    'PA' => t('Paul'),
    'PN' => t('Porto Novo'),
    'PR' => t('Praia'),
    'RG' => t('Ribeira Grande'),
    'SL' => t('Sal'),
    'CA' => t('Santa Catarina'),
    'CR' => t('Santa Cruz'),
    'SD' => t('Sao Domingos'),
    'SF' => t('Sao Filipe'),
    'SN' => t('Sao Nicolau'),
    'SV' => t('Sao Vicente'),
    'TA' => t('Tarrafal')
  );
}
