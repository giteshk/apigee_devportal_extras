<?php
/**
 * @file
 * Admin function to fetch the list of readonly administrator
 */


function apigee_devconnect_readonly_sysadmin_admin_form($form, $form_state)
{
    drupal_set_message("This module works only with Edge Private cloud.", "warning");
    $config = _apigee_devconnect_readonly_sysadmin_credentials();
    $form['apigee_devconnect_readonly_sysadmin'] = array(
        '#type' => 'fieldset',
        '#title' => t("Credentials for Readonly admin"),
        '#description' => t("Please create a readonly system administrator user on edge. We don't want to provide credentials which can write to edge here"),
        '#collapsed' => false,
        '#tree' => true,
    );

    $form['apigee_devconnect_readonly_sysadmin']['username'] = array(
        '#title' => "Readonly admin username",
        '#type' => 'textfield',
        '#required' => TRUE,
        '#default_value' => $config['user'],
    );
    $form['apigee_devconnect_readonly_sysadmin']['password'] = array(
        '#title' => "Readonly admin password",
        '#type' => 'password',
        '#required' => false,
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => "Save Configuration",
    );
    return $form;
}

function apigee_devconnect_readonly_sysadmin_admin_form_validate($form, &$form_state)
{
    $readonly_user = $form_state['values']['apigee_devconnect_readonly_sysadmin']['username'];
    $readonly_pass = $form_state['values']['apigee_devconnect_readonly_sysadmin']['password'];

    $config = devconnect_default_org_config();

    if (!empty($readonly_user)) {
        if (!empty($readonly_pass)) {
            require_once "User.php";
            $new_config = new \Apigee\Util\OrgConfig($config->orgName, $config->endpoint, $readonly_user, $readonly_pass);
            $user = new \APIProduct_Catalog\Apigee\ManagementAPI\User($new_config, $config->user_mail);
            if ($user->getRoles() === false) {
                form_set_error('readonly_admin', "Credentials are not valid");
            } else {
                drupal_set_message("Credentials valid");
            }
        } else {
            $config = _apigee_devconnect_readonly_sysadmin_credentials();
            if ($readonly_user !== $config['user']) {
                form_set_error('apigee_devconnect_readonly_sysadmin][password', "Password field is required if you are entering new username");
            }
        }
    }

}

function apigee_devconnect_readonly_sysadmin_admin_form_submit($form, &$form_state)
{
    $readonly_pass = $form_state['values']['apigee_devconnect_readonly_sysadmin']['password'];
    if (!empty($readonly_pass)) {
        $config_file = _apigee_devconnect_readonly_sysadmin_config_file();
        $org_config_new = $form_state['values']['apigee_devconnect_readonly_sysadmin'];
        file_put_contents($config_file, Drupal\devconnect\Crypto::encrypt(serialize($org_config_new)));
        @chmod($config_file, 0666);
        drupal_set_message("Credentials updated");
    } else {
        drupal_set_message("Password not changed");
    }
}
