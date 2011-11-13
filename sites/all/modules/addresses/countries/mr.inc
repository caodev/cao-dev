<?php

/**
 * @file
 * "Mauritania" specific data
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
function addresses_province_list_mr() {
  return array(
    'AD' => t('Adrar'),
    'AS' => t('Assaba'),
    'BR' => t('Brakna'),
    'DN' => t('Dakhlet Nouadhibou'),
    'GO' => t('Gorgol'),
    'GM' => t('Guidimaka'),
    'HC' => t('Hodh Ech Chargui'),
    'HG' => t('Hodh El Gharbi'),
    'IN' => t('Inchiri'),
    'TA' => t('Tagant'),
    'TZ' => t('Tiris Zemmour'),
    'TR' => t('Trarza'),
    'NO' => t('Nouakchott')
  );
}
