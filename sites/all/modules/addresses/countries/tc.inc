<?php

/**
 * @file
 * "Turks and Caicos Islands" specific data
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
function addresses_province_list_tc() {
  return array(
    'AC' => t('Ambergris Cays'),
    'DC' => t('Dellis Cay'),
    'FC' => t('French Cay'),
    'LW' => t('Little Water Cay'),
    'RC' => t('Parrot Cay'),
    'PN' => t('Pine Cay'),
    'SL' => t('Salt Cay'),
    'GT' => t('Grand Turk'),
    'SC' => t('South Caicos'),
    'EC' => t('East Caicos'),
    'MC' => t('Middle Caicos'),
    'NC' => t('North Caicos'),
    'PR' => t('Providenciales'),
    'WC' => t('West Caicos')
  );
}
