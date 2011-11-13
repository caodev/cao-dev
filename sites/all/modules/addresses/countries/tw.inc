<?php

/**
 * @file
 * "Taiwan, Province of China" specific data
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
function addresses_province_list_tw() {
  return array(
    'CH' => t('Chang-hua'),
    'CI' => t('Chia-i'),
    'HS' => t('Hsin-chu'),
    'HL' => t('Hua-lien'),
    'IL' => t('I-lan'),
    'KH' => t('Kao-hsiung county'),
    'KM' => t('Kin-men'),
    'LC' => t('Lien-chiang'),
    'ML' => t('Miao-li'),
    'NT' => t("Nan-t'ou"),
    'PH' => t("P'eng-hu"),
    'PT' => t("P'ing-tung"),
    'TG' => t("T'ai-chung"),
    'TA' => t("T'ai-nan"),
    'TP' => t("T'ai-pei county"),
    'TT' => t("T'ai-tung"),
    'TY' => t("T'ao-yuan"),
    'YL' => t('Yun-lin'),
    'CC' => t('Chia-i city'),
    'CL' => t('Chi-lung'),
    'HC' => t('Hsin-chu'),
    'TH' => t("T'ai-chung"),
    'TN' => t("T'ai-nan"),
    'KC' => t('Kao-hsiung city'),
    'TC' => t("T'ai-pei city")
  );
}
