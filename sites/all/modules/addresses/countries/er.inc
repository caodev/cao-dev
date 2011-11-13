<?php

/**
 * @file
 * "Eritrea" specific data
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
function addresses_province_list_er() {
  return array(
    'MA' => t('Central (Maekel)'),
    'KE' => t('Anseba (Keren)'),
    'DK' => t('Southern Red Sea (Debub-Keih-Bahri)'),
    'SK' => t('Northern Red Sea (Semien-Keih-Bahri)'),
    'DE' => t('Southern (Debub)'),
    'BR' => t('Gash-Barka (Barentu)')
  );
}
