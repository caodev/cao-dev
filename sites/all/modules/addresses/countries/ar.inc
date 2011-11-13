<?php

/**
 * @file
 * "Argentina" specific data
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
function addresses_province_list_ar() {
  return array(
    'A' => t('Salta'),
    'B' => t('Buenos Aires Province'),
    'C' => t('Distrito Federal'),
    'D' => t('San Luis'),
    'E' => t('Entre Rios'),
    'F' => t('La Rioja'),
    'G' => t('Santiago del Estero'),
    'H' => t('Chaco'),
    'J' => t('San Juan'),
    'K' => t('Catamarca'),
    'L' => t('La Pampa'),
    'M' => t('Mendoza'),
    'N' => t('Misiones'),
    'P' => t('Formosa'),
    'Q' => t('Neuquen'),
    'R' => t('Rio Negro'),
    'S' => t('Santa Fe'),
    'T' => t('Tucuman'),
    'U' => t('Chubut'),
    'V' => t('Tierra del Fuego'),
    'W' => t('Corrientes'),
    'X' => t('Cordoba'),
    'Y' => t('Jujuy'),
    'Z' => t('Santa Cruz')
  );
}
