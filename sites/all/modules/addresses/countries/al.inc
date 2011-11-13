<?php

/**
 * @file
 * "Albania" specific data
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
function addresses_province_list_al() {
  return array(
    'BR' => t('Berat'),
    'BU' => t('Bulqize'),
    'DL' => t('Delvine'),
    'DV' => t('Devoll'),
    'DI' => t('Diber'),
    'DR' => t('Durres'),
    'EL' => t('Elbasan'),
    'ER' => t('Kolonje'),
    'FR' => t('Fier'),
    'GJ' => t('Gjirokaster'),
    'GR' => t('Gramsh'),
    'HA' => t('Has'),
    'KA' => t('Kavaje'),
    'KB' => t('Kurbin'),
    'KC' => t('Kucove'),
    'KO' => t('Korce'),
    'KR' => t('Kruje'),
    'KU' => t('Kukes'),
    'LB' => t('Librazhd'),
    'LE' => t('Lezhe'),
    'LU' => t('Lushnje'),
    'MM' => t('Malesi e Madhe'),
    'MK' => t('Mallakaster'),
    'MT' => t('Mat'),
    'MR' => t('Mirdite'),
    'PQ' => t('Peqin'),
    'PR' => t('Permet'),
    'PG' => t('Pogradec'),
    'PU' => t('Puke'),
    'SH' => t('Shkoder'),
    'SK' => t('Skrapar'),
    'SR' => t('Sarande'),
    'TE' => t('Tepelene'),
    'TP' => t('Tropoje'),
    'TR' => t('Tirane'),
    'VL' => t('Vlore')
  );
}
