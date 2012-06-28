<?php
/**
 * @file
 * email_flags.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function email_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Email Sent Today".
  $flags['email_sent'] = array(
    'content_type' => 'node',
    'title' => 'Email Sent Today',
    'global' => '0',
    'types' => array(
      0 => 'property',
    ),
    'flag_short' => 'NA',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'NA',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '4',
        2 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '4',
        2 => '3',
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'email_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Updated Today".
  $flags['property_updated_today'] = array(
    'content_type' => 'node',
    'title' => 'Updated Today',
    'global' => '1',
    'types' => array(
      0 => 'property',
    ),
    'flag_short' => 'NA',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'NA',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '4',
        2 => '3',
      ),
      'unflag' => array(
        0 => '2',
        1 => '4',
        2 => '3',
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'email_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;
}
