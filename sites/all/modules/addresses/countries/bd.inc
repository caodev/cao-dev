<?php

/**
 * @file
 * "Bangladesh" specific data
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
function addresses_province_list_bd() {
  return array(
    'BAR' => t('Barisal'),
    'CHI' => t('Chittagong'),
    'DHA' => t('Dhaka'),
    'KHU' => t('Khulna'),
    'RAJ' => t('Rajshahi'),
    'SYL' => t('Sylhet')
  );
}
