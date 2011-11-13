<?php

/**
 * @file
 * "Cook Islands" specific data
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
function addresses_province_list_ck() {
  return array(
    'PU' => t('Pukapuka'),
    'RK' => t('Rakahanga'),
    'MK' => t('Manihiki'),
    'PE' => t('Penrhyn'),
    'NI' => t('Nassau Island'),
    'SU' => t('Surwarrow'),
    'PA' => t('Palmerston'),
    'AI' => t('Aitutaki'),
    'MA' => t('Manuae'),
    'TA' => t('Takutea'),
    'MT' => t('Mitiaro'),
    'AT' => t('Atiu'),
    'MU' => t('Mauke'),
    'RR' => t('Rarotonga'),
    'MG' => t('Mangaia')
  );
}
