<?php

/**
 * @file
 * "Algeria" specific data
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
function addresses_province_list_dz() {
  return array(
    'ADR' => t('Adrar'),
    'ADE' => t('Ain Defla'),
    'ATE' => t('Ain Temouchent'),
    'ALG' => t('Alger'),
    'ANN' => t('Annaba'),
    'BAT' => t('Batna'),
    'BEC' => t('Bechar'),
    'BEJ' => t('Bejaia'),
    'BIS' => t('Biskra'),
    'BLI' => t('Blida'),
    'BBA' => t('Bordj Bou Arreridj'),
    'BOA' => t('Bouira'),
    'BMD' => t('Boumerdes'),
    'CHL' => t('Chlef'),
    'CON' => t('Constantine'),
    'DJE' => t('Djelfa'),
    'EBA' => t('El Bayadh'),
    'EOU' => t('El Oued'),
    'ETA' => t('El Tarf'),
    'GHA' => t('Ghardaia'),
    'GUE' => t('Guelma'),
    'ILL' => t('Illizi'),
    'JIJ' => t('Jijel'),
    'KHE' => t('Khenchela'),
    'LAG' => t('Laghouat'),
    'MUA' => t('Muaskar'),
    'MED' => t('Medea'),
    'MIL' => t('Mila'),
    'MOS' => t('Mostaganem'),
    'MSI' => t("M'Sila"),
    'NAA' => t('Naama'),
    'ORA' => t('Oran'),
    'OUA' => t('Ouargla'),
    'OEB' => t('Oum el-Bouaghi'),
    'REL' => t('Relizane'),
    'SAI' => t('Saida'),
    'SET' => t('Setif'),
    'SBA' => t('Sidi Bel Abbes'),
    'SKI' => t('Skikda'),
    'SAH' => t('Souk Ahras'),
    'TAM' => t('Tamanghasset'),
    'TEB' => t('Tebessa'),
    'TIA' => t('Tiaret'),
    'TIN' => t('Tindouf'),
    'TIP' => t('Tipaza'),
    'TIS' => t('Tissemsilt'),
    'TOU' => t('Tizi Ouzou'),
    'TLE' => t('Tlemcen')
  );
}
