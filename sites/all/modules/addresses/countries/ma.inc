<?php

/**
 * @file
 * "Morocco" specific data
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
function addresses_province_list_ma() {
  return array(
    'AGD' => t('Agadir'),
    'HOC' => t('Al Hoceima'),
    'AZI' => t('Azilal'),
    'BME' => t('Beni Mellal'),
    'BSL' => t('Ben Slimane'),
    'BLM' => t('Boulemane'),
    'CBL' => t('Casablanca'),
    'CHA' => t('Chaouen'),
    'EJA' => t('El Jadida'),
    'EKS' => t('El Kelaa des Sraghna'),
    'ERA' => t('Er Rachidia'),
    'ESS' => t('Essaouira'),
    'FES' => t('Fes'),
    'FIG' => t('Figuig'),
    'GLM' => t('Guelmim'),
    'IFR' => t('Ifrane'),
    'KEN' => t('Kenitra'),
    'KHM' => t('Khemisset'),
    'KHN' => t('Khenifra'),
    'KHO' => t('Khouribga'),
    'LYN' => t('Laayoune'),
    'LAR' => t('Larache'),
    'MRK' => t('Marrakech'),
    'MKN' => t('Meknes'),
    'NAD' => t('Nador'),
    'ORZ' => t('Ouarzazate'),
    'OUJ' => t('Oujda'),
    'RSA' => t('Rabat-Sale'),
    'SAF' => t('Safi'),
    'SET' => t('Settat'),
    'SKA' => t('Sidi Kacem'),
    'TGR' => t('Tangier'),
    'TAN' => t('Tan-Tan'),
    'TAO' => t('Taounate'),
    'TRD' => t('Taroudannt'),
    'TAT' => t('Tata'),
    'TAZ' => t('Taza'),
    'TET' => t('Tetouan'),
    'TIZ' => t('Tiznit'),
    'ADK' => t('Ad Dakhla'),
    'BJD' => t('Boujdour'),
    'ESM' => t('Es Smara')
  );
}
