<?php

/**
 * @file
 * "Switzerland" specific data
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
function addresses_province_list_ch() {
  return array(
    'ZH' => t('Zurich'),
    'BE' => t('Bern'),
    'LU' => t('Lucerne'),
    'UR' => t('Uri'),
    'SZ' => t('Schwyz'),
    'OW' => t('Obwalden'),
    'NW' => t('Nidwalden'),
    'GL' => t('Glarus'),
    'ZG' => t('Zug'),
    'FR' => t('Fribourg'),
    'SO' => t('Solothurn'),
    'BS' => t('Basel-Stadt'),
    'BL' => t('Basel-Landschaft'),
    'SH' => t('Schaffhausen'),
    'AR' => t('Appenzell Ausserrhoden'),
    'AI' => t('Appenzell Innerhoden'),
    'SG' => t('St. Gallen'),
    'GR' => t('Graubunden'),
    'AG' => t('Aargau'),
    'TG' => t('Thurgau'),
    'TI' => t('Ticino'),
    'VD' => t('Vaud'),
    'VS' => t('Valais'),
    'NE' => t('Neuchâtel'),
    'GE' => t('Geneva'),
    'JU' => t('Jura')
  );
}
