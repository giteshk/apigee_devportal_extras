<?php
/**
 * @file
 * apiproduct_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apiproduct_catalog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function apiproduct_catalog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function apiproduct_catalog_node_info() {
  $items = array(
    'edge_api_product' => array(
      'name' => t('API Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
