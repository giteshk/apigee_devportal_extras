<?php


/**
 * Add the custom attributes as properties to the developer_app entity.
 * @param $info
 */
function apigee_appdashboard_rules_data_info_alter(&$info)
{
    $data = &$info['developer_app'];
    foreach (variable_get('app_attributes', array()) as $k => $v) {
        $data['property info']['attribute_' . $k] = [
            'type' => in_array($v['widget'], ['select', 'checkboxes', 'radios']) ? 'token' : 'text',
            'label' => $v['title'],
            'getter callback' => 'apigee_appdashboard_attribute_get',
            'setter callback' => 'apigee_appdashboard_attribute_set',
            'setter permissions' => 'administer developer apps',
        ];
        if ($data['property info']['attribute_' . $k]['type'] == 'token') {
            $data['property info']['attribute_' . $k]['options list'] = 'apigee_appdashboard_attribute_option_list_callback';
        }
    }
    $data['property info']['partner_contact_email'] = [
        'type' => 'text',
        'label' => 'Partner Contact for email',
        'getter callback' => 'apigee_appdashboard_app_contact_get',
    ];
}

/**
 * Find out who should you contact regarding an app.
 * It could be the company admin for a Company app or the developer for developer apps.
 * @param $entity
 * @param array $options
 * @param $name
 * @param $type
 * @param $context
 * @return mixed
 */
function apigee_appdashboard_app_contact_get($entity, array $options, $name, $type, $context)
{
    if ($entity instanceOf ApigeeCompanyAppEntity) {
        $company = new \Apigee\ManagementAPI\Company(devconnect_default_org_config());
        $company = $company->load($entity->companyName);
        return $company->getAttribute('ADMIN_EMAIL');
    } else {
        return $entity->developer;
    }
}

/**
 * Getter for the Custom App Attributes
 * @param $entity
 * @param array $options
 * @param $name
 * @param $type
 * @param $context
 * @return array
 */
function apigee_appdashboard_attribute_get($entity, array $options, $name, $type, $context)
{
    $name = str_replace("attribute_", '', $name);
    $attributes = variable_get('app_attributes', array());
    $value = "";
    if (isset($entity->attributes[$name])) {
        $value = $entity->attributes[$name];
    }
    return $attributes[$name]['widget'] === 'checkboxes' ? explode(',', $value) : $value;
}

/**
 * Setter for the custom app attributes
 *
 * @param $entity
 * @param $name
 * @param $value
 * @param $langcode
 * @param $type
 * @param $info
 */
function apigee_appdashboard_attribute_set($entity, $name, $value, $langcode, $type, $info)
{
    $name = str_replace("attribute_", '', $name);
    $entity->attributes[$name] = $value;
}

/**
 * List for the app attributes to which they apply.
 * @param $name
 * @param $info
 * @param $op
 * @return array
 */
function apigee_appdashboard_attribute_option_list_callback($name, $info, $op)
{
    $name = str_replace("attribute_", '', $name);
    $attributes = variable_get('app_attributes', array());
    return $attributes[$name]['type'] == 'checkbox' ? ['' => 'Not Checked', $attributes[$name]['default'] => 'Checked'] : $attributes[$name]['options'];

}