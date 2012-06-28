<?php
/**
 * @file
 * advertisement_entity.features.inc
 */

/**
 * Implements hook_node_info().
 */
function advertisement_entity_node_info() {
  $items = array(
    'advertisement' => array(
      'name' => t('Advertisement'),
      'base' => 'node_content',
      'description' => t('An advertisement for any basic product.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
