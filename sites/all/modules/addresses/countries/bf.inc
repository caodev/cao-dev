<?php

/**
 * @file
 * "Burkina Faso" specific data
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
function addresses_province_list_bf() {
  return array(
    'BAL' => t('Bale'),
    'BAM' => t('Bam'),
    'BAN' => t('Banwa'),
    'BAZ' => t('Bazega'),
    'BOR' => t('Bougouriba'),
    'BLG' => t('Boulgou'),
    'BOK' => t('Boulkiemde'),
    'COM' => t('Comoe'),
    'GAN' => t('Ganzourgou'),
    'GNA' => t('Gnagna'),
    'GOU' => t('Gourma'),
    'HOU' => t('Houet'),
    'IOA' => t('Ioba'),
    'KAD' => t('Kadiogo'),
    'KEN' => t('Kenedougou'),
    'KOD' => t('Komondjari'),
    'KOP' => t('Kompienga'),
    'KOS' => t('Kossi'),
    'KOL' => t('Koulpelogo'),
    'KOT' => t('Kouritenga'),
    'KOW' => t('Kourweogo'),
    'LER' => t('Leraba'),
    'LOR' => t('Loroum'),
    'MOU' => t('Mouhoun'),
    'NAH' => t('Nahouri'),
    'NAM' => t('Namentenga'),
    'NAY' => t('Nayala'),
    'NOU' => t('Noumbiel'),
    'OUB' => t('Oubritenga'),
    'OUD' => t('Oudalan'),
    'PAS' => t('Passore'),
    'PON' => t('Poni'),
    'SAG' => t('Sanguie'),
    'SAM' => t('Sanmatenga'),
    'SEN' => t('Seno'),
    'SIS' => t('Sissili'),
    'SOM' => t('Soum'),
    'SOR' => t('Sourou'),
    'TAP' => t('Tapoa'),
    'TUY' => t('Tuy'),
    'YAG' => t('Yagha'),
    'YAT' => t('Yatenga'),
    'ZIR' => t('Ziro'),
    'ZOD' => t('Zondoma'),
    'ZOW' => t('Zoundweogo')
  );
}
