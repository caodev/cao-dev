<?php

/**
 * @file
 * "Spain" specific data
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
function addresses_province_list_es() {
  return array(
    'AL' => t('Alava'),
    'AB' => t('Albacete'),
    'AC' => t('Alicante'),
    'AM' => t('Almeria'),
    'AS' => t('Asturias'),
    'AV' => t('Avila'),
    'BJ' => t('Badajoz'),
    'IB' => t('Illes Balears'),
    'BA' => t('Barcelona'),
    'BU' => t('Burgos'),
    'CC' => t('Caceres'),
    'CZ' => t('Cadiz'),
    'CT' => t('Cantabria'),
    'CL' => t('Castellon'),
    'CR' => t('Ciudad Real'),
    'CD' => t('Cordoba'),
    'CA' => t('A Coruna'),
    'CU' => t('Cuenca'),
    'GI' => t('Girona'),
    'GD' => t('Granada'),
    'GJ' => t('Guadalajara'),
    'GP' => t('Guipuzcoa'),
    'HL' => t('Huelva'),
    'HS' => t('Huesca'),
    'JN' => t('Jaen'),
    'RJ' => t('La Rioja'),
    'LE' => t('Leon'),
    'LL' => t('Lleida'),
    'LG' => t('Lugo'),
    'MD' => t('Madrid'),
    'ML' => t('Malaga'),
    'MU' => t('Murcia'),
    'NV' => t('Navarra'),
    'OU' => t('Ourense'),
    'PL' => t('Palencia'),
    'PM' => t('Las Palmas'),
    'PO' => t('Pontevedra'),
    'SL' => t('Salamanca'),
    'SC' => t('Santa Cruz de Tererife'),
    'SG' => t('Segovia'),
    'SV' => t('Sevilla'),
    'SO' => t('Soria'),
    'TA' => t('Tarragona'),
    'TE' => t('Teruel'),
    'TO' => t('Toledo'),
    'VC' => t('Valencia'),
    'VD' => t('Valladolid'),
    'VZ' => t('Vizcaya'),
    'ZM' => t('Zamora'),
    'ZR' => t('Zaragoza')
  );
}
