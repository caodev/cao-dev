<?php

/**
 * @file
 * "Mali" specific data
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
function addresses_province_list_ml() {
  return array(
    'GA' => t('Gao'),
    'KY' => t('Kayes'),
    'KD' => t('Kidal'),
    'KL' => t('Koulikoro'),
    'MP' => t('Mopti'),
    'SG' => t('Segou'),
    'SK' => t('Sikasso'),
    'TB' => t('Tombouctou'),
    'CD' => t('Bamako Capital District')
  );
}
