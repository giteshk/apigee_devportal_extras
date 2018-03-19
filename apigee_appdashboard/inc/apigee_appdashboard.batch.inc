<?php

use Apigee\ManagementAPI\Developer;
use Apigee\ManagementAPI\DeveloperApp;
use Apigee\ManagementAPI\CompanyApp;
use Drupal\devconnect_developer_apps\DeveloperAppEntity;


function apigee_appdashboard_admin_form($form, $form_state)
{
    $desc = <<<__STR__
This is a long running process. This will delete all the existing entries and resync from edge.
__STR__;
    $question = <<<_STR__
Do you want to sync the apps from Edge?
_STR__;

    return confirm_form($form, $question, 'admin/apigee_extras/appdashboard', $desc);
}

function apigee_appdashboard_admin_form_submit($form, $form_state)
{
    _apigee_appdashboard_reset_local_cache();
}

/**
 * Reset locally cached application data.
 *
 * @throws \Exception
 */
function _apigee_appdashboard_reset_local_cache()
{
    // Clear table's content.
    db_delete('apigee_appdashboard')->execute();
    db_delete('apigee_appdashboard_app_product_usage')->execute();
    $config = devconnect_default_org_config();
    $developer_obj = new Developer($config);
    $developer_obj->usePaging(); //Since the ORG is cps enabled
    $developers = $developer_obj->listDevelopers();
    foreach ($developers as $developer) {
        $tmp[$developer] = 'Developer';
    }
    $company_obj = new \Apigee\ManagementAPI\Company($config);
    $companies = $company_obj->listCompanies();
    foreach ($companies as $company) {
        $tmp[$company] = 'Company';
    }
    $len = count($tmp);
    $offset = 0;
    $slice_size = 10;
    foreach (array_chunk($tmp, $slice_size, TRUE) as $_developers_or_companies) {
        $operations[] = array(
            '_apigee_appdashboard_sync_developer_apps_from_edge',
            array(
                $_developers_or_companies,
                array('total' => $len, 'offset' => $offset),
            ),
        );
        $offset += $slice_size;
    }
    $batch_info = array(
        'operations' => $operations,
        'finished' => '_apigee_appdashboard_reset_local_cache_finished',
        'title' => t('Synchronizing Apps for Dashboard'),
        'init_message' => t('Initiating Synchronization'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Synchronization of apps for Dashboard failed'),
    );

    batch_set($batch_info);

    // If not run by drush, redirect to People admin page.
    if (!drupal_is_cli()) {
        batch_process(apigee_appdashboard_VIEW_PATH);
    } else {
        $batch =& batch_get();
        $batch['progressive'] = FALSE;
        drush_backend_batch_process();
    }
}

/**
 * Finish batch callback to sync developers.
 *
 * @param bool $success
 *   TRUE if batch was successful.
 * @param array $results
 *   Contains result statistics for batch run.
 * @param array $operations
 *   Contains all operations that were queued.
 */
function _apigee_appdashboard_reset_local_cache_finished($success, $results, $operations)
{
    cache_clear_all();
    variable_set("apigee_appdashboard_needs_rebuild", false);
    drupal_set_message("Dashboard refreshed");
}

/**
 * Batch callback to save apps to Dev Portal from Edge.
 * @param $developers
 * @param $counters
 * @param $context
 */
function _apigee_appdashboard_sync_developer_apps_from_edge($developers_or_companies, $counters, &$context)
{
    $config = devconnect_default_org_config();
    /** @var Developer $developer */
    foreach ($developers_or_companies as $key => $type) {
        try {
            if ($type == 'Developer') {
                $apps = (new DeveloperApp($config, $key))->getListDetail();
                db_delete('apigee_appdashboard')->condition('email', $key)->execute();
            } else {
                $apps = (new CompanyApp($config, $key))->getListDetail();
                db_delete('apigee_appdashboard')->condition('company', $key)->execute();
            }

            /** @var \Apigee\ManagementAPI\DeveloperApp $app */
            foreach ($apps as $app) {
                // Set status to pending if one or more API Products is pending.
                $status = apigee_appdashboard_STATUS_APPROVED;
                foreach ($app->getCredentialApiProducts() as $product) {
                    if ($product['status'] == 'pending') {
                        $status = apigee_appdashboard_STATUS_PENDING;
                        break;
                    }
                    if ($product['status'] == 'revoked') {
                        $status = apigee_appdashboard_STATUS_REVOKED;
                        break;
                    }
                }
                if ($app->getCredentialExpiryDate() == -1) {
                    $credential_expiry = 2144000000;
                } else {
                    $credential_expiry = round($app->getCredentialExpiryDate() / 1000);
                }
                $developer_mail = '';
                $uid = 0;
                if ($app instanceof CompanyApp) {
                    $company = new \Apigee\ManagementAPI\Company($config);
                    $developers = $company->listDevelopers($app->getCompanyName());
                    if (count($developers['Company Administrator']) >= 1) {
                        foreach ($developers['Company Administrator'] as $_tmp_mail) {
                            $developer_mail = $_tmp_mail;
                            if (strpos($_tmp_mail, "@sage.com") == FALSE) {
                                break;
                            }
                        }
                    }
                } elseif ($app instanceof DeveloperApp) {
                    $developer_mail = $app->getDeveloperMail();
                }

                if (!empty($developer_mail)) {
                    $account = user_load_by_mail($developer_mail);
                    if ($account !== FALSE) {
                        $uid = $account->uid;
                    }
                }

                $fields = [
                    'email' => ($app instanceof DeveloperApp) ? $app->getDeveloperMail() : "",
                    'company' => ($app instanceof CompanyApp) ? $app->getCompanyName() : "",
                    'name' => $app->getName(),
                    'display_name' => $app->getAttribute('DisplayName') ?: $app->getName(),
//                    'consumer_key' => $app->getConsumerKey(),
//                    'consumer_secret' => '--', // $app->getConsumerSecret(), Removed consumer secret from portal
                    'overall_status' => $app->getOverallStatus(),
//                    'app_status' => $status,
//                    'credential_status' => $app->getCredentialStatus(),
                    'created_at' => round($app->getCreatedAt() / 1000),
                    'modified_at' => round($app->getModifiedAt() / 1000),
                    'org_name' => $config->orgName,
//                    'api_products' => implode(',', $app->getApiProducts()),
//                    'key_expiry' => $app->getKeyExpiry(),
//                    'credential_expiry' => $credential_expiry,
//                    'certification_status' => $app->getAttribute('certification_status') ?: 'none',
//                    'is_prod_app' => $app->getAttribute('is_prod_app') ?: '0',
//                    'certification_status_changed_by' => $app->getAttribute('certification_status_changed_by') ?: '',
//                    'certification_status_changed_at' => $app->getAttribute('certification_status_changed_at') ?: 0,
                    'uid' => $uid,
                ];
                $keys = [
                    'app_id' => $app->getAppId(),
                ];
                db_merge('apigee_appdashboard')->fields($fields)->key($keys)->execute();
                db_delete('apigee_appdashboard_app_product_usage')->condition('app_id', $app->getAppId())->execute();
                foreach ($app->getCredentials() as $delta => $c) {
                    foreach ($c['apiProducts'] as $_product) {
                        $keys['product_name'] = $_product['apiproduct'];
                        $keys['product_status'] = $_product['status'];
                        $keys['delta'] = $delta;
                        $keys['issued_at'] = round($c['issuedAt'] / 1000);
                        if (isset($c['expiresAt'])) {
                            $keys['expires_at'] = round($c['expiresAt'] / 1000);
                        }
                        db_merge('apigee_appdashboard_app_product_usage')->key($keys)->execute();
                    }
                }
            }
        } catch (Exception $e) {
            watchdog(__FUNCTION__, "Error in Sync " . $e->getMessage(), array(), WATCHDOG_ERROR);

        }
        module_invoke_all("apigee_appdashboard_post_sync");
    }

    $context['message'] = t('%completed developers out of %total synced to Dev Portal', array(
        '%completed' => $counters['offset'],
        '%total' => $counters['total'],
    ));
    $context['finished'] = 1;
}
