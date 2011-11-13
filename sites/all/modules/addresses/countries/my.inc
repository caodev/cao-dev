<?php

/**
 * @file
 * "Malaysia" specific data
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
function addresses_province_list_my() {
  return array(
    'JH' => t('Johor'),
    'KD' => t('Kedah'),
    'KN' => t('Kelantan'),
    'KL' => t('Kuala Lumpur'),
    'ML' => t('Malacca'),
    'NS' => t('Negeri Sembilan'),
    'PH' => t('Pahang'),
    'PK' => t('Perak'),
    'PS' => t('Perlis'),
    'PG' => t('Penang'),
    'WP' => t('Wilayah Persekutuan'),
    'SL' => t('Selangor'),
    'TR' => t('Terengganu'),
    'LB' => t('Labuan'),
    'SB' => t('Sabah'),
    'SR' => t('Sarawak')
  );
}
