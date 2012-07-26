<?php
/**
 * @file
 * faq_entity.features.inc
 */

/**
 * Implements hook_node_info().
 */
function faq_entity_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('An FAQ entry for Trey Keller.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
