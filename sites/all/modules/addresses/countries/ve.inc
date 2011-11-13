<?php

/**
 * @file
 * "Venezuela" specific data
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
function addresses_province_list_ve() {
  return array(
    'Z' => t('Amazonas'),
    'B' => t('Anzoategui'),
    'C' => t('Apure'),
    'D' => t('Aragua'),
    'E' => t('Barinas'),
    'F' => t('Bolivar'),
    'G' => t('Carabobo'),
    'H' => t('Cojedes'),
    'Y' => t('Delta Amacuro'),
    'I' => t('Falcon'),
    'J' => t('Guarico'),
    'K' => t('Lara'),
    'L' => t('Merida'),
    'M' => t('Miranda'),
    'N' => t('Monagas'),
    'O' => t('Nueva Esparta'),
    'P' => t('Portuguesa'),
    'R' => t('Sucre'),
    'S' => t('Tachira'),
    'T' => t('Trujillo'),
    'X' => t('Vargas'),
    'U' => t('Yaracuy'),
    'V' => t('Zulia'),
    'A' => t('Federal District'),
    'W' => t('Federal Dependency')
  );
}
