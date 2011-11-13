<?php

/**
 * @file
 * "Bulgaria" specific data
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
function addresses_province_list_bg() {
  return array(
    '01' => t('Blagoevgrad'),
    '02' => t('Burgas'),
    '03' => t('Varna'),
    '04' => t('Veliko Turnovo'),
    '05' => t('Vidin'),
    '06' => t('Vratsa'),
    '07' => t('Gabrovo'),
    '08' => t('Dobrich'),
    '09' => t('Kurdzhali'),
    '10' => t('Kyustendil'),
    '11' => t('Lovech'),
    '12' => t('Montana'),
    '13' => t('Pazardzhik'),
    '14' => t('Pernik'),
    '15' => t('Pleven'),
    '16' => t('Plovdiv'),
    '17' => t('Razgrad'),
    '18' => t('Ruse'),
    '19' => t('Silistra'),
    '20' => t('Sliven'),
    '21' => t('Smolyan'),
    '23' => t('Sofia'),
    '22' => t('Sofia Region'),
    '24' => t('Stara Zagora'),
    '25' => t('Turgovishte'),
    '26' => t('Khaskovo'),
    '27' => t('Shumen'),
    '28' => t('Yambol')
  );
}
