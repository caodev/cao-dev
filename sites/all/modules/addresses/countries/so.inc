<?php

/**
 * @file
 * "Somalia" specific data
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
function addresses_province_list_so() {
  return array(
    'AW' => t('Awdal'),
    'BK' => t('Bakool'),
    'BN' => t('Banaadir'),
    'BR' => t('Bari'),
    'BY' => t('Bay'),
    'GA' => t('Galguduud'),
    'GE' => t('Gedo'),
    'HI' => t('Hiiraan'),
    'JD' => t('Jubbada Dhexe'),
    'JH' => t('Jubbada Hoose'),
    'MU' => t('Mudug'),
    'NU' => t('Nugaal'),
    'SA' => t('Sanaag'),
    'SD' => t('Shabeellaha Dhexe'),
    'SH' => t('Shabeellaha Hoose'),
    'SL' => t('Sool'),
    'TO' => t('Togdheer'),
    'WG' => t('Woqooyi Galbeed')
  );
}
