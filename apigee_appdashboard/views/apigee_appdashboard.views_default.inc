<?php
/**
 * @file
 * apigee_appdashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function apigee_appdashboard_views_default_views()
{
    $view = new view();
    $view->name = 'apigee_extras_app_dashboard';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'apigee_appdashboard';
    $view->human_name = 'Apigee Extras App dashboard';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'API Key Approval Dashboard';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'administer apigee-extras appdashboard';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['distinct'] = TRUE;
    $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
    $handler->display->display_options['query']['options']['query_tags'] = array(
      0 => 'check_edge_apiproduct_access',
    );
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '30';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'display_name' => 'display_name',
      'name' => 'display_name',
      'email' => 'email',
      'company' => 'company',
      'status' => 'status',
      'created_at' => 'created_at',
      'modified_at' => 'modified_at',
      'app_id' => 'app_id',
      'product_name' => 'product_name',
      'product_status' => 'product_status',
      'expires_at' => 'expires_at',
      'edit' => 'edit',
      'delta' => 'delta',
    );
    $handler->display->display_options['style_options']['default'] = 'modified_at';
    $handler->display->display_options['style_options']['info'] = array(
      'display_name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => ' ',
        'empty_column' => 0,
      ),
      'name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'email' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'company' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'status' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'created_at' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'modified_at' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'app_id' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'product_name' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'product_status' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'expires_at' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'edit' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'delta' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    /* Relationship: App Dashboard: App Owner */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Relationship: App to product mapping: App */
    $handler->display->display_options['relationships']['app_id']['id'] = 'app_id';
    $handler->display->display_options['relationships']['app_id']['table'] = 'apigee_appdashboard_app_product_usage';
    $handler->display->display_options['relationships']['app_id']['field'] = 'app_id';
    $handler->display->display_options['relationships']['app_id']['required'] = TRUE;
    /* Field: App Dashboard: App Display Name */
    $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
    $handler->display->display_options['fields']['display_name']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
    /* Field: App Dashboard: App Name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['name']['alter']['text'] = '(Internal name : [name])';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    /* Field: App Dashboard: Developer Email */
    $handler->display->display_options['fields']['email']['id'] = 'email';
    $handler->display->display_options['fields']['email']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['email']['field'] = 'email';
    /* Field: App Dashboard: Company */
    $handler->display->display_options['fields']['company']['id'] = 'company';
    $handler->display->display_options['fields']['company']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['company']['field'] = 'company';
    /* Field: App Dashboard: OverAll App Status */
    $handler->display->display_options['fields']['overall_status']['id'] = 'overall_status';
    $handler->display->display_options['fields']['overall_status']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['overall_status']['field'] = 'overall_status';
    /* Field: User: Active */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'users';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    $handler->display->display_options['fields']['status']['relationship'] = 'uid';
    $handler->display->display_options['fields']['status']['label'] = 'Owner Active';
    $handler->display->display_options['fields']['status']['not'] = 0;
    /* Field: App Dashboard: Date/Time Created */
    $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
    $handler->display->display_options['fields']['created_at']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
    $handler->display->display_options['fields']['created_at']['label'] = 'App Date/Time Created';
    $handler->display->display_options['fields']['created_at']['date_format'] = 'today time ago';
    $handler->display->display_options['fields']['created_at']['second_date_format'] = 'long';
    /* Field: App Dashboard: Date/Time Modified */
    $handler->display->display_options['fields']['modified_at']['id'] = 'modified_at';
    $handler->display->display_options['fields']['modified_at']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['modified_at']['field'] = 'modified_at';
    $handler->display->display_options['fields']['modified_at']['date_format'] = 'long';
    $handler->display->display_options['fields']['modified_at']['second_date_format'] = 'long';
    /* Field: App Dashboard: App UUID */
    $handler->display->display_options['fields']['app_id']['id'] = 'app_id';
    $handler->display->display_options['fields']['app_id']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['fields']['app_id']['field'] = 'app_id';
    $handler->display->display_options['fields']['app_id']['label'] = '';
    $handler->display->display_options['fields']['app_id']['exclude'] = TRUE;
    $handler->display->display_options['fields']['app_id']['element_label_colon'] = FALSE;
    /* Field: Global: Custom text */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['label'] = 'Review';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Details';
    $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing']['alter']['path'] = apigee_appdashboard_VIEW_PATH . '/app-details/[app_id]/view';
    $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Sort criterion: App Dashboard: Date/Time Modified */
    $handler->display->display_options['sorts']['modified_at']['id'] = 'modified_at';
    $handler->display->display_options['sorts']['modified_at']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['sorts']['modified_at']['field'] = 'modified_at';
    $handler->display->display_options['sorts']['modified_at']['order'] = 'DESC';
    /* Sort criterion: App Dashboard: App Display Name */
    $handler->display->display_options['sorts']['display_name']['id'] = 'display_name';
    $handler->display->display_options['sorts']['display_name']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['sorts']['display_name']['field'] = 'display_name';
    /* Sort criterion: App to product mapping: Date/Time Credential Issued */
    $handler->display->display_options['sorts']['issued_at']['id'] = 'issued_at';
    $handler->display->display_options['sorts']['issued_at']['table'] = 'apigee_appdashboard_app_product_usage';
    $handler->display->display_options['sorts']['issued_at']['field'] = 'issued_at';
    $handler->display->display_options['sorts']['issued_at']['order'] = 'DESC';
    /* Filter criterion: Global: Combine fields filter */
    $handler->display->display_options['filters']['combine']['id'] = 'combine';
    $handler->display->display_options['filters']['combine']['table'] = 'views';
    $handler->display->display_options['filters']['combine']['field'] = 'combine';
    $handler->display->display_options['filters']['combine']['operator'] = 'contains';
    $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
    $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
    $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
    $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by email, company or any string';
    $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
    $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
    $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    $handler->display->display_options['filters']['combine']['fields'] = array(
      'display_name' => 'display_name',
      'name' => 'name',
      'email' => 'email',
      'company' => 'company',
      'status' => 'status',
      'created_at' => 'created_at',
      'modified_at' => 'modified_at',
      'app_id' => 'app_id',
    );
    /* Filter criterion: User: Active */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'users';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['relationship'] = 'uid';
    $handler->display->display_options['filters']['status']['value'] = 'All';
    $handler->display->display_options['filters']['status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'User Active';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    /* Filter criterion: App to product mapping: Product Name */
    $handler->display->display_options['filters']['product_name']['id'] = 'product_name';
    $handler->display->display_options['filters']['product_name']['table'] = 'apigee_appdashboard_app_product_usage';
    $handler->display->display_options['filters']['product_name']['field'] = 'product_name';
    $handler->display->display_options['filters']['product_name']['relationship'] = 'app_id';
    $handler->display->display_options['filters']['product_name']['operator'] = 'word';
    $handler->display->display_options['filters']['product_name']['exposed'] = TRUE;
    $handler->display->display_options['filters']['product_name']['expose']['operator_id'] = 'product_name_op';
    $handler->display->display_options['filters']['product_name']['expose']['label'] = 'Product Name';
    $handler->display->display_options['filters']['product_name']['expose']['operator'] = 'product_name_op';
    $handler->display->display_options['filters']['product_name']['expose']['identifier'] = 'product_name';
    $handler->display->display_options['filters']['product_name']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    /* Filter criterion: App Dashboard: OverAll App Status */
    $handler->display->display_options['filters']['overall_status']['id'] = 'overall_status';
    $handler->display->display_options['filters']['overall_status']['table'] = 'apigee_appdashboard';
    $handler->display->display_options['filters']['overall_status']['field'] = 'overall_status';
    $handler->display->display_options['filters']['overall_status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['overall_status']['expose']['operator_id'] = 'overall_status_op';
    $handler->display->display_options['filters']['overall_status']['expose']['label'] = 'OverAll App Status';
    $handler->display->display_options['filters']['overall_status']['expose']['operator'] = 'overall_status_op';
    $handler->display->display_options['filters']['overall_status']['expose']['identifier'] = 'overall_status';
    $handler->display->display_options['filters']['overall_status']['is_grouped'] = TRUE;
    $handler->display->display_options['filters']['overall_status']['group_info']['label'] = 'OverAll App Status';
    $handler->display->display_options['filters']['overall_status']['group_info']['identifier'] = 'overall_status';
    $handler->display->display_options['filters']['overall_status']['group_info']['group_items'] = array(
      1 => array(
        'title' => 'pending',
        'operator' => '=',
        'value' => 'Pending',
      ),
      2 => array(
        'title' => 'approved',
        'operator' => '=',
        'value' => 'Approved',
      ),
      3 => array(
        'title' => 'revoked',
        'operator' => '=',
        'value' => 'Revoked',
      ),
    );

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page_1');
    $handler->display->display_options['path'] = apigee_appdashboard_VIEW_PATH;
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'App Dashboard';
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'main-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;

    $export[$view->name] = $view;

    return $export;
}
