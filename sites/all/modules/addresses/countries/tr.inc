<?php

/**
 * @file
 * "Turkey" specific data
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
function addresses_province_list_tr() {
  return array(
    'ADA' => t('Adana'),
    'ADI' => t('Adiyaman'),
    'AFY' => t('Afyonkarahisar'),
    'AGR' => t('Agri'),
    'AKS' => t('Aksaray'),
    'AMA' => t('Amasya'),
    'ANK' => t('Ankara'),
    'ANT' => t('Antalya'),
    'ARD' => t('Ardahan'),
    'ART' => t('Artvin'),
    'AYI' => t('Aydin'),
    'BAL' => t('Balikesir'),
    'BAR' => t('Bartin'),
    'BAT' => t('Batman'),
    'BAY' => t('Bayburt'),
    'BIL' => t('Bilecik'),
    'BIN' => t('Bingol'),
    'BIT' => t('Bitlis'),
    'BOL' => t('Bolu'),
    'BRD' => t('Burdur'),
    'BRS' => t('Bursa'),
    'CKL' => t('Canakkale'),
    'CKR' => t('Cankiri'),
    'COR' => t('Corum'),
    'DEN' => t('Denizli'),
    'DIY' => t('Diyarbakir'),
    'DUZ' => t('Duzce'),
    'EDI' => t('Edirne'),
    'ELA' => t('Elazig'),
    'EZC' => t('Erzincan'),
    'EZR' => t('Erzurum'),
    'ESK' => t('Eskisehir'),
    'GAZ' => t('Gaziantep'),
    'GIR' => t('Giresun'),
    'GMS' => t('Gumushane'),
    'HKR' => t('Hakkari'),
    'HTY' => t('Hatay'),
    'IGD' => t('Igdir'),
    'ISP' => t('Isparta'),
    'IST' => t('Istanbul'),
    'IZM' => t('Izmir'),
    'KAH' => t('Kahramanmaras'),
    'KRB' => t('Karabuk'),
    'KRM' => t('Karaman'),
    'KRS' => t('Kars'),
    'KAS' => t('Kastamonu'),
    'KAY' => t('Kayseri'),
    'KLS' => t('Kilis'),
    'KRK' => t('Kirikkale'),
    'KLR' => t('Kirklareli'),
    'KRS' => t('Kirsehir'),
    'KOC' => t('Kocaeli'),
    'KON' => t('Konya'),
    'KUT' => t('Kutahya'),
    'MAL' => t('Malatya'),
    'MAN' => t('Manisa'),
    'MAR' => t('Mardin'),
    'MER' => t('Mersin'),
    'MUG' => t('Mugla'),
    'MUS' => t('Mus'),
    'NEV' => t('Nevsehir'),
    'NIG' => t('Nigde'),
    'ORD' => t('Ordu'),
    'OSM' => t('Osmaniye'),
    'RIZ' => t('Rize'),
    'SAK' => t('Sakarya'),
    'SAM' => t('Samsun'),
    'SAN' => t('Sanliurfa'),
    'SII' => t('Siirt'),
    'SIN' => t('Sinop'),
    'SIR' => t('Sirnak'),
    'SIV' => t('Sivas'),
    'TEL' => t('Tekirdag'),
    'TOK' => t('Tokat'),
    'TRA' => t('Trabzon'),
    'TUN' => t('Tunceli'),
    'USK' => t('Usak'),
    'VAN' => t('Van'),
    'YAL' => t('Yalova'),
    'YOZ' => t('Yozgat'),
    'ZON' => t('Zonguldak')
  );
}
