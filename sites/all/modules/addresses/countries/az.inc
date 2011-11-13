<?php

/**
 * @file
 * "Azerbaijan" specific data
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
function addresses_province_list_az() {
  return array(
    'AB' => t('Ali Bayramli'),
    'ABS' => t('Abseron'),
    'AGC' => t('AgcabAdi'),
    'AGM' => t('Agdam'),
    'AGS' => t('Agdas,'),
    'AGA' => t('Agstafa'),
    'AGU' => t('Agsu'),
    'AST' => t('Astara'),
    'BA'  => t('Baki'),
    'BAB' => t('BabAk'),
    'BAL' => t('BalakAn'),
    'BAR' => t('BArdA'),
    'BEY' => t('Beylaqan'),
    'BIL' => t('Bilasuvar'),
    'CAB' => t('Cabrayil'),
    'CAL' => t('Calilabab'),
    'CUL' => t('Culfa'),
    'DAS' => t('Daskasan'),
    'DAV' => t('Davaci'),
    'FUZ' => t('Fuzuli'),
    'GA'  => t('Ganca'),
    'GAD' => t('Gadabay'),
    'GOR' => t('Goranboy'),
    'GOY' => t('Goycay'),
    'HAC' => t('Haciqabul'),
    'IMI' => t('Imisli'),
    'ISM' => t('Ismayilli'),
    'KAL' => t('Kalbacar'),
    'KUR' => t('Kurdamir'),
    'LA'  => t('Lankaran'),
    'LAC' => t('Lacin'),
    'LAN' => t('Lankaran'),
    'LER' => t('Lerik'),
    'MAS' => t('Masalli'),
    'MI'  => t('Mingacevir'),
    'NA'  => t('Naftalan'),
    'NEF' => t('Neftcala'),
    'OGU' => t('Oguz'),
    'ORD' => t('Ordubad'),
    'QAB' => t('Qabala'),
    'QAX' => t('Qax'),
    'QAZ' => t('Qazax'),
    'QOB' => t('Qobustan'),
    'QBA' => t('Quba'),
    'QBI' => t('Qubadli'),
    'QUS' => t('Qusar'),
    'SA'  => t('Saki'),
    'SAT' => t('Saatli'),
    'SAB' => t('Sabirabad'),
    'SAD' => t('Sadarak'),
    'SAH' => t('Sahbuz'),
    'SAK' => t('Saki'),
    'SAL' => t('Salyan'),
    'SM'  => t('Sumqayit'),
    'SMI' => t('Samaxi'),
    'SKR' => t('Samkir'),
    'SMX' => t('Samux'),
    'SAR' => t('Sarur'),
    'SIY' => t('Siyazan'),
    'SS'  => t('Susa'),
    'SUS' => t('Susa'),
    'TAR' => t('Tartar'),
    'TOV' => t('Tovuz'),
    'UCA' => t('Ucar'),
    'XA'  => t('Xankandi'),
    'XAC' => t('Xacmaz'),
    'XAN' => t('Xanlar'),
    'XIZ' => t('Xizi'),
    'XCI' => t('Xocali'),
    'XVD' => t('Xocavand'),
    'YAR' => t('Yardimli'),
    'YEV' => t('Yevlax'),
    'ZAN' => t('Zangilan'),
    'ZAQ' => t('Zaqatala'),
    'ZAR' => t('Zardab'),
    'NX'  => t('Naxcivan')
  );
}
