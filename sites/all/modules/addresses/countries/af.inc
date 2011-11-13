<?php

/**
 * @file
 * "Afghanistan" specific data
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
function addresses_province_list_af() {
  return array(
    'BDS' => t('Badakhshan province'),
    'BDG' => t('Badghis province'),
    'BGL' => t('Baghlan province'),
    'BAL' => t('Balkh province'),
    'BAM' => t('Bamian province'),
    'FRA' => t('Farah province'),
    'FYB' => t('Faryab province'),
    'GHA' => t('Ghazni province'),
    'GHO' => t('Ghowr province'),
    'HEL' => t('Helmand province'),
    'HER' => t('Herat province'),
    'JOW' => t('Jowzjan province'),
    'KAB' => t('Kabul province'),
    'KAN' => t('Kandahar province'),
    'KAP' => t('Kapisa province'),
    'KHO' => t('Khost province'),
    'KNR' => t('Konar province'),
    'KDZ' => t('Kondoz province'),
    'LAG' => t('Laghman province'),
    'LOW' => t('Lowgar province'),
    'NAN' => t('Nangrahar province'),
    'NIM' => t('Nimruz province'),
    'NUR' => t('Nurestan province'),
    'ORU' => t('Oruzgan province'),
    'PIA' => t('Paktia province'),
    'PKA' => t('Paktika province'),
    'PAR' => t('Parwan province'),
    'SAM' => t('Samangan province'),
    'SAR' => t('Sar-e Pol province'),
    'TAK' => t('Takhar province'),
    'WAR' => t('Wardak province'),
    'ZAB' => t('Zabol province')
  );
}
