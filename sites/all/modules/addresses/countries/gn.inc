<?php

/**
 * @file
 * "Guinea" specific data
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
function addresses_province_list_gn() {
  return array(
    'CNK' => t('Conakry'),
    'BYL' => t('Beyla'),
    'BFA' => t('Boffa'),
    'BOK' => t('Boke'),
    'COY' => t('Coyah'),
    'DBL' => t('Dabola'),
    'DLB' => t('Dalaba'),
    'DGR' => t('Dinguiraye'),
    'DBR' => t('Dubreka'),
    'FRN' => t('Faranah'),
    'FRC' => t('Forecariah'),
    'FRI' => t('Fria'),
    'GAO' => t('Gaoual'),
    'GCD' => t('Gueckedou'),
    'KNK' => t('Kankan'),
    'KRN' => t('Kerouane'),
    'KND' => t('Kindia'),
    'KSD' => t('Kissidougou'),
    'KBA' => t('Koubia'),
    'KDA' => t('Koundara'),
    'KRA' => t('Kouroussa'),
    'LAB' => t('Labe'),
    'LLM' => t('Lelouma'),
    'LOL' => t('Lola'),
    'MCT' => t('Macenta'),
    'MAL' => t('Mali'),
    'MAM' => t('Mamou'),
    'MAN' => t('Mandiana'),
    'NZR' => t('Nzerekore'),
    'PIT' => t('Pita'),
    'SIG' => t('Siguiri'),
    'TLM' => t('Telimele'),
    'TOG' => t('Tougue'),
    'YOM' => t('Yomou')
  );
}
