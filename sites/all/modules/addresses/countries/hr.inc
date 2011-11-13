<?php

/**
 * @file
 * "Croatia" specific data
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
function addresses_province_list_hr() {
  return array(
    '01' => t('Zagreb county'),
    '02' => t('Krapina-Zagorje county'),
    '03' => t('Sisak-Moslavina county'),
    '04' => t('Karlovac county'),
    '05' => t('Varazdin county'),
    '06' => t('Koprivnica-Krizevci county'),
    '07' => t('Bjelovar-Bilogora county'),
    '08' => t('Primorje-Gorski Kotar county'),
    '09' => t('Lika-Senj county'),
    '10' => t('Virovitica-Podravina county'),
    '11' => t('Pozega-Slavonia county'),
    '12' => t('Brod-Posavina county'),
    '13' => t('Zadar county'),
    '14' => t('Osijek-Baranja county'),
    '15' => t('Sibenik-Knin county'),
    '16' => t('Vukovar-Srijem county'),
    '17' => t('Split-Dalmatia county'),
    '18' => t('Istria county'),
    '19' => t('Dubrovnik-Neretva county'),
    '20' => t('Medjimurje county'),
    '21' => t('Zagreb (city)')
  );
}
