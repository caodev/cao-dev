<?php

/**
 * @file
 * "Tonga" specific data
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
function addresses_province_list_to() {
  return array(
    'H' => t("Ha'apai"),
    'T' => t('Tongatapu'),
    'V' => t("Vava'u")
  );
}
