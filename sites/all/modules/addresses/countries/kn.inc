<?php

/**
 * @file
 * "Saint Kitts and Nevis" specific data
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
function addresses_province_list_kn() {
  return array(
    'CCN' => t('Christ Church Nichola Town'),
    'SAS' => t('Saint Anne Sandy Point'),
    'SGB' => t('Saint George Basseterre'),
    'SGG' => t('Saint George Gingerland'),
    'SJW' => t('Saint James Windward'),
    'SJC' => t('Saint John Capesterre'),
    'SJF' => t('Saint John Figtree'),
    'SMC' => t('Saint Mary Cayon'),
    'CAP' => t('Saint Paul Capesterre'),
    'CHA' => t('Saint Paul Charlestown'),
    'SPB' => t('Saint Peter Basseterre'),
    'STL' => t('Saint Thomas Lowland'),
    'STM' => t('Saint Thomas Middle Island'),
    'TPP' => t('Trinity Palmetto Point')
  );
}
