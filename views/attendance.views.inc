<?php

/**
 * hook_views_data()
 */
function attendance_views_data() {

  $tables['attendance_node_users'] = array (
    'table' => array(
	  'group' => t('Attendance'),
	  'join' => array (
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid'
         ),
         'node' => array(
           'left_field' => 'nid',
           'field' => 'nid'
         )
	  ),
      'base' => array(
        'field' => 'attendance_id',
        'title' => t('Attendance'),
        'help' => t('Attendance notes whether a user will be coming ro a particular event.'),
        'weight' => 0,
      ),
	),
    'status' => array (
	  'title' => t('Status'),
	  'help' => t('The status of the user'),
      'argument' => array(
        'handler' => 'views_handler_argument_string'
      ),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_attendance_status'
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
	  ),
    ),
    'uid' => array(
      'title' => t('User'),
      'help' => t('User who responded their attendance'),
      'field' => array(
        'handler' => 'views_handler_field_user_link',
        'click sortable' => TRUE
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_user_uid',
        'name field' => 'name', 
        'numeric' => TRUE,
        'validate type' => 'uid',
      ),
      'relationship' => array( 
        'base' => 'users',
        'field' => 'uid',
        'label' => 'User',
        'help' => t('Brind in data about the user who responded to this attendance'),
      ),
    ),	 
    'nid' => array(
      'title' => t('Node'),
      'help' => t('Event node'),
      'field' => array(
        'handler' => 'views_handler_field_node_link',
        'click sortable' => TRUE
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_node_nid',
        'name field' => 'name', 
        'numeric' => TRUE,
        'validate type' => 'uid',
      ),
      'relationship' => array( 
        'base' => 'node',
        'field' => 'nid',
        'label' => 'Node',
        'help' => t('Brind in data about the event being attended'),
      ),
    ), 
  );
	
  return $tables;
}

/**
 *  Implementation of hook_views_handlers().
 */
function attendance_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'attendance') . '/views',
    ),
    'handlers' => array(
      'views_handler_filter_attendance_status' => array('parent' => 'views_handler_filter_in_operator'),
	)
  );
}