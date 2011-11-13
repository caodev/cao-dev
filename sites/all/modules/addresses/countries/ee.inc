<?php

/**
 * @file
 * "Estonia" specific data
 */

/**
 * Implementation of hook_province_list().
 *
 * Its a hook from äddresses module to list all
 * states/provinces/teritories of a given country
 *
 * @return
 *   ärray. states where the keys are the state
 *   code and the value is the state name
 */
function addresses_province_list_ee() {
  return array(
    '37' => t('Harju County'),
    '39' => t('Hiiu County'),
    '44' => t('Ida-Viru County'),
    '49' => t('Jõgeva County'),
    '51' => t('Järva County'),
    '57' => t('Lääne County'),
    '59' => t('Lääne-Viru County'),
    '65' => t('Põlva County'),
    '67' => t('Pärnu County'),
    '70' => t('Rapla County'),
    '74' => t('Saare County'),
    '78' => t('Tartu County'),
    '82' => t('Valga County'),
    '84' => t('Viljandi County'),
    '86' => t('Võru County')
  );
}
