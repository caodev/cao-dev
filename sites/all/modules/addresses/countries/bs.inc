<?php

/**
 * @file
 * "Bahamas" specific data
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
function addresses_province_list_bs() {
  return array(
    'ACK' => t('Acklins'),
    'BER' => t('Berry Islands'),
    'BIM' => t('Bimini'),
    'BLK' => t('Black Point'),
    'CAT' => t('Cat Island'),
    'CAB' => t('Central Abaco'),
    'CAN' => t('Central Andros'),
    'CEL' => t('Central Eleuthera'),
    'FRE' => t('City of Freeport'),
    'CRO' => t('Crooked Island'),
    'EGB' => t('East Grand Bahama'),
    'EXU' => t('Exuma'),
    'GRD' => t('Grand Cay'),
    'HAR' => t('Harbour Island'),
    'HOP' => t('Hope Town'),
    'INA' => t('Inagua'),
    'LNG' => t('Long Island'),
    'MAN' => t('Mangrove Cay'),
    'MAY' => t('Mayaguana'),
    'MOO' => t("Moore's Island"),
    'NAB' => t('North Abaco'),
    'NAN' => t('North Andros'),
    'NEL' => t('North Eleuthera'),
    'RAG' => t('Ragged Island'),
    'RUM' => t('Rum Cay'),
    'SAL' => t('San Salvador'),
    'SAB' => t('South Abaco'),
    'SAN' => t('South Andros'),
    'SEL' => t('South Eleuthera'),
    'SWE' => t('Spanish Wells'),
    'WGB' => t('West Grand Bahama')
  );
}
