<?php

/**
 * @file
 * "Russian Federation" specific data
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
function addresses_province_list_ru() {
  return array(
    'AD' => t('Adygeya'),
    'BA' => t('Bashkortostan'),
    'BU' => t('Buryatia'),
    'AL' => t('Altai Republic'),
    'DA' => t('Dagestan'),
    'IN' => t('Ingushetia'),
    'KB' => t('Kabardino-Balkaria'),
    'KL' => t('Kalmykia'),
    'KC' => t('Karachay-Cherkessia'),
    'KR' => t('Karelia'),
    'KO' => t('Komi'),
    'ME' => t('Mari El'),
    'MO' => t('Mordovia'),
    'SA' => t('Sakha'),
    'SE' => t('North Ossetia'),
    'TA' => t('Tatarstan'),
    'TY' => t('Tuva'),
    'UD' => t('Udmurtia'),
    'KK' => t('Khakassia'),
    'CE' => t('Chechnya'),
    'CU' => t('Chuvashia'),
    'ALT' => t('Altai Krai'),
    'KDA' => t('Krasnodar'),
    'KYA' => t('Krasnoyarsk'),
    'PRI' => t('Primorsky'),
    'STA' => t('Stavropol'),
    'KHA' => t('Khabarovsk'),
    'AMU' => t('Amur'),
    'ARK' => t('Arkhangelsk'),
    'AST' => t('Astrakhan'),
    'BEL' => t('Belgorod'),
    'BRY' => t('Bryansk'),
    'VLA' => t('Vladimir'),
    'VGG' => t('Volgograd'),
    'VLG' => t('Vologda'),
    'VOR' => t('Voronezh'),
    'IVA' => t('Ivanovo'),
    'IRK' => t('Irkutsk'),
    'KGD' => t('Kaliningrad'),
    'KLU' => t('Kaluga'),
    'KAM' => t('Kamchatka'),
    'KEM' => t('Kemerovo'),
    'KIR' => t('Kirov'),
    'KOS' => t('Kostroma'),
    'KGN' => t('Kurgan'),
    'KRS' => t('Kursk'),
    'LEN' => t('Leningrad'),
    'LIP' => t('Lipetsk'),
    'MAG' => t('Magadan'),
    'MOS' => t('Moscow (Province)'),
    'MUR' => t('Murmansk'),
    'NIZ' => t('Nizhny Novgorod'),
    'NGR' => t('Novgorod'),
    'NVS' => t('Novosibirsk'),
    'OMS' => t('Omsk'),
    'ORE' => t('Orenburg'),
    'ORL' => t('Oryol'),
    'PNZ' => t('Penza'),
    'PER' => t('Perm'),
    'PSK' => t('Pskov'),
    'ROS' => t('Rostov'),
    'RYA' => t('Ryazan'),
    'SAM' => t('Samara'),
    'SAR' => t('Saratov'),
    'SAK' => t('Sakhalin'),
    'SVE' => t('Sverdlovsk'),
    'SMO' => t('Smolensk'),
    'TAM' => t('Tambov'),
    'TVE' => t('Tver'),
    'TOM' => t('Tomsk'),
    'TUL' => t('Tula'),
    'TYU' => t('Tyumen'),
    'ULY' => t('Ulynovsk'),
    'CHE' => t('Chelyabinsk'),
    'CHI' => t('Chita'),
    'YAR' => t('Yaroslavl'),
    'MOW' => t('Moscow (City)'),
    'SPE' => t('St. Petersburg'),
    'YEV' => t('Jewish Oblast'),
    'AGB' => t('Aga Buryatia'),
    'KOP' => t('Permyakia'),
    'KOR' => t('Koryakia'),
    'NEN' => t('Nenetsia'),
    'TAY' => t('Taymyria'),
    'UOB' => t('Ust-Orda Buryatia'),
    'KHM' => t('Khantia-Mansia'),
    'CHU' => t('Chukotka'),
    'EVE' => t('Evenkia'),
    'YAN' => t('Yamalia')
  );
}
