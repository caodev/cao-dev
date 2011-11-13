<?php

/**
 * @file
 * "Dominican Republic" specific data
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
function addresses_province_list_do() {
  return array(
    'DN' => t('Distrito Nacional'),
    'AZ' => t('Azua'),
    'BC' => t('Baoruco'),
    'BH' => t('Barahona'),
    'DJ' => t('Dajabon'),
    'DU' => t('Duarte'),
    'EL' => t('Elias Pina'),
    'SY' => t('El Seybo'),
    'ET' => t('Espaillat'),
    'HM' => t('Hato Mayor'),
    'IN' => t('Independencia'),
    'AL' => t('La Altagracia'),
    'RO' => t('La Romana'),
    'VE' => t('La Vega'),
    'MT' => t('Maria Trinidad Sanchez'),
    'MN' => t('Monsenor Nouel'),
    'MC' => t('Monte Cristi'),
    'MP' => t('Monte Plata'),
    'PD' => t('Pedernales'),
    'PR' => t('Peravia (Bani)'),
    'PP' => t('Puerto Plata'),
    'SL' => t('Salcedo'),
    'SM' => t('Samana'),
    'SH' => t('Sanchez Ramirez'),
    'SC' => t('San Cristobal'),
    'JO' => t('San Jose de Ocoa'),
    'SJ' => t('San Juan'),
    'PM' => t('San Pedro de Macoris'),
    'SA' => t('Santiago'),
    'ST' => t('Santiago Rodriguez'),
    'SD' => t('Santo Domingo'),
    'VA' => t('Valverde')
  );
}
