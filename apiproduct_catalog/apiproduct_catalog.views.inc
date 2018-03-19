<?php

/**
 * @file
 * Views integration for apigee_appdashboard table.
 */

/**
 * Implements hook_views_data().
 */
function apiproduct_catalog_views_data_alter(&$data)
{
    $data['node_access']['nid']['filter']['handler'] = 'apiproduct_catalog_handler_filter_node_edit_access';
    if(module_exists("apigee_appdashboard")){
        $data['apigee_appdashboard_app_product_usage']['nid'] = array(
            'title' => t('API Product Nid'),
            // The help that appears on the UI.
            'help' => t('The NID of the API Product Node'),
            // Information for displaying the nid.
            'field' => array(
                'click sortable' => TRUE,
            ),
            // Information for accepting a nid as an argument.
            'argument' => array(
                'handler' => 'views_handler_argument_node_nid',
                'click sortable' => TRUE,
                'numeric' => TRUE,
            ),
            // Information for accepting a nid as a filter.
            'filter' => array(
                'handler' => 'views_handler_filter_numeric',
            ),
            // Information for sorting on a nid.
            'sort' => array(
                'handler' => 'views_handler_sort',
            ),
            'relationship' => array(
                'handler' => 'views_handler_relationship',
                'base' => 'node',
                'base field' => 'nid',
                'title' => t('Content'),
                'label' => t('Product Node'),
            ),
        );
    }
}
