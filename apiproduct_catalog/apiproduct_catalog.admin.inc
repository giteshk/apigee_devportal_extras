<?php
/**
 * @file
 * Admin function to fetch the list of readonly administrator
 */


function apiproduct_catalog_admin_form(array $form, array &$form_state)
{


    $form['apiproduct_catalog_product_access_mapping'] = array(
        '#title' => 'Settings for mapping Product access level to Drupal Roles',
        '#type' => 'fieldset',
        '#tree' => TRUE
    );

    $var = _apiproduct_catalog_product_access_mapping();
    $roles = user_roles();

    $form['apiproduct_catalog_product_access_mapping']['public'] = array(
        '#type' => 'checkboxes',
        '#title' => 'Select a product to map to Public products',
        '#required' => TRUE,
        '#default_value' => $var['public'],
        '#options' => $roles,
    );
    $form['apiproduct_catalog_product_access_mapping']['private'] = array(
        '#type' => 'checkboxes',
        '#title' => 'Select a product to map to Private products',
        '#required' => TRUE,
        '#default_value' => $var['private'],
        '#options' => $roles,
    );
    $form['apiproduct_catalog_product_access_mapping']['internal'] = array(
        '#type' => 'checkboxes',
        '#title' => 'Select a product to map to Internal products',
        '#required' => TRUE,
        '#default_value' => $var['internal'],
        '#options' => $roles,
    );
    $form['advanced'] = array(
        '#type' => 'fieldset',
        '#title' => 'Advanced Setting',
    );
    $form['advanced']['apiproduct_catalog_force_sync'] = array(
        '#type' => 'checkbox',
        '#title' => "Sync all products on next cron run",
        '#description' => "
        This will slow down the sync job which by default compares the modified dates.
        This flag will be automatically reset after the sync.     
        ",
        '#default_value' => variable_get('apiproduct_catalog_force_sync', 0),
    );

    $form = system_settings_form($form);
    $form['#submit'][] = 'apiproduct_catalog_admin_form_submit';
    return $form;
}


function apiproduct_catalog_admin_form_submit($form, $form_state)
{
    node_access_needs_rebuild(TRUE);
    cache_clear_all();
}

function apiproduct_catalog_admin_reset_form($form, $form_state)
{
    $desc = "This will remove API Products nodes / SmartDocs nodes / SmartDocs terms / Categories? This will not delete anything from Edge";
    return confirm_form($form, "Are you sure you want to remove all sync nodes ?", 'admin/config/apigee_extras/apiproduct_catalog', $desc);
}

function apiproduct_catalog_admin_reset_form_submit($form, &$form_state)
{
    $artifacts_to_delete = [
        'node' => ['edge_api_product', 'smart_method'],
        'taxonomy_term' => ['api_product_categories', 'smartdocs_models', 'smartdocs_tags', 'smartdocs_model_categories'],
    ];
    foreach ($artifacts_to_delete as $entity_type => $bundles) {
        foreach ($bundles as $bundle) {
            $conditions = [];
            if ($entity_type == 'taxonomy_term') {
                $vocab = taxonomy_vocabulary_machine_name_load($bundle);
                $conditions['vid'] = $vocab->vid;
            } else if ($entity_type == 'node') {
                $conditions['type'] = $bundle;
            }
            $entities = entity_load($entity_type, [], $conditions);
            foreach ($entities as $entity) {
                $view = views_get_view($entity->name . "_methods");
                if ($view) {
                    views_delete_view($view);
                }
            }
            if (!empty($entities)) {
                entity_delete_multiple($entity_type, array_keys($entities));
            }
        }
    }
    module_invoke_all("apiproduct_catalog_reset");
    drupal_set_message("Finished API Product Catalog reset. Please run the cron job now to recreate all content");
    $form_state['redirect'] = 'admin/config';
}
