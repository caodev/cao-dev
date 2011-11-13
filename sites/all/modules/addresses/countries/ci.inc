<?php

/**
 * @file
 * "Cote D'Ivoire" specific data
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
function addresses_province_list_ci() {
  return array(
    'ABE' => t('Abengourou'),
    'ABI' => t('Abidjan'),
    'ABO' => t('Aboisso'),
    'ADI' => t('Adiake'),
    'ADZ' => t('Adzope'),
    'AGB' => t('Agboville'),
    'AGN' => t('Agnibilekrou'),
    'ALE' => t('Alepe'),
    'BOC' => t('Bocanda'),
    'BAN' => t('Bangolo'),
    'BEO' => t('Beoumi'),
    'BIA' => t('Biankouma'),
    'BDK' => t('Bondoukou'),
    'BGN' => t('Bongouanou'),
    'BFL' => t('Bouafle'),
    'BKE' => t('Bouake'),
    'BNA' => t('Bouna'),
    'BDL' => t('Boundiali'),
    'DKL' => t('Dabakala'),
    'DBU' => t('Dabou'),
    'DAL' => t('Daloa'),
    'DAN' => t('Danane'),
    'DAO' => t('Daoukro'),
    'DIM' => t('Dimbokro'),
    'DIV' => t('Divo'),
    'DUE' => t('Duekoue'),
    'FER' => t('Ferkessedougou'),
    'GAG' => t('Gagnoa'),
    'GBA' => t('Grand-Bassam'),
    'GLA' => t('Grand-Lahou'),
    'GUI' => t('Guiglo'),
    'ISS' => t('Issia'),
    'JAC' => t('Jacqueville'),
    'KAT' => t('Katiola'),
    'KOR' => t('Korhogo'),
    'LAK' => t('Lakota'),
    'MAN' => t('Man'),
    'MKN' => t('Mankono'),
    'MBA' => t('Mbahiakro'),
    'ODI' => t('Odienne'),
    'OUM' => t('Oume'),
    'SAK' => t('Sakassou'),
    'SPE' => t('San-Pedro'),
    'SAS' => t('Sassandra'),
    'SEG' => t('Seguela'),
    'SIN' => t('Sinfra'),
    'SOU' => t('Soubre'),
    'TAB' => t('Tabou'),
    'TAN' => t('Tanda'),
    'TIE' => t('Tiebissou'),
    'TIN' => t('Tingrela'),
    'TIA' => t('Tiassale'),
    'TBA' => t('Touba'),
    'TLP' => t('Toulepleu'),
    'TMD' => t('Toumodi'),
    'VAV' => t('Vavoua'),
    'YAM' => t('Yamoussoukro'),
    'ZUE' => t('Zuenoula')
  );
}
