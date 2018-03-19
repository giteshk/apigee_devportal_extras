<?php
/**
 * @file
 * apiproduct_catalog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function apiproduct_catalog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'api-resources-listing-page';
  $context->description = 'API Resources Listing';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*' => 'taxonomy/term/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-products_from_proxies-block' => array(
          'module' => 'views',
          'delta' => 'products_from_proxies-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('API Resources Listing');
  $export['api-resources-listing-page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'apiproduct-catalog';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'api_products' => 'api_products',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-api_products-page' => array(
          'module' => 'views',
          'delta' => '-exp-api_products-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => array(
      0 => 'main-menu:product-catalog',
    ),
  );
  $context->condition_mode = 0;
  $export['apiproduct-catalog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'categorized_api_docs';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'categorized_api_docs:page' => 'categorized_api_docs:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-categorized_api_docs-page' => array(
          'module' => 'views',
          'delta' => '-exp-categorized_api_docs-page',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['categorized_api_docs'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'edge-api-product-details';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'edge_api_product' => 'edge_api_product',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-db8c6ca6844e0071f75a221fb747a9ab' => array(
          'module' => 'views',
          'delta' => 'db8c6ca6844e0071f75a221fb747a9ab',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['edge-api-product-details'] = $context;

  return $export;
}
