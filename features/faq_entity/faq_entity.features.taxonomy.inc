<?php
/**
 * @file
 * faq_entity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function faq_entity_taxonomy_default_vocabularies() {
  return array(
    'faq_tags' => array(
      'name' => 'FAQ Tags',
      'machine_name' => 'faq_tags',
      'description' => 'Tags for the FAQ\'s',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
