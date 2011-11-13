<?php

/**
 * @file
 * "Guatemala" specific data
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
function addresses_province_list_gt() {
  return array(
    'AV' => t('Alta Verapaz'),
    'BV' => t('Baja Verapaz'),
    'CM' => t('Chimaltenango'),
    'CQ' => t('Chiquimula'),
    'PE' => t('El Peten'),
    'PR' => t('El Progreso'),
    'QC' => t('El Quiche'),
    'ES' => t('Escuintla'),
    'GU' => t('Guatemala'),
    'HU' => t('Huehuetenango'),
    'IZ' => t('Izabal'),
    'JA' => t('Jalapa'),
    'JU' => t('Jutiapa'),
    'QZ' => t('Quetzaltenango'),
    'RE' => t('Retalhuleu'),
    'ST' => t('Sacatepequez'),
    'SM' => t('San Marcos'),
    'SR' => t('Santa Rosa'),
    'SO' => t('Solola'),
    'SU' => t('Suchitepequez'),
    'TO' => t('Totonicapan'),
    'ZA' => t('Zacapa')
  );
}
