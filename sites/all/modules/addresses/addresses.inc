<?php
/**
 * @author Bruno Massa
 * @file
 * An implementation of a universal API for address manipulation.
 */

/**
 * List all countries on Planet! :)
 *
 * It uses the ISO notation.
 * See http://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
 * or http://www.iso.org/iso/country_codes/iso_3166_code_lists/english_country_names_and_code_elements.htm
 * for further info.
 *
 * @param $available
 *   Array (optional). A list of countries that are allowed.
 * @param $top_countries
 *   Array (optional). A list of countries to also display
 *   at the top of the list. (The rest of the list will still
 *   include those top countries.)
 * @param $upper
 *   Boolean (optional). When TRUE, the country codes will
 *   be totally in Upper Case. Its the default ISO code,
 *   but the files and function are all named with lower
 *   case, so its better to return lower case by default
 * @return
 *   Array. 'COUNTRY CODE' => 'COUNTRY NAME' pairs as layed out in
 *   ISO 3166-1 alpha-2
 */
function _addresses_country_get($available = array(), $top_countries = array(), $upper = FALSE) {
  $countries = array(
    'ad' => t('Andorra'),
    'ae' => t('United Arab Emirates'),
    'af' => t('Afghanistan'),
    'ag' => t('Antigua and Barbuda'),
    'ai' => t('Anguilla'),
    'al' => t('Albania'),
    'am' => t('Armenia'),
    'an' => t('Netherlands Antilles'),
    'ao' => t('Angola'),
    'aq' => t('Antarctica'),
    'ar' => t('Argentina'),
    'as' => t('American Samoa'),
    'at' => t('Austria'),
    'au' => t('Australia'),
    'aw' => t('Aruba'),
    'ax' => t('Aland Islands'),
    'az' => t('Azerbaijan'),
    'ba' => t('Bosnia and Herzegovina'),
    'bb' => t('Barbados'),
    'bd' => t('Bangladesh'),
    'be' => t('Belgium'),
    'bf' => t('Burkina Faso'),
    'bg' => t('Bulgaria'),
    'bh' => t('Bahrain'),
    'bi' => t('Burundi'),
    'bj' => t('Benin'),
    'bm' => t('Bermuda'),
    'bn' => t('Brunei'),
    'bo' => t('Bolivia'),
    'br' => t('Brazil'),
    'bs' => t('Bahamas'),
    'bt' => t('Bhutan'),
    'bv' => t('Bouvet Island'),
    'bw' => t('Botswana'),
    'by' => t('Belarus'),
    'bz' => t('Belize'),
    'ca' => t('Canada'),
    'cc' => t('Cocos (Keeling) Islands'),
    'cd' => t('Congo (Kinshasa)'),
    'cf' => t('Central African Republic'),
    'cg' => t('Congo (Brazzaville)'),
    'ch' => t('Switzerland'),
    'ci' => t('Ivory Coast'),
    'ck' => t('Cook Islands'),
    'cl' => t('Chile'),
    'cm' => t('Cameroon'),
    'cn' => t('China'),
    'co' => t('Colombia'),
    'cr' => t('Costa Rica'),
    'cs' => t('Serbia And Montenegro'),
    'cu' => t('Cuba'),
    'cv' => t('Cape Verde'),
    'cx' => t('Christmas Island'),
    'cy' => t('Cyprus'),
    'cz' => t('Czech Republic'),
    'de' => t('Germany'),
    'dj' => t('Djibouti'),
    'dk' => t('Denmark'),
    'dm' => t('Dominica'),
    'do' => t('Dominican Republic'),
    'dz' => t('Algeria'),
    'ec' => t('Ecuador'),
    'ee' => t('Estonia'),
    'eg' => t('Egypt'),
    'eh' => t('Western Sahara'),
    'er' => t('Eritrea'),
    'es' => t('Spain'),
    'et' => t('Ethiopia'),
    'fi' => t('Finland'),
    'fj' => t('Fiji'),
    'fk' => t('Falkland Islands'),
    'fm' => t('Micronesia'),
    'fo' => t('Faroe Islands'),
    'fr' => t('France'),
    'ga' => t('Gabon'),
    'gd' => t('Grenada'),
    'ge' => t('Georgia'),
    'gf' => t('French Guiana'),
    'gg' => t('Guernsey'),
    'gh' => t('Ghana'),
    'gi' => t('Gibraltar'),
    'gl' => t('Greenland'),
    'gm' => t('Gambia'),
    'gn' => t('Guinea'),
    'gp' => t('Guadeloupe'),
    'gq' => t('Equatorial Guinea'),
    'gr' => t('Greece'),
    'gs' => t('South Georgia and the South Sandwich Islands'),
    'gt' => t('Guatemala'),
    'gu' => t('Guam'),
    'gw' => t('Guinea-Bissau'),
    'gy' => t('Guyana'),
    'hk' => t('Hong Kong S.A.R., China'),
    'hm' => t('Heard Island and McDonald Islands'),
    'hn' => t('Honduras'),
    'hr' => t('Croatia'),
    'ht' => t('Haiti'),
    'hu' => t('Hungary'),
    'id' => t('Indonesia'),
    'ie' => t('Ireland'),
    'il' => t('Israel'),
    'im' => t('Isle of Man'),
    'in' => t('India'),
    'io' => t('British Indian Ocean Territory'),
    'iq' => t('Iraq'),
    'ir' => t('Iran'),
    'is' => t('Iceland'),
    'it' => t('Italy'),
    'je' => t('Jersey'),
    'jm' => t('Jamaica'),
    'jo' => t('Jordan'),
    'jp' => t('Japan'),
    'ke' => t('Kenya'),
    'kg' => t('Kyrgyzstan'),
    'kh' => t('Cambodia'),
    'ki' => t('Kiribati'),
    'km' => t('Comoros'),
    'kn' => t('Saint Kitts and Nevis'),
    'kp' => t('North Korea'),
    'kr' => t('South Korea'),
    'kw' => t('Kuwait'),
    'ky' => t('Cayman Islands'),
    'kz' => t('Kazakhstan'),
    'la' => t('Laos'),
    'lb' => t('Lebanon'),
    'lc' => t('Saint Lucia'),
    'li' => t('Liechtenstein'),
    'lk' => t('Sri Lanka'),
    'lr' => t('Liberia'),
    'ls' => t('Lesotho'),
    'lt' => t('Lithuania'),
    'lu' => t('Luxembourg'),
    'lv' => t('Latvia'),
    'ly' => t('Libya'),
    'ma' => t('Morocco'),
    'mc' => t('Monaco'),
    'md' => t('Moldova'),
    'me' => t('Montenegro'),
    'mg' => t('Madagascar'),
    'mh' => t('Marshall Islands'),
    'mk' => t('Macedonia'),
    'ml' => t('Mali'),
    'mm' => t('Myanmar'),
    'mn' => t('Mongolia'),
    'mo' => t('Macao S.A.R., China'),
    'mp' => t('Northern Mariana Islands'),
    'mq' => t('Martinique'),
    'mr' => t('Mauritania'),
    'ms' => t('Montserrat'),
    'mt' => t('Malta'),
    'mu' => t('Mauritius'),
    'mv' => t('Maldives'),
    'mw' => t('Malawi'),
    'mx' => t('Mexico'),
    'my' => t('Malaysia'),
    'mz' => t('Mozambique'),
    'na' => t('Namibia'),
    'nc' => t('New Caledonia'),
    'ne' => t('Niger'),
    'nf' => t('Norfolk Island'),
    'ng' => t('Nigeria'),
    'ni' => t('Nicaragua'),
    'nl' => t('Netherlands'),
    'no' => t('Norway'),
    'np' => t('Nepal'),
    'nr' => t('Nauru'),
    'nu' => t('Niue'),
    'nz' => t('New Zealand'),
    'om' => t('Oman'),
    'pa' => t('Panama'),
    'pe' => t('Peru'),
    'pf' => t('French Polynesia'),
    'pg' => t('Papua New Guinea'),
    'ph' => t('Philippines'),
    'pk' => t('Pakistan'),
    'pl' => t('Poland'),
    'pm' => t('Saint Pierre and Miquelon'),
    'pn' => t('Pitcairn'),
    'pr' => t('Puerto Rico'),
    'ps' => t('Palestinian Territory'),
    'pt' => t('Portugal'),
    'pw' => t('Palau'),
    'py' => t('Paraguay'),
    'qa' => t('Qatar'),
    're' => t('Reunion'),
    'ro' => t('Romania'),
    'rs' => t('Serbia'),
    'ru' => t('Russia'),
    'rw' => t('Rwanda'),
    'sa' => t('Saudi Arabia'),
    'sb' => t('Solomon Islands'),
    'sc' => t('Seychelles'),
    'sd' => t('Sudan'),
    'se' => t('Sweden'),
    'sg' => t('Singapore'),
    'sh' => t('Saint Helena'),
    'si' => t('Slovenia'),
    'sj' => t('Svalbard and Jan Mayen'),
    'sk' => t('Slovakia'),
    'sl' => t('Sierra Leone'),
    'sm' => t('San Marino'),
    'sn' => t('Senegal'),
    'so' => t('Somalia'),
    'sr' => t('Suriname'),
    'st' => t('Sao Tome and Principe'),
    'sv' => t('El Salvador'),
    'sy' => t('Syria'),
    'sz' => t('Swaziland'),
    'tc' => t('Turks and Caicos Islands'),
    'td' => t('Chad'),
    'tf' => t('French Southern Territories'),
    'tg' => t('Togo'),
    'th' => t('Thailand'),
    'tj' => t('Tajikistan'),
    'tk' => t('Tokelau'),
    'tl' => t('East Timor'),
    'tm' => t('Turkmenistan'),
    'tn' => t('Tunisia'),
    'to' => t('Tonga'),
    'tr' => t('Turkey'),
    'tt' => t('Trinidad and Tobago'),
    'tv' => t('Tuvalu'),
    'tw' => t('Taiwan'),
    'tz' => t('Tanzania'),
    'ua' => t('Ukraine'),
    'ug' => t('Uganda'),
    'uk' => t('United Kingdom'),
    'um' => t('United States Minor Outlying Islands'),
    'us' => t('United States'),
    'uy' => t('Uruguay'),
    'uz' => t('Uzbekistan'),
    'va' => t('Vatican'),
    'vc' => t('Saint Vincent and the Grenadines'),
    've' => t('Venezuela'),
    'vg' => t('British Virgin Islands'),
    'vi' => t('U.S. Virgin Islands'),
    'vn' => t('Vietnam'),
    'vu' => t('Vanuatu'),
    'wf' => t('Wallis and Futuna'),
    'ws' => t('Samoa'),
    'ye' => t('Yemen'),
    'yt' => t('Mayotte'),
    'za' => t('South Africa'),
    'zm' => t('Zambia'),
    'zw' => t('Zimbabwe'),
  );

  if (!empty($available)) {
    foreach ($countries as $ccode => $country) {
      if (empty($available[$ccode])) {
        unset($countries[$ccode]);
      }
    }
  }

  // Sort the list and return
  natcasesort($countries);

  // Move any designated countries to the top of the list
  if (!empty($top_countries) && is_array($top_countries)) {
    $top_list = array();
    foreach ($top_countries as $ccode => $ignore) {
      if (!empty($countries[$ccode])) {
        // only add top countries if defined in the countries array
        $top_list['top_' . $ccode] = $countries[$ccode];
      }
    }
    if (!empty($top_list)) {
      // sort like $countries
      natcasesort($top_list);
      // add a separator
      $top_list['separator'] = '____________________';
      // merge in full countries list
      $countries = array_merge($top_list, $countries);
    }
  }

  // In fact, the ISO codes for countries are all Upper Case.
  // So, if someone needs the list as the official records,
  // it will convert.
  if (!empty($upper)) {
    $countries = array_change_key_case($countries, CASE_UPPER);
  }

  return $countries;
}

