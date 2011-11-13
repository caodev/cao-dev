<?php

/**
 * @file
 * "Liechtenstein" specific data
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
function addresses_province_list_li() {
  return array(
    'V' => t('Vaduz'),
    'A' => t('Schaan'),
    'B' => t('Balzers'),
    'N' => t('Triesen'),
    'E' => t('Eschen'),
    'M' => t('Mauren'),
    'T' => t('Triesenberg'),
    'R' => t('Ruggell'),
    'G' => t('Gamprin'),
    'L' => t('Schellenberg'),
    'P' => t('Planken')
  );
}
