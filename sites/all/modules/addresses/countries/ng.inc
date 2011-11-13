<?php

/**
 * @file
 * "Nigeria" specific data
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
function addresses_province_list_ng() {
  return array(
    'AB' => t('Abia'),
    'AD' => t('Adamawa'),
    'AK' => t('Akwa Ibom'),
    'AN' => t('Anambra'),
    'BC' => t('Bauchi'),
    'BY' => t('Bayelsa'),
    'BN' => t('Benue'),
    'BO' => t('Borno'),
    'CR' => t('Cross River'),
    'DE' => t('Delta'),
    'EB' => t('Ebonyi'),
    'ED' => t('Edo'),
    'EK' => t('Ekiti'),
    'EN' => t('Enugu'),
    'CT' => t('Federal Capital Territory'),
    'GO' => t('Gombe'),
    'IM' => t('Imo'),
    'JI' => t('Jigawa'),
    'KD' => t('Kaduna'),
    'KN' => t('Kano'),
    'KT' => t('Katsina'),
    'KE' => t('Kebbi'),
    'KO' => t('Kogi'),
    'KW' => t('Kwara'),
    'LA' => t('Lagos'),
    'NA' => t('Nassarawa'),
    'NI' => t('Niger'),
    'OG' => t('Ogun'),
    'ONG' => t('Ondo'),
    'OS' => t('Osun'),
    'OY' => t('Oyo'),
    'PL' => t('Plateau'),
    'RI' => t('Rivers'),
    'SO' => t('Sokoto'),
    'TA' => t('Taraba'),
    'YO' => t('Yobe'),
    'ZA' => t('Zamfara')
  );
}
