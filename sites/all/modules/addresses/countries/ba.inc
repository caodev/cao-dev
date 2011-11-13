<?php

/**
 * @file
 * "Bosnia and Herzegovina" specific data
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
function addresses_province_list_ba() {
  return array(
    'BRO' => t('Brcko district'),
    'FUS' => t('Unsko-Sanski Kanton'),
    'FPO' => t('Posavski Kanton'),
    'FTU' => t('Tuzlanski Kanton'),
    'FZE' => t('Zenicko-Dobojski Kanton'),
    'FBP' => t('Bosanskopodrinjski Kanton'),
    'FSB' => t('Srednjebosanski Kanton'),
    'FHN' => t('Hercegovacko-neretvanski Kanton'),
    'FZH' => t('Zapadnohercegovacka Zupanija'),
    'FSA' => t('Kanton Sarajevo'),
    'FZA' => t('Zapadnobosanska'),
    'SBL' => t('Banja Luka'),
    'SDO' => t('Doboj'),
    'SBI' => t('Bijeljina'),
    'SVL' => t('Vlasenica'),
    'SSR' => t('Sarajevo-Romanija or Sokolac'),
    'SFO' => t('Foca'),
    'STR' => t('Trebinje')
  );
}
