<?php

/**
 * @file
 * "Barbados" specific data
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
function addresses_province_list_bb() {
  return array(
    'CC' => t('Christ Church'),
    'AND' => t('Saint Andrew'),
    'GEO' => t('Saint George'),
    'JAM' => t('Saint James'),
    'JOH' => t('Saint John'),
    'JOS' => t('Saint Joseph'),
    'LUC' => t('Saint Lucy'),
    'MIC' => t('Saint Michael'),
    'PET' => t('Saint Peter'),
    'PHI' => t('Saint Philip'),
    'THO' => t('Saint Thomas')
  );
}
