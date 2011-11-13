<?php

/**
 * @file
 * "Indonesia" specific data
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
function addresses_province_list_id() {
  return array(
    'BA' => t('Bali'),
    'BB' => t('Bangka-Belitung'),
    'BT' => t('Banten'),
    'BE' => t('Bengkulu'),
    'GO' => t('Gorontalo'),
    'JA' => t('Jambi'),
    'JR' => t('Jawa Barat'),
    'JT' => t('Jawa Tengah'),
    'JI' => t('Jawa Timur'),
    'KB' => t('Kalimantan Barat'),
    'KS' => t('Kalimantan Selatan'),
    'KT' => t('Kalimantan Tengah'),
    'KI' => t('Kalimantan Timur'),
    'LA' => t('Lampung'),
    'MA' => t('Maluku'),
    'MU' => t('Maluku Utara'),
    'NB' => t('Nusa Tenggara Barat'),
    'NT' => t('Nusa Tenggara Timur'),
    'IJ' => t('Papua'),
    'RI' => t('Riau'),
    'SN' => t('Sulawesi Selatan'),
    'ST' => t('Sulawesi Tengah'),
    'SG' => t('Sulawesi Tenggara'),
    'SW' => t('Sulawesi Utara'),
    'SB' => t('Sumatera Barat'),
    'SL' => t('Sumatera Selatan'),
    'SU' => t('Sumatera Utara'),
    'JK' => t('Jakarta Raya'),
    'AC' => t('Aceh'),
    'YO' => t('Yogyakarta')
  );
}