/**
 * 3-diget code of all countries on Planet! :)
 *
 * It uses the ISO notation.
 * See http://en.wikipedia.org/wiki/ISO_3166-1_alpha-3
 * for further info.
 *
 * @return
 *   Array. 'COUNTRY 2-DIGIT CODE' => 'COUNTRY 3-DIGIT CODE' pairs
 */
function _addresses_country_get_code3() {
  $countries = array(
    'af' => 'afg',
    'ax' => 'ala',
    'al' => 'alb',
    'dz' => 'dza',
    'as' => 'asm',
    'ad' => 'and',
    'ao' => 'ago',
    'ai' => 'aia',
    'aq' => 'ata',
    'ag' => 'atg',
    'ar' => 'arg',
    'am' => 'arm',
    'aw' => 'abw',
    'au' => 'aus',
    'at' => 'aut',
    'az' => 'aze',
    'bs' => 'bhs',
    'bh' => 'bhr',
    'bd' => 'bgd',
    'bb' => 'brb',
    'by' => 'blr',
    'be' => 'bel',
    'bz' => 'blz',
    'bj' => 'ben',
    'bm' => 'bmu',
    'bt' => 'btn',
    'bo' => 'bol',
    'ba' => 'bih',
    'bw' => 'bwa',
    'bv' => 'bvt',
    'br' => 'bra',
    'io' => 'iot',
    'bn' => 'brn',
    'bg' => 'bgr',
    'bf' => 'bfa',
    'bi' => 'bdi',
    'kh' => 'khm',
    'cm' => 'cmr',
    'ca' => 'can',
    'cv' => 'cpv',
    'ky' => 'cym',
    'cf' => 'caf',
    'td' => 'tcd',
    'cl' => 'chl',
    'cn' => 'chn',
    'cx' => 'cxr',
    'cc' => 'cck',
    'co' => 'col',
    'km' => 'com',
    'cg' => 'cog',
    'cd' => 'zar',
    'ck' => 'cok',
    'cr' => 'cri',
    'ci' => 'civ',
    'hr' => 'hrv',
    'cu' => 'cub',
    'cy' => 'cyp',
    'cz' => 'cze',
    'dk' => 'dnk',
    'dj' => 'dji',
    'dm' => 'dma',
    'do' => 'dom',
    'ec' => 'ecu',
    'eg' => 'egy',
    'sv' => 'slv',
    'gq' => 'gnq',
    'er' => 'eri',
    'ee' => 'est',
    'et' => 'eth',
    'fk' => 'flk',
    'fo' => 'fro',
    'fj' => 'fji',
    'fi' => 'fin',
    'fr' => 'fra',
    'gf' => 'guf',
    'pf' => 'pyf',
    'tf' => 'atf',
    'ga' => 'gab',
    'gm' => 'gmb',
    'ge' => 'geo',
    'de' => 'deu',
    'gh' => 'gha',
    'gi' => 'gib',
    'gr' => 'grc',
    'gl' => 'grl',
    'gd' => 'grd',
    'gp' => 'glp',
    'gu' => 'gum',
    'gt' => 'gtm',
    'gg' => 'ggy',
    'gn' => 'gin',
    'gw' => 'gnb',
    'gy' => 'guy',
    'ht' => 'hti',
    'hm' => 'hmd',
    'va' => 'vat',
    'hn' => 'hnd',
    'hk' => 'hkg',
    'hu' => 'hun',
    'is' => 'isl',
    'in' => 'ind',
    'id' => 'idn',
    'ir' => 'irn',
    'iq' => 'irq',
    'ie' => 'irl',
    'im' => 'imn',
    'il' => 'isr',
    'it' => 'ita',
    'jm' => 'jam',
    'jp' => 'jpn',
    'je' => 'jey',
    'jo' => 'jor',
    'kz' => 'kaz',
    'ke' => 'ken',
    'ki' => 'kir',
    'kp' => 'prk',
    'kr' => 'kor',
    'kw' => 'kwt',
    'kg' => 'kgz',
    'la' => 'lao',
    'lv' => 'lva',
    'lb' => 'lbn',
    'ls' => 'lso',
    'lr' => 'lbr',
    'ly' => 'lby',
    'li' => 'lie',
    'lt' => 'ltu',
    'lu' => 'lux',
    'mo' => 'mac',
    'mk' => 'mkd',
    'mg' => 'mdg',
    'mw' => 'mwi',
    'my' => 'mys',
    'mv' => 'mdv',
    'ml' => 'mli',
    'mt' => 'mlt',
    'mh' => 'mhl',
    'mq' => 'mtq',
    'mr' => 'mrt',
    'mu' => 'mus',
    'yt' => 'myt',
    'mx' => 'mex',
    'fm' => 'fsm',
    'md' => 'mda',
    'mc' => 'mco',
    'mn' => 'mng',
    'me' => 'mne',
    'ms' => 'msr',
    'ma' => 'mar',
    'mz' => 'moz',
    'mm' => 'mmr',
    'na' => 'nam',
    'nr' => 'nru',
    'np' => 'npl',
    'nl' => 'nld',
    'an' => 'ant',
    'nc' => 'ncl',
    'nz' => 'nzl',
    'ni' => 'nic',
    'ne' => 'ner',
    'ng' => 'nga',
    'nu' => 'niu',
    'nf' => 'nfk',
    'mp' => 'mnp',
    'no' => 'nor',
    'om' => 'omn',
    'pk' => 'pak',
    'pw' => 'plw',
    'ps' => 'pse',
    'pa' => 'pan',
    'pg' => 'png',
    'py' => 'pry',
    'pe' => 'per',
    'ph' => 'phl',
    'pn' => 'pcn',
    'pl' => 'pol',
    'pt' => 'prt',
    'pr' => 'pri',
    'qa' => 'qat',
    're' => 'reu',
    'ro' => 'rou',
    'ru' => 'rus',
    'rw' => 'rwa',
    'bl' => 'blm',
    'sh' => 'shn',
    'kn' => 'kna',
    'lc' => 'lca',
    'mf' => 'maf',
    'pm' => 'spm',
    'vc' => 'vct',
    'ws' => 'wsm',
    'sm' => 'smr',
    'st' => 'stp',
    'sa' => 'sau',
    'sn' => 'sen',
    'rs' => 'srb',
    'sc' => 'syc',
    'sl' => 'sle',
    'sg' => 'sgp',
    'sk' => 'svk',
    'si' => 'svn',
    'sb' => 'slb',
    'so' => 'som',
    'za' => 'zaf',
    'gs' => 'sgs',
    'es' => 'esp',
    'lk' => 'lka',
    'sd' => 'sdn',
    'sr' => 'sur',
    'sj' => 'sjm',
    'sz' => 'swz',
    'se' => 'swe',
    'ch' => 'che',
    'sy' => 'syr',
    'tw' => 'twn',
    'tj' => 'tjk',
    'tz' => 'tza',
    'th' => 'tha',
    'tl' => 'tls',
    'tg' => 'tgo',
    'tk' => 'tkl',
    'to' => 'ton',
    'tt' => 'tto',
    'tn' => 'tun',
    'tr' => 'tur',
    'tm' => 'tkm',
    'tc' => 'tca',
    'tv' => 'tuv',
    'ug' => 'uga',
    'ua' => 'ukr',
    'ae' => 'are',
    'gb' => 'gbr',
    'us' => 'usa',
    'um' => 'umi',
    'uy' => 'ury',
    'uz' => 'uzb',
    'vu' => 'vut',
    've' => 'ven',
    'vn' => 'vnm',
    'vg' => 'vgb',
    'vi' => 'vir',
    'wf' => 'wlf',
    'eh' => 'esh',
    'ye' => 'yem',
    'zm' => 'zmb',
    'zw' => 'zwe'
  );

  return $countries;
}

