<?php

/**
 * @file
 * "Italy" specific data
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
function addresses_province_list_it() {
  return array(
    'AG' => t('Agrigento'),
    'AL' => t('Alessandria'),
    'AN' => t('Ancona'),
    'AO' => t('Aosta'),
    'AR' => t('Arezzo'),
    'AP' => t('Ascoli Piceno'),
    'AT' => t('Asti'),
    'AV' => t('Avellino'),
    'BA' => t('Bari'),
    'BL' => t('Belluno'),
    'BN' => t('Benevento'),
    'BG' => t('Bergamo'),
    'BI' => t('Biella'),
    'BO' => t('Bologna'),
    'BZ' => t('Bolzano'),
    'BS' => t('Brescia'),
    'BR' => t('Brindisi'),
    'BT' => t('Barletta-Andria-Trani'),
    'CA' => t('Cagliari'),
    'CL' => t('Caltanissetta'),
    'CB' => t('Campobasso'),
    'CI' => t('Carbonia-Iglesias'),
    'CE' => t('Caserta'),
    'CT' => t('Catania'),
    'CZ' => t('Catanzaro'),
    'CH' => t('Chieti'),
    'CO' => t('Como'),
    'CS' => t('Cosenza'),
    'CR' => t('Cremona'),
    'KR' => t('Crotone'),
    'CN' => t('Cuneo'),
    'EN' => t('Enna'),
    'FM' => t('Fermo'),
    'FE' => t('Ferrara'),
    'FI' => t('Firenze'),
    'FG' => t('Foggia'),
    'FO' => t('Forlì-Cesena'),
    'FR' => t('Frosinone'),
    'GE' => t('Genova'),
    'GO' => t('Gorizia'),
    'GR' => t('Grosseto'),
    'IM' => t('Imperia'),
    'IS' => t('Isernia'),
    'AQ' => t("L'Aquila"),
    'SP' => t('La Spezia'),
    'LT' => t('Latina'),
    'LE' => t('Lecce'),
    'LC' => t('Lecco'),
    'LI' => t('Livorno'),
    'LO' => t('Lodi'),
    'LU' => t('Lucca'),
    'MC' => t('Macerata'),
    'MN' => t('Mantova'),
    'MS' => t('Massa-Carrara'),
    'MT' => t('Matera'),
    'VS' => t('Medio Campidano'),
    'ME' => t('Messina'),
    'MI' => t('Milano'),
    'MO' => t('Modena'),
    'MB' => t('Monza e Brianza'),
    'NA' => t('Napoli'),
    'NO' => t('Novara'),
    'NU' => t('Nuoro'),
    'OG' => t('Ogliastra'),
    'OT' => t('Olbia-Tempio'),
    'OR' => t('Oristano'),
    'PD' => t('Padova'),
    'PA' => t('Palermo'),
    'PR' => t('Parma'),
    'PV' => t('Pavia'),
    'PG' => t('Perugia'),
    'PU' => t('Pesaro e Urbino'),
    'PE' => t('Pescara'),
    'PC' => t('Piacenza'),
    'PI' => t('Pisa'),
    'PT' => t('Pistoia'),
    'PN' => t('Pordenone'),
    'PZ' => t('Potenza'),
    'PO' => t('Prato'),
    'RG' => t('Ragusa'),
    'RA' => t('Ravenna'),
    'RC' => t('Reggio Calabria'),
    'RE' => t('Reggio Emilia'),
    'RI' => t('Rieti'),
    'RN' => t('Rimini'),
    'RM' => t('Roma'),
    'RO' => t('Rovigo'),
    'SA' => t('Salerno'),
    'SS' => t('Sassari'),
    'SV' => t('Savona'),
    'SI' => t('Siena'),
    'SO' => t('Sondrio'),
    'SR' => t('Siracusa'),
    'TA' => t('Taranto'),
    'TE' => t('Teramo'),
    'TR' => t('Terni'),
    'TP' => t('Trapani'),
    'TN' => t('Trento'),
    'TV' => t('Treviso'),
    'TS' => t('Trieste'),
    'TO' => t('Torino'),
    'UD' => t('Udine'),
    'VA' => t('Varese'),
    'VE' => t('Venezia'),
    'VB' => t('Verbano-Cusio-Ossola'),
    'VC' => t('Vercelli'),
    'VR' => t('Verona'),
    'VV' => t('Vibo Valentia'),
    'VI' => t('Vicenza'),
    'VT' => t('Viterbo')
  );
}

/**
 * Implementation of hook_address_format().
 *
 * Format the address using local preferences. It uses
 * Token module to convert this tokens to their real values.
 *
 * @return
 *   String. The address field tokens
 */
function addresses_address_format_it() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard]
[addresses_postal_code_hcard] [addresses_city_hcard] [addresses_province_code_hcard]
[addresses_country_name_hcard]';
}
