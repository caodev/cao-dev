<?php

/**
 * @file
 * "Malta" specific data
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
function addresses_province_list_mt() {
  return array(
    'ATT' => t('Attard'),
    'BAL' => t('Balzan'),
    'BGU' => t('Birgu'),
    'BKK' => t('Birkirkara'),
    'BRZ' => t('Birzebbuga'),
    'BOR' => t('Bormla'),
    'DIN' => t('Dingli'),
    'FGU' => t('Fgura'),
    'FLO' => t('Floriana'),
    'GDJ' => t('Gudja'),
    'GZR' => t('Gzira'),
    'GRG' => t('Gargur'),
    'GXQ' => t('Gaxaq'),
    'HMR' => t('Hamrun'),
    'IKL' => t('Iklin'),
    'ISL' => t('Isla'),
    'KLK' => t('Kalkara'),
    'KRK' => t('Kirkop'),
    'LIJ' => t('Lija'),
    'LUQ' => t('Luqa'),
    'MRS' => t('Marsa'),
    'MKL' => t('Marsaskala'),
    'MXL' => t('Marsaxlokk'),
    'MDN' => t('Mdina'),
    'MEL' => t('Melliea'),
    'MGR' => t('Mgarr'),
    'MST' => t('Mosta'),
    'MQA' => t('Mqabba'),
    'MSI' => t('Msida'),
    'MTF' => t('Mtarfa'),
    'NAX' => t('Naxxar'),
    'PAO' => t('Paola'),
    'PEM' => t('Pembroke'),
    'PIE' => t('Pieta'),
    'QOR' => t('Qormi'),
    'QRE' => t('Qrendi'),
    'RAB' => t('Rabat'),
    'SAF' => t('Safi'),
    'SGI' => t('San Giljan'),
    'SLU' => t('Santa Lucija'),
    'SPB' => t('San Pawl il-Bahar'),
    'SGW' => t('San Gwann'),
    'SVE' => t('Santa Venera'),
    'SIG' => t('Siggiewi'),
    'SLM' => t('Sliema'),
    'SWQ' => t('Swieqi'),
    'TXB' => t('Ta Xbiex'),
    'TRX' => t('Tarxien'),
    'VLT' => t('Valletta'),
    'XGJ' => t('Xgajra'),
    'ZBR' => t('Zabbar'),
    'ZBG' => t('Zebbug'),
    'ZJT' => t('Zejtun'),
    'ZRQ' => t('Zurrieq'),
    'FNT' => t('Fontana'),
    'GHJ' => t('Ghajnsielem'),
    'GHR' => t('Gharb'),
    'GHS' => t('Ghasri'),
    'KRC' => t('Kercem'),
    'MUN' => t('Munxar'),
    'NAD' => t('Nadur'),
    'QAL' => t('Qala'),
    'VIC' => t('Victoria'),
    'SLA' => t('San Lawrenz'),
    'SNT' => t('Sannat'),
    'ZAG' => t('Xagra'),
    'XEW' => t('Xewkija'),
    'ZEB' => t('Zebbug')
  );
}