/**
 * Get available states.
 *
 * @param $country
 *   String (optional). The 2-digit country code
 * @return
 *   Array. If $country is passed, then return an array
 *   of states for that country. If nothing is passed then return
 *   an array of countrys who have states, where each country contains
 *   an array of states.
 */
function _addresses_province_get($country = NULL) {
  static $provinces;

  // Get a list of countries
  $countries_all = _addresses_country_get();

  // Test if its needed to update the province list
  if (empty($country) && empty($provinces)) {
    // Get the countries list
    $countries = array_keys($countries_all);
    $update = TRUE;
  }
  elseif (!empty($country) && $countries_all[$country] && empty($provinces[$country])) {
    $countries[] = $country;
    $update = TRUE;
  }

  if (!empty($update)) {
    foreach ($countries as $country_code) {
      // Load country specifice code .inc file if it exists.
      // For example, if country_code for U.S. == 'us', load 'addresses.us.inc'
      include_once drupal_get_path('module', 'addresses') .'/countries/'. $country_code .'.inc';

      // If the country have a province list, load it
      $function = 'addresses_province_list_'. $country_code;
      if (function_exists($function)) {
        $provinces[$country_code] = $function();
      }
    }
  }

  // Return the states of a single country, if any
  if (!empty($country)) {
    if (isset($provinces[$country])) {
      return $provinces[$country];
    }
    else {
      return array();
    }
  }
  else {
    return $provinces;
  }
}

