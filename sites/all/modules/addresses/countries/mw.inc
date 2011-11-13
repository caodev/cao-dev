<?php

/**
 * @file
 * "Malawi" specific data
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
function addresses_province_list_mw() {
  return array(
    'BLK' => t('Balaka'),
    'BLT' => t('Blantyre'),
    'CKW' => t('Chikwawa'),
    'CRD' => t('Chiradzulu'),
    'CTP' => t('Chitipa'),
    'DDZ' => t('Dedza'),
    'DWA' => t('Dowa'),
    'KRG' => t('Karonga'),
    'KSG' => t('Kasungu'),
    'LKM' => t('Likoma'),
    'LLG' => t('Lilongwe'),
    'MCG' => t('Machinga'),
    'MGC' => t('Mangochi'),
    'MCH' => t('Mchinji'),
    'MLJ' => t('Mulanje'),
    'MWZ' => t('Mwanza'),
    'MZM' => t('Mzimba'),
    'NTU' => t('Ntcheu'),
    'NKB' => t('Nkhata Bay'),
    'NKH' => t('Nkhotakota'),
    'NSJ' => t('Nsanje'),
    'NTI' => t('Ntchisi'),
    'PHL' => t('Phalombe'),
    'RMP' => t('Rumphi'),
    'SLM' => t('Salima'),
    'THY' => t('Thyolo'),
    'ZBA' => t('Zomba')
  );
}
