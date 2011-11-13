<?php

/**
 * @file
 * "Thailand" specific data
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
function addresses_province_list_th() {
  return array(
    '10' => t('Bangkok'),
    '11' => t('Samut Prakan'),
    '12' => t('Nonthaburi'),
    '13' => t('Pathum Thani'),
    '14' => t('Phra Nakhon Si Ayutthaya'),
    '15' => t('Ang Thong'),
    '16' => t('Lop Buri'),
    '17' => t('Sing Buri'),
    '18' => t('Chai Nat'),
    '19' => t('Saraburi'),
    '20' => t('Chon Buri'),
    '21' => t('Rayong'),
    '22' => t('Chanthaburi'),
    '23' => t('Trat'),
    '24' => t('Chachoengsao'),
    '25' => t('Prachin Buri'),
    '26' => t('Nakhon Nayok'),
    '27' => t('Sa Kaeo'),
    '30' => t('Nakhon Ratchasima'),
    '31' => t('Buri Ram'),
    '32' => t('Surin'),
    '33' => t('Si Sa Ket'),
    '34' => t('Ubon Ratchathani'),
    '35' => t('Yasothon'),
    '36' => t('Chaiyaphum'),
    '37' => t('Amnat Charoen'),
    '39' => t('Nong Bua Lam Phu'),
    '40' => t('Khon Kaen'),
    '41' => t('Udon Thani'),
    '42' => t('Loei'),
    '43' => t('Nong Khai'),
    '44' => t('Maha Sarakham'),
    '45' => t('Roi Et'),
    '46' => t('Kalasin'),
    '47' => t('Sakon Nakhon'),
    '48' => t('Nakhon Phanom'),
    '49' => t('Mukdahan'),
    '50' => t('Chiang Mai'),
    '51' => t('Lamphun'),
    '52' => t('Lampang'),
    '53' => t('Uttaradit'),
    '54' => t('Phrae'),
    '55' => t('Nan'),
    '56' => t('Phayao'),
    '57' => t('Chiang Rai'),
    '58' => t('Mae Hong Son'),
    '60' => t('Nakhon Sawan'),
    '61' => t('Uthai Thani'),
    '62' => t('Kamphaeng Phet'),
    '63' => t('Tak'),
    '64' => t('Sukhothai'),
    '65' => t('Phitsanulok'),
    '66' => t('Phichit'),
    '70' => t('Ratchaburi'),
    '71' => t('Kanchanaburi'),
    '72' => t('Suphanburi'),
    '73' => t('Nakhon Pathom'),
    '74' => t('Samut Sakhon'),
    '75' => t('Samut Songkhram'),
    '76' => t('Phetchabun'),
    '78' => t('Phetchaburi'),
    '77' => t('Prachuap Khiri Khan'),
    '80' => t('Nakhon Si Thammarat'),
    '81' => t('Krabi'),
    '82' => t('Phang Nga'),
    '83' => t('Phuket'),
    '84' => t('Surat Thani'),
    '85' => t('Ranong'),
    '86' => t('Chumpon'),
    '90' => t('Songkhla'),
    '91' => t('Satun'),
    '92' => t('Trang'),
    '93' => t('Phattalung'),
    '94' => t('Pattani'),
    '95' => t('Yala'),
    '96' => t('Narathiwat'),
    'S' => t('Pattaya')
  );
}
