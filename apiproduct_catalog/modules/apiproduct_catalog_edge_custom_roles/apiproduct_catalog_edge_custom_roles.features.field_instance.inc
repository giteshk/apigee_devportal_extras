<?php
/**
 * @file
 * apiproduct_catalog_edge_custom_roles.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function apiproduct_catalog_edge_custom_roles_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-edge_api_product-field_api_team_name'.
  $field_instances['node-edge_api_product-field_api_team_name'] = array(
    'bundle' => 'edge_api_product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This could be some Team Identifier.
This controls the visibility of API Product and API Docs content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_api_team_name',
    'label' => 'Team Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Team Name');
  t('This could be some Team Identifier.
This controls the visibility of API Product and API Docs content.');

  return $field_instances;
}
