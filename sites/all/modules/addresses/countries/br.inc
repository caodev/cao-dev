<?php

/**
 * @file
 * "Brazil" specific data
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
function addresses_province_list_br() {
  return array(
    'AC' => t('Acre'),
    'AL' => t('Alagoas'),
    'AM' => t('Amazonas'),
    'AP' => t('Amapa'),
    'BA' => t('Bahia'),
    'CE' => t('Ceara'),
    'DF' => t('Distrito Federal'),
    'ES' => t('Espirito Santo'),
    'GO' => t('Goias'),
    'MA' => t('Maranhao'),
    'MG' => t('Minas Gerais'),
    'MS' => t('Mato Grosso do Sul'),
    'MT' => t('Mato Grosso'),
    'PA' => t('Para'),
    'PB' => t('Paraiba'),
    'PE' => t('Pernambuco'),
    'PI' => t('Piaui'),
    'PR' => t('Parana'),
    'RJ' => t('Rio de Janeiro'),
    'RN' => t('Rio Grande do Norte'),
    'RO' => t('Rondonia'),
    'RR' => t('Roraima'),
    'RS' => t('Rio Grande do Sul'),
    'SC' => t('Santa Catarina'),
    'SE' => t('Sergipe'),
    'SP' => t('Sao Paulo'),
    'TO' => t('Tocantins')
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
function addresses_address_format_br() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_street_hcard]
[addresses_additional_hcard]
[addresses_city_hcard] [addresses_province_name_hcard]
[addresses_country_name_hcard]
[addresses_postal_code_hcard]';
}
