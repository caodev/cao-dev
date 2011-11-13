<?php

/**
 * @file
 * "India" specific data
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
function addresses_province_list_in() {
  return array(
    'AP' => t('Andhra Pradesh'),
    'AR' => t('Arunachal Pradesh'),
    'AS' => t('Assam'),
    'BR' => t('Bihar'),
    'CT' => t('Chhattisgarh'),
    'GA' => t('Goa'),
    'GJ' => t('Gujarat'),
    'HR' => t('Haryana'),
    'HP' => t('Himachal Pradesh'),
    'JK' => t('Jammu and Kashmir'),
    'JH' => t('Jharkhand'),
    'KA' => t('Karnataka'),
    'KL' => t('Kerala'),
    'MP' => t('Madhya Pradesh'),
    'MM' => t('Maharashtra'),
    'MN' => t('Manipur'),
    'ML' => t('Meghalaya'),
    'MZ' => t('Mizoram'),
    'NL' => t('Nagaland'),
    'OR' => t('Orissa'),
    'PB' => t('Punjab'),
    'RJ' => t('Rajasthan'),
    'SK' => t('Sikkim'),
    'TN' => t('Tamil Nadu'),
    'TR' => t('Tripura'),
    'UL' => t('Uttaranchal'),
    'UP' => t('Uttar Pradesh'),
    'WB' => t('West Bengal'),
    'AN' => t('Andaman and Nicobar Islands'),
    'CH' => t('Chandigarh'),
    'DN' => t('Dadra and Nagar Haveli'),
    'DD' => t('Daman and Diu'),
    'DL' => t('Delhi'),
    'LD' => t('Lakshadweep'),
    'PY' => t('Pondicherry')
  );
}
