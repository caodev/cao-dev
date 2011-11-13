<?php

/**
 * @file
 * "Antigua and Barbuda" specific data
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
function addresses_province_list_ag() {
  return array(
    'ASG' => t('Saint George'),
    'ASJ' => t('Saint John'),
    'ASM' => t('Saint Mary'),
    'ASL' => t('Saint Paul'),
    'ASR' => t('Saint Peter'),
    'ASH' => t('Saint Philip'),
    'BAR' => t('Barbuda'),
    'RED' => t('Redonda')
  );
}
