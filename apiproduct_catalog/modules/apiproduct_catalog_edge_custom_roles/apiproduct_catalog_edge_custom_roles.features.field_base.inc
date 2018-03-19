<?php
/**
 * @file
 * apiproduct_catalog_edge_custom_roles.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function apiproduct_catalog_edge_custom_roles_field_default_field_bases()
{
    $field_bases = array();

    // Exported field_base: 'field_api_team_name'.
    $field_bases['field_api_team_name'] = array(
        'active' => 1,
        'cardinality' => -1,
        'deleted' => 0,
        'entity_types' => array(),
        'field_name' => 'field_api_team_name',
        'indexes' => array(
            'format' => array(
                0 => 'format',
            ),
        ),
        'locked' => 0,
        'module' => 'text',
        'settings' => array(
            'max_length' => 255,
        ),
        'translatable' => 0,
        'type' => 'text',
    );

    return $field_bases;
}
