<?php

/**
 * @file
 * "Seychelles" specific data
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
function addresses_province_list_sc() {
  return array(
    'AP' => t('Anse aux Pins'),
    'AB' => t('Anse Boileau'),
    'AE' => t('Anse Etoile'),
    'AL' => t('Anse Louis'),
    'AR' => t('Anse Royale'),
    'BL' => t('Baie Lazare'),
    'BS' => t('Baie Sainte Anne'),
    'BV' => t('Beau Vallon'),
    'BA' => t('Bel Air'),
    'BO' => t('Bel Ombre'),
    'CA' => t('Cascade'),
    'GL' => t('Glacis'),
    'GM' => t("Grand' Anse (on Mahe)"),
    'GP' => t("Grand' Anse (on Praslin)"),
    'DG' => t('La Digue'),
    'RA' => t('La Riviere Anglaise'),
    'MB' => t('Mont Buxton'),
    'MF' => t('Mont Fleuri'),
    'PL' => t('Plaisance'),
    'PR' => t('Pointe La Rue'),
    'PG' => t('Port Glaud'),
    'SL' => t('Saint Louis'),
    'TA' => t('Takamaka')
  );
}
