<?php

/**
 * @file
 * "Uganda" specific data
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
function addresses_province_list_ug() {
  return array(
    'KAL' => t('Kalangala'),
    'KMP' => t('Kampala'),
    'KAY' => t('Kayunga'),
    'KIB' => t('Kiboga'),
    'LUW' => t('Luwero'),
    'MAS' => t('Masaka'),
    'MPI' => t('Mpigi'),
    'MUB' => t('Mubende'),
    'MUK' => t('Mukono'),
    'NKS' => t('Nakasongola'),
    'RAK' => t('Rakai'),
    'SEM' => t('Sembabule'),
    'WAK' => t('Wakiso'),
    'BUG' => t('Bugiri'),
    'BUS' => t('Busia'),
    'IGA' => t('Iganga'),
    'JIN' => t('Jinja'),
    'KAB' => t('Kaberamaido'),
    'KML' => t('Kamuli'),
    'KPC' => t('Kapchorwa'),
    'KTK' => t('Katakwi'),
    'KUM' => t('Kumi'),
    'MAY' => t('Mayuge'),
    'MBA' => t('Mbale'),
    'PAL' => t('Pallisa'),
    'SIR' => t('Sironko'),
    'SOR' => t('Soroti'),
    'TOR' => t('Tororo'),
    'ADJ' => t('Adjumani'),
    'APC' => t('Apac'),
    'ARU' => t('Arua'),
    'GUL' => t('Gulu'),
    'KIT' => t('Kitgum'),
    'KOT' => t('Kotido'),
    'LIR' => t('Lira'),
    'MRT' => t('Moroto'),
    'MOY' => t('Moyo'),
    'NAK' => t('Nakapiripirit'),
    'NEB' => t('Nebbi'),
    'PAD' => t('Pader'),
    'YUM' => t('Yumbe'),
    'BUN' => t('Bundibugyo'),
    'BSH' => t('Bushenyi'),
    'HOI' => t('Hoima'),
    'KBL' => t('Kabale'),
    'KAR' => t('Kabarole'),
    'KAM' => t('Kamwenge'),
    'KAN' => t('Kanungu'),
    'KAS' => t('Kasese'),
    'KBA' => t('Kibaale'),
    'KIS' => t('Kisoro'),
    'KYE' => t('Kyenjojo'),
    'MSN' => t('Masindi'),
    'MBR' => t('Mbarara'),
    'NTU' => t('Ntungamo'),
    'RUK' => t('Rukungiri')
  );
}
