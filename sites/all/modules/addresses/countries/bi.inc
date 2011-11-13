<?php

/**
 * @file
 * "Burundi" specific data
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
function addresses_province_list_bi() {
  return array(
    'BB' => t('Bubanza'),
    'BJ' => t('Bujumbura'),
    'BR' => t('Bururi'),
    'CA' => t('Cankuzo'),
    'CI' => t('Cibitoke'),
    'GI' => t('Gitega'),
    'KR' => t('Karuzi'),
    'KY' => t('Kayanza'),
    'KI' => t('Kirundo'),
    'MA' => t('Makamba'),
    'MU' => t('Muramvya'),
    'MY' => t('Muyinga'),
    'MW' => t('Mwaro'),
    'NG' => t('Ngozi'),
    'RT' => t('Rutana'),
    'RY' => t('Ruyigi')
  );
}
