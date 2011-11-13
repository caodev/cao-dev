<?php

/**
 * @file
 * "San Marino" specific data
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
function addresses_province_list_sm() {
  return array(
    'AC' => t('Acquaviva'),
    'BM' => t('Borgo Maggiore'),
    'CH' => t('Chiesanuova'),
    'DO' => t('Domagnano'),
    'FA' => t('Faetano'),
    'FI' => t('Fiorentino'),
    'MO' => t('Montegiardino'),
    'SM' => t('Citta di San Marino'),
    'SE' => t('Serravalle')
  );
}
