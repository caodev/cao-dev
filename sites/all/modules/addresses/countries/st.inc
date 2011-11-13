<?php

/**
 * @file
 * "Sao Tome and Principe" specific data
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
function addresses_province_list_st() {
  return array(
    'S' => t('Sao Tome'),
    'P' => t('Principe')
  );
}
