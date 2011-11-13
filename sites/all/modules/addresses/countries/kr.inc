<?php

/**
 * @file
 * "Korea, Republic Of (South Korea)" specific data
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
function addresses_province_list_kr() {
  return array(
    '11' => t('Seoul Special City'),
    '26' => t('Busan Metropolitan City'),
    '27' => t('Daegu Metropolitan City'),
    '28' => t('Incheon Metropolitan City'),
    '29' => t('Gwangju Metropolitan City'),
    '30' => t('Daejeon Metropolitan City'),
    '31' => t('Ulsan Metropolitan City'),
    '41' => t('Gyeonggi-do'),
    '42' => t('Gangwon-do'),
    '43' => t('Chungcheongbuk-do'),
    '44' => t('Chungcheongnam-do'),
    '45' => t('Jeollabuk-do'),
    '46' => t('Jeollanam-do'),
    '47' => t('Gyeongsangbuk-do'),
    '48' => t('Gyeongsangnam-do'),
    '49' => t('Jeju-do')
  );
}
