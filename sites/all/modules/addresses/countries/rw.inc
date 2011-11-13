<?php

/**
 * @file
 * "Rwanda" specific data
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
function addresses_province_list_rw() {
  return array(
    'BU' => t('Butare'),
    'BY' => t('Byumba'),
    'CY' => t('Cyangugu'),
    'GK' => t('Gikongoro'),
    'GS' => t('Gisenyi'),
    'GT' => t('Gitarama'),
    'KG' => t('Kibungo'),
    'KY' => t('Kibuye'),
    'KR' => t('Kigali Rurale'),
    'KV' => t('Kigali-ville'),
    'RU' => t('Ruhengeri'),
    'UM' => t('Umutara')
  );
}
