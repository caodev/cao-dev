<?php

/**
 * @file
 * "Portugal" specific data
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
function addresses_province_list_pt() {
  return array(
    'AV' => t('Aveiro'),
    'AR' => t('Acores (Azores)'),
    'BJ' => t('Beja'),
    'BA' => t('Braga'),
    'BN' => t('Braganca'),
    'CB' => t('Castelo Branco'),
    'CO' => t('Coimbra'),
    'EV' => t('Evora'),
    'FA' => t('Faro'),
    'GU' => t('Guarda'),
    'LE' => t('Leiria'),
    'LI' => t('Lisboa'),
    'MA' => t('Madeira'),
    'PG' => t('Portalegre'),
    'PO' => t('Porto'),
    'SA' => t('Santarem'),
    'SE' => t('Setubal'),
    'VC' => t('Viana do Castelo'),
    'VR' => t('Vila Real'),
    'VS' => t('Viseu')
  );
}
