<?php

/**
 * @file
 * "Maldives" specific data
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
function addresses_province_list_mv() {
  return array(
    'THU' => t('Thiladhunmathi Uthuru'),
    'THD' => t('Thiladhunmathi Dhekunu'),
    'MLU' => t('Miladhunmadulu Uthuru'),
    'MLD' => t('Miladhunmadulu Dhekunu'),
    'MAU' => t('Maalhosmadulu Uthuru'),
    'MAD' => t('Maalhosmadulu Dhekunu'),
    'FAA' => t('Faadhippolhu'),
    'MAA' => t('Male Atoll'),
    'AAU' => t('Ari Atoll Uthuru'),
    'AAD' => t('Ari Atoll Dheknu'),
    'FEA' => t('Felidhe Atoll'),
    'MUA' => t('Mulaku Atoll'),
    'NAU' => t('Nilandhe Atoll Uthuru'),
    'NAD' => t('Nilandhe Atoll Dhekunu'),
    'KLH' => t('Kolhumadulu'),
    'HDH' => t('Hadhdhunmathi'),
    'HAU' => t('Huvadhu Atoll Uthuru'),
    'HAD' => t('Huvadhu Atoll Dhekunu'),
    'FMU' => t('Fua Mulaku'),
    'ADD' => t('Addu')
  );
}
