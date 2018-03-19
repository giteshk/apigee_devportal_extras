<?php

/**
 * @file
 * Views integration for apigee_appdashboard table.
 */

/**
 * Implements hook_views_data().
 */
function apigee_appdashboard_views_data()
{
    return [
        'apigee_appdashboard' => [
            'table' => [
                'group' => t('App Dashboard'),
                'base' => [
                    'field' => 'app_id',
                    'title' => t('Cached Developer App'),
                    'help' => t('Cached Developer Apps table'),
                ],
            ],
            'name' => [
                'title' => t('App Name'),
                'help' => t('Internal or machine-referenceable name for the app'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'app_id' => [
                'title' => t('App UUID'),
                'help' => t('Universally unique identifier for an app'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'email' => [
                'title' => t('Developer Email'),
                'help' => t('Email of developer who created this app.'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'company' => [
                'title' => t('Company'),
                'help' => t('Company the app belongs to.'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'display_name' => [
                'title' => t('App Display Name'),
                'help' => t('Human-readable name for the app'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'created_at' => [
                'title' => t('Date/Time Created'),
                'help' => t('Indicates when the app was first created'),
                'field' => [
                    'handler' => 'views_handler_field_date',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort_date'],
                'filter' => ['handler' => 'views_handler_filter_date'],
                'argument' => ['handler' => 'views_handler_argument_date'],
            ],
            'modified_at' => [
                'title' => t('Date/Time Modified'),
                'help' => t('Indicates when the app was last modified'),
                'field' => [
                    'handler' => 'views_handler_field_date',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort_date'],
                'filter' => ['handler' => 'views_handler_filter_date'],
                'argument' => ['handler' => 'views_handler_argument_date'],
            ],
            'overall_status' => [
                'title' => t('OverAll App Status'),
                'help' => t('OverAll Status of the App'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'uid' => [
                'title' => t('App Developer uid'),
                'help' => t('The user who owns the App/Company'),
                'relationship' => array(
                    'title' => t('App Owner'),
                    'help' => t('Relate App to the user who created it.'),
                    'handler' => 'views_handler_relationship',
                    'base' => 'users',
                    'field' => 'uid',
                    'label' => t('app_owner'),
                ),
                'filter' => array(
                    'handler' => 'views_handler_filter_user_name',
                ),
                'argument' => array(
                    'handler' => 'views_handler_argument_numeric',
                ),
                'field' => array(
                    'handler' => 'views_handler_field_user',
                ),
            ],
        ],
        'apigee_appdashboard_app_product_usage' => [
            'table' => [
                'base' => [
                    'title' => 'App to product mapping',
                    'help' => 'App to product mapping.',
                ],
                'group' => 'App to product mapping',
                'join' => [
                    'apigee_appdashboard' => [
                        'left_field' => 'app_id',
                        'field' => 'app_id',
                    ],
                ],
            ],
            'product_name' => [
                'title' => 'Product Name',
                'help' => 'API product name',
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
            'delta' => [
                'title' => 'delta',
                'help' => 'Credentials Delta',
                'field' => [
                    'handler' => 'views_handler_field_numeric',
                    'click sortable' => FALSE,
                ],
            ],
            'modified_at' => [
                'title' => t('Date/Time Modified'),
                'help' => t('Indicates when the app was last modified'),
                'field' => [
                    'handler' => 'views_handler_field_date',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort_date'],
                'filter' => ['handler' => 'views_handler_filter_date'],
                'argument' => ['handler' => 'views_handler_argument_date'],
            ],
            'issued_at' => [
                'title' => t('Date/Time Credential Issued'),
                'help' => t('Indicates when the credential was issued'),
                'field' => [
                    'handler' => 'views_handler_field_date',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort_date'],
                'filter' => ['handler' => 'views_handler_filter_date'],
                'argument' => ['handler' => 'views_handler_argument_date'],
            ],
            'expires_at' => [
                'title' => t('Date/Time Credential Expires'),
                'help' => t('Indicates when the credential will expire'),
                'field' => [
                    'handler' => 'views_handler_field_date',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort_date'],
                'filter' => ['handler' => 'views_handler_filter_date'],
                'argument' => ['handler' => 'views_handler_argument_date'],
            ],
            'app_id' => [
                'title' => 'App Id',
                'help' => 'Primary key: unique App ID.',
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => FALSE,
                ],
                'relationship' => array(
                    'title' => t('App'),
                    'help' => t('App from the app_dashboard table'),
                    'handler' => 'views_handler_relationship',
                    'base' => 'apigee_appdashboard',
                    'field' => 'app_id',
                    'label' => t('apigee_appdashboard_app_product_usage APP ID'),
                ),
            ],
            'product_status' => [
                'title' => t('APP - API Product status'),
                'help' => t('Status of the API Product on the APP'),
                'field' => [
                    'handler' => 'views_handler_field',
                    'click sortable' => TRUE,
                ],
                'sort' => ['handler' => 'views_handler_sort'],
                'filter' => ['handler' => 'views_handler_filter_string'],
                'argument' => ['handler' => 'views_handler_argument_string'],
            ],
        ]
    ];
}
