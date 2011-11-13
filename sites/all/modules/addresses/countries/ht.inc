<?php

/**
 * @file
 * "Haiti" specific data
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
function addresses_province_list_ht() {
  return array(
    'AR' => t('Artibonite'),
    'CE' => t('Centre'),
    'GA' => t("Grand'Anse"),
    'ND' => t('Nord'),
    'NE' => t('Nord-Est'),
    'NO' => t('Nord-Ouest'),
    'OU' => t('Ouest'),
    'SD' => t('Sud'),
    'SE' => t('Sud-Est')
  );
}
