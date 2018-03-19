<?php
/**
 * @file
 * apiproduct_catalog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function apiproduct_catalog_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer api products in catalog'.
  $permissions['administer api products in catalog'] = array(
    'name' => 'administer api products in catalog',
    'roles' => array(
      'administrator' => 'administrator',
      'product owner' => 'product owner',
    ),
    'module' => 'apiproduct_catalog',
  );

  return $permissions;
}
