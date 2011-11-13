<?php

/**
 * @file
 * "Korea, Democratic People's Republic Of (North Korea)" specific data
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
function addresses_province_list_kp() {
  return array(
    'CHA' => t('Chagang-do'),
    'HAB' => t('Hamgyong-bukto'),
    'HAN' => t('Hamgyong-namdo'),
    'HWB' => t('Hwanghae-bukto'),
    'HWN' => t('Hwanghae-namdo'),
    'KAN' => t('Kangwon-do'),
    'PYB' => t("P'yongan-bukto"),
    'PYN' => t("P'yongan-namdo"),
    'YAN' => t('Ryanggang-do (Yanggang-do)'),
    'NAJ' => t('Rason Directly Governed City'),
    'PYO' => t("P'yongyang Special City")
  );
}
