<?php
/**
 * @file
 * watcher_flag_and_rule.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function watcher_flag_and_rule_flag_default_flags() {
  $flags = array();
  // Exported flag: "Watch Property".
  $flags['property_watch'] = array(
    'content_type' => 'node',
    'title' => 'Watch Property',
    'global' => '0',
    'types' => array(
      0 => 'property',
    ),
    'flag_short' => 'Watch this property.',
    'flag_long' => 'Click here to be emailed about changes to this property.',
    'flag_message' => 'You are now watching this property.',
    'unflag_short' => 'Stop watching this property.',
    'unflag_long' => 'Click here to stop recieving alerts about this property.',
    'unflag_message' => 'You will no longer recieve alerts.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'watcher_flag_and_rule',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;
}