/**
 * Generates HTML for the passed address.
 *
 * @ingroup themeable
 * @param $afields
 *   Array. A single address with the following fields (generally, but it can have more):
 *   - 'street'       => A string representing the street
 *   - 'additional'   => A string for any additional portion of the street
 *   - 'city'         => A string for the city name
 *   - 'province'     => The standard postal abbreviation for the province
 *   - 'country'      => The two-letter ISO code for the country of the address (REQUIRED)
 *   - 'postal_code'  => The international postal code for the address
 */
function theme_addresses($afields) {
  drupal_add_css(drupal_get_path('module', 'addresses') .'/addresses.css');

  // If all fields are hidden, return ''
  if (empty($afields)) {
    return '';
  }

  if (!empty($afields['country'])) {
    // Get the countries address format from a variable
    $address_format = variable_get('addresses_format_'. $afields['country'], '');
    // If there is still no address format
    if (empty($address_format)) {
      // Load the country code specific .inc file if it exists
      module_load_include('inc', 'addresses', '/countries/'. $afields['country']);
      $function = 'addresses_address_format_'. $afields['country'];
      // If the country code specific .inc file provides an address format
      if (function_exists($function)) {
        $address_format = $function();
        variable_set('addresses_format_'. $afields['country'], $address_format);
      }
    }
  }

  // If there is no address format, use the default format
  if (empty($address_format)) {
    $address_format = variable_get('addresses_format_default', FALSE);

    // 'addresses_format_default' is not set, use US's programmed format
    if (!$address_format) {
      module_load_include('inc', 'addresses', '/countries/us');
      $address_format = variable_get('addresses_format_default', addresses_address_format_us());
      // Store as addresses_format_default to prevent fetching from filesystem
      // next time.
      variable_set('addresses_format_default', $address_format);
    }
  }

  // Replace all addresses_adr tokens with their values
  $address_format = token_replace($address_format, 'addresses_adr', $afields);

  // Replace al addresses_general tokens with their values
  $address_format = token_replace($address_format, 'addresses_general', $afields);

  // Replace new lines with the HTML <br /> tag and remove empty lines
  $address_format = explode("\n", $address_format);
  foreach (array_keys($address_format) as $line) {
    $address_format[$line] = trim($address_format[$line]);
    if (empty($address_format[$line])) {
      unset($address_format[$line]);
    }
  }
  $address_format = implode("\n", $address_format);

  // Return the address with adr microformatting and hcard and vcard formatting
  return '<div class="vcard"><dl class="adr">'. $address_format .'</dl></div>';
}

