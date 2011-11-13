<?php

/**
 * @file
 * "Samoa" specific data
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
function addresses_province_list_ws() {
  return array(
    'AN' => t("A'ana"),
    'AI' => t('Aiga-i-le-Tai'),
    'AT' => t('Atua'),
    'FA' => t("Fa'asaleleaga"),
    'GE' => t("Gaga'emauga"),
    'GF' => t('Gagaifomauga'),
    'PA' => t('Palauli'),
    'SA' => t("Satupa'itea"),
    'TU' => t('Tuamasaga'),
    'VF' => t("Va'a-o-Fonoti"),
    'VS' => t('Vaisigano')
  );
}
