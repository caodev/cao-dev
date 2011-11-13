<?php

/**
 * @file
 * "Chad" specific data
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
function addresses_province_list_td() {
  return array(
    'BA' => t('Batha'),
    'BI' => t('Biltine'),
    'BE' => t('Borkou-Ennedi-Tibesti'),
    'CB' => t('Chari-Baguirmi'),
    'GU' => t('Guera'),
    'KA' => t('Kanem'),
    'LA' => t('Lac'),
    'LC' => t('Logone Occidental'),
    'LR' => t('Logone Oriental'),
    'MK' => t('Mayo-Kebbi'),
    'MC' => t('Moyen-Chari'),
    'OU' => t('Ouaddai'),
    'SA' => t('Salamat'),
    'TA' => t('Tandjile')
  );
}
