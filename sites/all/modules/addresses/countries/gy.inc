<?php

/**
 * @file
 * "Guyana" specific data
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
function addresses_province_list_gy() {
  return array(
    'BW' => t('Barima-Waini'),
    'CM' => t('Cuyuni-Mazaruni'),
    'DM' => t('Demerara-Mahaica'),
    'EC' => t('East Berbice-Corentyne'),
    'EW' => t('Essequibo Islands-West Demerara'),
    'MB' => t('Mahaica-Berbice'),
    'PM' => t('Pomeroon-Supenaam'),
    'PI' => t('Potaro-Siparuni'),
    'UD' => t('Upper Demerara-Berbice'),
    'UT' => t('Upper Takutu-Upper Essequibo')
  );
}
