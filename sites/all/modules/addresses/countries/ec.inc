<?php

/**
 * @file
 * "Ecuador" specific data
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
function addresses_province_list_ec() {
  return array(
    'A' => t('Azuay'),
    'B' => t('Bolivar'),
    'C' => t('Carchi'),
    'D' => t('Orellana'),
    'E' => t('Esmeraldas'),
    'F' => t('Canar'),
    'G' => t('Guayas'),
    'H' => t('Chimborazo'),
    'I' => t('Imbabura'),
    'L' => t('Loja'),
    'M' => t('Manabi'),
    'N' => t('Napo'),
    'O' => t('El Oro'),
    'P' => t('Pichincha'),
    'R' => t('Los Rios'),
    'S' => t('Morona-Santiago'),
    'T' => t('Tungurahua'),
    'U' => t('Sucumbios'),
    'W' => t('Galapagos'),
    'X' => t('Cotopaxi'),
    'Y' => t('Pastaza'),
    'Z' => t('Zamora-Chinchipe')
  );
}
