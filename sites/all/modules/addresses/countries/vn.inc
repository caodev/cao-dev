<?php

/**
 * @file
 * "Vietnam" specific data
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
function addresses_province_list_vn() {
  return array(
    'AG' => t('An Giang'),
    'BG' => t('Bac Giang'),
    'BK' => t('Bac Kan'),
    'BL' => t('Bac Lieu'),
    'BC' => t('Bac Ninh'),
    'BR' => t('Ba Ria-Vung Tau'),
    'BN' => t('Ben Tre'),
    'BH' => t('Binh Dinh'),
    'BU' => t('Binh Duong'),
    'BP' => t('Binh Phuoc'),
    'BT' => t('Binh Thuan'),
    'CM' => t('Ca Mau'),
    'CT' => t('Can Tho'),
    'CB' => t('Cao Bang'),
    'DL' => t('Dak Lak'),
    'DG' => t('Dak Nong'),
    'DN' => t('Da Nang'),
    'DB' => t('Dien Bien'),
    'DI' => t('Dong Nai'),
    'DT' => t('Dong Thap'),
    'GL' => t('Gia Lai'),
    'HG' => t('Ha Giang'),
    'HD' => t('Hai Duong'),
    'HP' => t('Hai Phong'),
    'HM' => t('Ha Nam'),
    'HI' => t('Ha Noi'),
    'HT' => t('Ha Tay'),
    'HH' => t('Ha Tinh'),
    'HB' => t('Hoa Binh'),
    'HC' => t('Ho Chin Minh'),
    'HU' => t('Hau Giang'),
    'HY' => t('Hung Yen')
  );
}
