<?php
/**
 * @file
 * apiproduct_catalog.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function apiproduct_catalog_user_default_roles() {
  $roles = array();

  // Exported role: product owner.
  $roles['product owner'] = array(
    'name' => 'product owner',
    'weight' => 12,
  );

  return $roles;
}
