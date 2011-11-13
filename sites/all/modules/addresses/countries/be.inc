<?php

/**
 * @file
 * "Belgium" specific data
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
function addresses_province_list_be() {
  return array(
    'BRU' => t('Brussels'),
    'VAN' => t('Antwerpen'),
    'VBR' => t('Vlaams Brabant'),
    'VLI' => t('Limburg'),
    'VOV' => t('Oost-Vlaanderen'),
    'VWV' => t('West-Vlaanderen'),
    'WBR' => t('Brabant Wallon'),
    'WHT' => t('Hainaut'),
    'WLG' => t('Liege'),
    'WLX' => t('Luxembourg'),
    'WNA' => t('Namur')
  );
}
