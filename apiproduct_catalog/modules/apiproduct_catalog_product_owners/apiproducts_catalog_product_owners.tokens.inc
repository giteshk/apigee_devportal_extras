<?php

/**
 * Implements hook_token_info_alter().
 */
function apiproduct_catalog_product_owners_token_info_alter(&$data)
{
  if(isset($data['tokens']['developer_app'])) {
    $data['tokens']['developer_app']['pending-approver-emails'] = [
      'name' => t('List of pending Approver emails'),
      'description' => t('Email address of all approvers for products that are still pending approval comma seperated'),
    ];
    $data['tokens']['developer_app']['all-approver-emails'] = [
      'name' => t('List of all Approver emails'),
      'description' => t('Email address of all approvers for all products on this app'),
    ];
    $data['tokens']['developer_app']['pending-approver-roles'] = [
      'name' => t('List of pending Approver roles'),
      'description' => t('Roles mentioned on the API Product as approver roles for Products with pending status'),
    ];
    $data['tokens']['developer_app']['all-approver-roles'] = [
      'name' => t('List of all Approver roles'),
      'description' => t('Roles mentioned on the API Product as approver for all products'),
    ];
  }
}


/**
 * Implements hook_tokens().
 */
function apiproduct_catalog_product_owners_tokens($type, $tokens, array $data = array(), array $options = array())
{
  if ($type != 'developer_app' || empty($data['developer_app'])) {
    return array();
  }
  $app = $data['developer_app'];
  $replacements = [];
  $pending_apiproducts = [];
  $all_products = [];
  foreach($app->credentials as $c){
    foreach($c['apiProducts'] as $p) {
      $all_products[$p['apiproduct']] = $p['apiproduct'];
      if($p['status'] == 'pending') {
        $pending_apiproducts[$p['apiproduct']] = $p['apiproduct'];
      }
    }
  }
  $pending_approver_emails = [];
  $all_approver_emails = [];
  $all_approver_roles = [];
  $pending_approver_roles = [];
  $apiproducts = entity_load('api_product', $all_products, ['show_private' => true]);
  $all_roles = array_flip(user_roles());

  foreach($apiproducts as $product_name => $product) {
    if(isset($product->attributes['product_owner'])) {
      foreach(explode(",", $product->attributes['product_owner']) as $email) {
        $all_approver_emails[$email] = $email;
        if(in_array($product_name, $pending_apiproducts)) {
          $pending_approver_emails[$email] = $email;
        }
      }
    }
    if(isset($product->attributes['product_owner_role'])) {
      foreach(explode(",", $product->attributes['product_owner_role']) as $role) {
        if(!isset($all_roles[$role])) {
          continue;
        }
        $all_approver_roles[$role] = $all_roles[$role];
        if(in_array($product_name, $pending_apiproducts)) {
          $pending_approver_roles[$role] = $all_roles[$role];
        }
      }
    }
  }

  $replacements['[app:pending-approver-emails]'] = implode(",", $pending_approver_emails);
  $replacements['[app:all-approver-emails]'] = implode(",", $all_approver_emails);
  $replacements['[app:pending-approver-roles]'] = implode(",", $pending_approver_roles);
  $replacements['[app:all-approver-roles]'] = implode(",", $all_approver_roles);
  return $replacements;
}
