<?php

/**
 * @file
 * "China" specific data
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
function addresses_province_list_cn() {
  return array(
    '11' => t('Beijing'),
    '12' => t('Tianjin'),
    '13' => t('Hebei'),
    '14' => t('Shanxi'),
    '15' => t('Nei Mongol'),
    '21' => t('Liaoning'),
    '22' => t('Jilin'),
    '23' => t('Heilongjiang'),
    '31' => t('Shanghai'),
    '32' => t('Jiangsu'),
    '33' => t('Zhejiang'),
    '34' => t('Anhui'),
    '35' => t('Fujian'),
    '36' => t('Jiangxi'),
    '37' => t('Shandong'),
    '41' => t('Henan'),
    '42' => t('Hubei'),
    '43' => t('Hunan'),
    '44' => t('Guangdong'),
    '45' => t('Guangxi'),
    '46' => t('Hainan'),
    '51' => t('Sichuan'),
    '52' => t('Guizhou'),
    '53' => t('Yunnan'),
    '54' => t('Xizang Zizhiqu (Tibet)'),
    '61' => t('Shaanxi'),
    '62' => t('Gansu'),
    '63' => t('Qinghai'),
    '64' => t('Ningxia'),
    '65' => t('Xinjiang'),
    '71' => t('Taiwan'),
    '91' => t('Xianggang'),
    '92' => t('Aomen'),
    '97' => t('Chongqing'),
    '98' => t('Gaoxiong'),
    '99' => t('Taibei')
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
function addresses_address_format_cn() {
  return '[addresses_aname_hcard] [addresses_is_primary_hcard]
[addresses_additional_hcard]
[addresses_street_hcard], [addresses_city_hcard]
[addresses_postal_code_hcard], [addresses_province_name_hcard]
[addresses_country_name_hcard]';
}