/**
 * Print a formatted is_primary field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted is_primary field.
 */
function theme_addresses_is_primary($afields, $format = 'plain') {
  switch ($format) {
    case 'plain':
      return ($afields == FALSE) ? 'False' : 'True';
    case 'hcard':
      if ($afields['is_primary']) {
        return '<span class="primary">'. theme('placeholder', '('. t('default') .')') .'</span>';
      }
      break;
  }
}

/**
 * Print a formatted aname field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted aname field.
 */
function theme_addresses_aname($afields, $format = 'plain') {
  if (!empty($afields['aname'])) {
    switch ($format) {
    case 'plain':
      return check_plain($afields['aname']);

    case 'hcard':
      return '<span class="fn org">'. theme('placeholder', $afields['aname']) .'</span>';

    }
  }
}

/**
 * Print a formatted country field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted country field.
 */
function theme_addresses_country($afields, $format = 'name') {
  $country = check_plain($afields['country']);
  if (!empty($country)) {
    $countries = _addresses_country_get();
    switch ($format) {
      case 'name':
        return $countries[$country];
      case 'code2':
        return drupal_strtoupper($country);
      case 'code3':
        $countries_code3 = _addresses_country_get_code3();
        return drupal_strtoupper($countries_code3[$country]);
      case 'name_hcard':
        return '<dt>'. t('Country') .': </dt><dd class="country-name">'. $countries[$country] .'</dd>';
      case 'code2_hcard':
        return '<dt>'. t('Country') .': </dt><dd><abbr class="country-name" title="'. $countries[$country] .'">'. drupal_strtoupper($country) .'</abbr></dd>';
      case 'code3_hcard':
        $countries_code3 = _addresses_country_get_code3();
        return '<dt>'. t('Country') .': </dt><dd><abbr class="country-name" title="'. $countries[$country] .'">'. drupal_strtoupper($countries_code3[$country]) .'</abbr></dd>';
    }
  }
}

