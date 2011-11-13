<?php

/**
 * @file
 * Addresses user views declarations.
 */


/**
 * Implementation of hook_views_data().
 */
function addresses_user_views_views_data() {
  $data = array();

  // Views: Addresses User
  $data['addresses_user']['table']['group'] = t('Addresses user list');

  $data['addresses_user']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'eid', // not too sure why it's called 'e'-id... but that's the uid
    ),
  );

  $data['addresses_user']['is_primary'] = array(
    'title' => t('Is primary'),
    'help' => t('Whether this is the primary address. WARNING: non-primary addresses may be private!'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is primary'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    //'argument' => array( -- not available yet
    //  'handler' => 'views_handler_argument_boolean',
    //),
  );

  $data['addresses_user']['aname'] = array(
    'title' => t('Address name'),
    'help' => t('The name of the business or person at that address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['country'] = array(
    'title' => t('Country'),
    'help' => t('The country in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['province'] = array(
    'title' => t('Province'),
    'help' => t('The province in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['province'] = array(
    'title' => t('Province'),
    'help' => t('The province in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['city'] = array(
    'title' => t('City'),
    'help' => t('The city in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['street'] = array(
    'title' => t('Street'),
    'help' => t('The street in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['additional'] = array(
    'title' => t('Additional'),
    'help' => t('The additional field in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['addresses_user']['postal_code'] = array(
    'title' => t('Postal code'),
    'help' => t('The postal code field in the address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // calls hook_addresses_user_views(&$data) functions.
  // Give a change for sub-modules to add their own data handlers.
  // (WARNING: specialized handlers will require a 'path' entry)
  module_invoke_all('addresses_user_views', $data);

  return $data;
}

// vim: ts=2 sw=2 et syntax=php
