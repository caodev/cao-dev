<?php

/**
 * @file
 * "Peru" specific data
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
function addresses_province_list_pe() {
  return array(
    'AM' => t('Amazonas'),
    'AN' => t('Ancash'),
    'AP' => t('Apurimac'),
    'AR' => t('Arequipa'),
    'AY' => t('Ayacucho'),
    'CJ' => t('Cajamarca'),
    'CL' => t('Callao'),
    'CU' => t('Cusco'),
    'HV' => t('Huancavelica'),
    'HO' => t('Huanuco'),
    'IC' => t('Ica'),
    'JU' => t('Junin'),
    'LD' => t('La Libertad'),
    'LY' => t('Lambayeque'),
    'LI' => t('Lima'),
    'LO' => t('Loreto'),
    'MD' => t('Madre de Dios'),
    'MO' => t('Moquegua'),
    'PA' => t('Pasco'),
    'PI' => t('Piura'),
    'PU' => t('Puno'),
    'SM' => t('San Martin'),
    'TA' => t('Tacna'),
    'TU' => t('Tumbes'),
    'UC' => t('Ucayali')
  );
}
