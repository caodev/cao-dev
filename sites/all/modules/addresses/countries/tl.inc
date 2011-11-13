<?php

/**
 * @file
 * "Timor Leste" specific data
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
function addresses_province_list_tl() {
  return array(
    'AL' => t('Aileu'),
    'AN' => t('Ainaro'),
    'BA' => t('Baucau'),
    'BO' => t('Bobonaro'),
    'CO' => t('Cova Lima'),
    'DI' => t('Dili'),
    'ER' => t('Ermera'),
    'LA' => t('Lautem'),
    'LI' => t('Liquica'),
    'MT' => t('Manatuto'),
    'MF' => t('Manufahi'),
    'OE' => t('Oecussi'),
    'VI' => t('Viqueque')
  );
}