/**
 * Print a formatted province field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted province field.
 */
function theme_addresses_province($afields, $format = 'name') {
  $province = check_plain($afields['province']);
  if (!empty($province)) {
    $country = check_plain($afields['country']);
    $provinces = _addresses_province_get($country);
    switch ($format) {
      case 'name':
        return $provinces[$province];
      case 'code':
        return drupal_strtoupper($province);
      case 'name_hcard':
        return '<dt>'. t('Province') .': </dt><dd class="region">'. $provinces[$province] .'</dd>';
      case 'code_hcard':
        return '<dt>'. t('Province') .': </dt><dd><abbr class="region" title="'. $provinces[$province] .'">'. drupal_strtoupper($province) .'</abbr></dd>';
    }
  }
}

/**
 * Print a formatted city field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted city field.
 */
function theme_addresses_city($afields, $format = 'plain') {
  $city = check_plain($afields['city']);
  if (!empty($city)) {
    switch ($format) {
      case 'plain':
        return $city;
      case 'hcard':
        return '<dt>'. t('City') .': </dt><dd class="city locality">'. $city .'</dd>';
    }
  }
}

/**
 * Print a formatted street field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted street field.
 */
function theme_addresses_street($afields, $format = 'plain') {
  $street = check_plain($afields['street']);
  if (!empty($street)) {
    switch ($format) {
      case 'plain':
        return $street;
      case 'hcard':
        return '<dt>'. t('Street') .': </dt><dd class="street-address">'. $street .'</dd>';
    }
  }
}

