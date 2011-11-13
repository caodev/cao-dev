<?php

/**
 * @file
 * "Latvia" specific data
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
function addresses_province_list_lv() {
  return array(
    'AIZ' => t('Aizkraukles Rajons'),
    'ALU' => t('Aluksnes Rajons'),
    'BAL' => t('Balvu Rajons'),
    'BAU' => t('Bauskas Rajons'),
    'CES' => t('Cesu Rajons'),
    'DGR' => t('Daugavpils Rajons'),
    'DOB' => t('Dobeles Rajons'),
    'GUL' => t('Gulbenes Rajons'),
    'JEK' => t('Jekabpils Rajons'),
    'JGR' => t('Jelgavas Rajons'),
    'KRA' => t('Kraslavas Rajons'),
    'KUL' => t('Kuldigas Rajons'),
    'LPR' => t('Liepajas Rajons'),
    'LIM' => t('Limbazu Rajons'),
    'LUD' => t('Ludzas Rajons'),
    'MAD' => t('Madonas Rajons'),
    'OGR' => t('Ogres Rajons'),
    'PRE' => t('Preilu Rajons'),
    'RZR' => t('Rezeknes Rajons'),
    'RGR' => t('Rigas Rajons'),
    'SAL' => t('Saldus Rajons'),
    'TAL' => t('Talsu Rajons'),
    'TUK' => t('Tukuma Rajons'),
    'VLK' => t('Valkas Rajons'),
    'VLM' => t('Valmieras Rajons'),
    'VSR' => t('Ventspils Rajons'),
    'DGV' => t('Daugavpils'),
    'JGV' => t('Jelgava'),
    'JUR' => t('Jurmala'),
    'LPK' => t('Liepaja'),
    'RZK' => t('Rezekne'),
    'RGA' => t('Riga'),
    'VSL' => t('Ventspils')
  );
}
