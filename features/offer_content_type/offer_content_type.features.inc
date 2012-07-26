<?php
/**
 * @file
 * offer_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function offer_content_type_node_info() {
  $items = array(
    'offer' => array(
      'name' => t('Offer'),
      'base' => 'node_content',
      'description' => t('Temporary Offer Content Type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