/**
 * Print a formatted additional field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted additional field.
 */
function theme_addresses_additional($afields, $format = 'plain') {
  $additional = check_plain($afields['additional']);
  if (!empty($additional)) {
    switch ($format) {
      case 'plain':
        return $additional;
      case 'hcard':
        return '<dt>'. t('Additional') .': </dt><dd class="extended-address">'. $additional .'</dd>';
    }
  }
}

/**
 * Print a formatted postal_code field.
 *
 * @param $afields
 *   All address fields values.
 * @param $format
 *   The format to return the field in.
 * @return
 *   A formatted postal_code field.
 */
function theme_addresses_postal_code($afields, $format = 'plain') {
  $postal_code = check_plain($afields['postal_code']);
  if (!empty($postal_code)) {
    switch ($format) {
      case 'plain':
        return $postal_code;
      case 'hcard':
        return '<dt>'. t('Postal Code') .': </dt><dd class="postal-code">'. $postal_code .'</dd>';
    }
  }
}

/**
 * Create a single line address. Usefull for some labels.
 *
 * @param $afields
 *   Array. The address parts. see theme_address()
 * @return
 *   String. The single line address
 * @ingroup themeable
 */
function theme_addresses_address_singleline($afields) {
  // Check if its a valid address
  if (empty($afields)) {
    return '';
  }

  $output = '';

  // Add the streets
  if (!empty($afields['street'])) {
    $output .= $afields['street'];
  }

  // Add the city
  if (!empty($afields['city'])) {
    if (!empty($afields['street'])) {
      $output .= ', ';
    }
    $output .= $afields['city'];
  }

  // Add the state / province
  if (!empty($afields['province'])) {
    if (!empty($afields['street']) || !empty($afields['city'])) {
      $output .= ', ';
    }
    $output .= $afields['province'];
  }

  // Add the Postal code
  if (!empty($afields['postal_code'])) {
    if (!empty($afields)) {
      $output .= ' ';
    }
    $output .= $afields['postal_code'];
  }

  // Add the country
  if (!empty($afields['country'])) {
    $output .= ', '. $afields['country'];
  }

  return check_plain($output);
}

// vim: ts=2 sw=2 et syntax=php
