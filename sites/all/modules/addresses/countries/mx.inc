<?php

/**
 * @file
 * "Mexico" specific data
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
function addresses_province_list_mx() {
  return array(
    'AGU' => t('Aguascalientes'),
    'BCN' => t('Baja California'),
    'BCS' => t('Baja California Sur'),
    'CAM' => t('Campeche'),
    'CHP' => t('Chiapas'),
    'CHH' => t('Chihuahua'),
    'COA' => t('Coahuila'),
    'COL' => t('Colima'),
    'DUR' => t('Durango'),
    'GUA' => t('Guanajuato'),
    'GRO' => t('Guerrero'),
    'HID' => t('Hidalgo'),
    'JAL' => t('Jalisco'),
    'MEX' => t('Mexico'),
    'MIC' => t('Michoacan'),
    'MOR' => t('Morelos'),
    'NAY' => t('Nayarit'),
    'NLE' => t('Nuevo Leon'),
    'OAX' => t('Oaxaca'),
    'PUE' => t('Puebla'),
    'QUE' => t('Queretaro'),
    'ROO' => t('Quintana Roo'),
    'SLP' => t('San Luis Potosi'),
    'SIN' => t('Sinaloa'),
    'SON' => t('Sonora'),
    'TAB' => t('Tabasco'),
    'TAM' => t('Tamaulipas'),
    'TLA' => t('Tlaxcala'),
    'VER' => t('Veracruz'),
    'YUC' => t('Yucatan'),
    'ZAC' => t('Zacatecas'),
    'DIF' => t('Distrito Federal')
  );
}
