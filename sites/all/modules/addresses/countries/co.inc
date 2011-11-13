<?php

/**
 * @file
 * "Colombia" specific data
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
function addresses_province_list_co() {
  return array(
    'AMZ' => t('Amazonas'),
    'ANT' => t('Antioquia'),
    'ARA' => t('Arauca'),
    'ATL' => t('Atlantico'),
    'BOL' => t('Bolivar'),
    'BOY' => t('Boyaca'),
    'CAL' => t('Caldas'),
    'CAQ' => t('Caqueta'),
    'CAS' => t('Casanare'),
    'CAU' => t('Cauca'),
    'CES' => t('Cesar'),
    'CHO' => t('Choco'),
    'COR' => t('Cordoba'),
    'CAM' => t('Cundinamarca'),
    'GNA' => t('Guainia'),
    'GJR' => t('Guajira'),
    'GVR' => t('Guaviare'),
    'HUI' => t('Huila'),
    'MAG' => t('Magdalena'),
    'MET' => t('Meta'),
    'NAR' => t('Narino'),
    'NDS' => t('Norte de Santander'),
    'PUT' => t('Putumayo'),
    'QUI' => t('Quindio'),
    'RIS' => t('Risaralda'),
    'SAP' => t('San Andres y Providencia'),
    'SAN' => t('Santander'),
    'SUC' => t('Sucre'),
    'TOL' => t('Tolima'),
    'VDC' => t('Valle del Cauca'),
    'VAU' => t('Vaupes'),
    'VIC' => t('Vichada'),
    'BDC' => t('Bogota D.C.')
  );
}
