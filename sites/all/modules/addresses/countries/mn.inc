<?php

/**
 * @file
 * "Mongolia" specific data
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
function addresses_province_list_mn() {
  return array(
    '1' => t('Ulanbaatar'),
    '035' => t('Orhon'),
    '037' => t('Darhan uul'),
    '039' => t('Hentiy'),
    '041' => t('Hovsgol'),
    '043' => t('Hovd'),
    '046' => t('Uvs'),
    '047' => t('Tov'),
    '049' => t('Selenge'),
    '051' => t('Suhbaatar'),
    '053' => t('Omnogovi'),
    '055' => t('Ovorhangay'),
    '057' => t('Dzavhan'),
    '059' => t('DundgovL'),
    '061' => t('Dornod'),
    '063' => t('Dornogov'),
    '064' => t('Govi-Sumber'),
    '065' => t('Govi-Altay'),
    '067' => t('Bulgan'),
    '069' => t('Bayanhongor'),
    '071' => t('Bayan-Olgiy'),
    '073' => t('Arhangay')
  );
}
