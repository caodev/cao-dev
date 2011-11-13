<?php

/**
 * @file
 * "Philippines" specific data
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
function addresses_province_list_ph() {
  return array(
    'ABR' => t('Abra'),
    'ANO' => t('Agusan del Norte'),
    'ASU' => t('Agusan del Sur'),
    'AKL' => t('Aklan'),
    'ALB' => t('Albay'),
    'ANT' => t('Antique'),
    'APY' => t('Apayao'),
    'AUR' => t('Aurora'),
    'BAS' => t('Basilan'),
    'BTA' => t('Bataan'),
    'BTE' => t('Batanes'),
    'BTG' => t('Batangas'),
    'BLR' => t('Biliran'),
    'BEN' => t('Benguet'),
    'BOL' => t('Bohol'),
    'BUK' => t('Bukidnon'),
    'BUL' => t('Bulacan'),
    'CAG' => t('Cagayan'),
    'CNO' => t('Camarines Norte'),
    'CSU' => t('Camarines Sur'),
    'CAM' => t('Camiguin'),
    'CAP' => t('Capiz'),
    'CAT' => t('Catanduanes'),
    'CAV' => t('Cavite'),
    'CEB' => t('Cebu'),
    'CMP' => t('Compostela'),
    'DNO' => t('Davao del Norte'),
    'DSU' => t('Davao del Sur'),
    'DOR' => t('Davao Oriental'),
    'ESA' => t('Eastern Samar'),
    'GUI' => t('Guimaras'),
    'IFU' => t('Ifugao'),
    'INO' => t('Ilocos Norte'),
    'ISU' => t('Ilocos Sur'),
    'ILO' => t('Iloilo'),
    'ISA' => t('Isabela'),
    'KAL' => t('Kalinga'),
    'LAG' => t('Laguna'),
    'LNO' => t('Lanao del Norte'),
    'LSU' => t('Lanao del Sur'),
    'UNI' => t('La Union'),
    'LEY' => t('Leyte'),
    'MAG' => t('Maguindanao'),
    'MRN' => t('Marinduque'),
    'MSB' => t('Masbate'),
    'MIC' => t('Mindoro Occidental'),
    'MIR' => t('Mindoro Oriental'),
    'MSC' => t('Misamis Occidental'),
    'MOR' => t('Misamis Oriental'),
    'MOP' => t('Mountain Province'),
    'NCR' => t('National Capital Region'),
    'NOC' => t('Negros Occidental'),
    'NOR' => t('Negros Oriental'),
    'NCT' => t('North Cotabato'),
    'NSM' => t('Northern Samar'),
    'NEC' => t('Nueva Ecija'),
    'NVZ' => t('Nueva Vizcaya'),
    'PLW' => t('Palawan'),
    'PMP' => t('Pampanga'),
    'PNG' => t('Pangasinan'),
    'QZN' => t('Quezon'),
    'QRN' => t('Quirino'),
    'RIZ' => t('Rizal'),
    'ROM' => t('Romblon'),
    'SMR' => t('Samar'),
    'SRG' => t('Sarangani'),
    'SQJ' => t('Siquijor'),
    'SRS' => t('Sorsogon'),
    'SCO' => t('South Cotabato'),
    'SLE' => t('Southern Leyte'),
    'SKU' => t('Sultan Kudarat'),
    'SLU' => t('Sulu'),
    'SNO' => t('Surigao del Norte'),
    'SSU' => t('Surigao del Sur'),
    'TAR' => t('Tarlac'),
    'TAW' => t('Tawi-Tawi'),
    'ZBL' => t('Zambales'),
    'ZNO' => t('Zamboanga del Norte'),
    'ZSU' => t('Zamboanga del Sur'),
    'ZSI' => t('Zamboanga Sibugay')
  );
}
