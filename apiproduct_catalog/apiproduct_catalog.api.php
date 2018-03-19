<?php

/**
 * Implement this hook to sync additional data from edge.
 *
 * @param $node
 * @param $edge_api_product
 */
function hook_apiproduct_catalog_node_presave_alter(&$node, $edge_api_product)
{

}

/**
 * Implement this hook to fire additional logic after the node is saved from the sync job
 *
 * @param $node
 * @param $edge_api_product
 */
function hook_apiproduct_catalog_node_postsave($node, $edge_api_product)
{

}


/**
 * Implement this hook if you want to delete any data that you may have generated during API Sync
 *
 */
function hook_apiproduct_catalog_reset()
{

}