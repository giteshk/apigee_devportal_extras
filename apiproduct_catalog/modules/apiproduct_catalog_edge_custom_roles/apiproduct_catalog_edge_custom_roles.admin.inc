<?php


function apiproduct_catalog_edge_custom_roles_settings_form($form, $form_state)
{
    $desc = <<<__DESC__
    This would be the suffixes for the custom roles in Edge.
<br/>We treat whatever string appears before the suffix as team name from the custom role name.
<br/>You can enter multiple values by seperating each of them by a comma(,)
<br/> This will be a case insensitive match.
<br/> e.g 12344_developer would result in the team name "12344" or GTI_Developer would result in a team name "GTI"
__DESC__;

    $form['apigee_devconnect_readonly_sysadmin_team_name_suffixes'] = [
        '#type' => 'textfield',
        '#title' => 'Team name suffixes in Edge',
        '#description' => $desc,
        '#default_value' => variable_get('apiproduct_catalog_edge_custom_roles_team_name_suffixes', '_developer'),
    ];
    return system_settings_form($form);
}