<?php

class ApigeeAPIProductKeyApprover extends \Apigee\Util\APIObject
{
    /**
     * Initializes this object
     *
     * @param \Apigee\Util\OrgConfig $config
     * @param mixed $developer
     */
    public function __construct(\Apigee\Util\OrgConfig $config, $app_id)
    {
        $app = new \Apigee\ManagementAPI\DeveloperApp($config, '');
        $app = $app->loadByAppId($app_id, TRUE);
        $baseurl = str_replace($config->endpoint, '', $app->client->getBaseUrl());
        $this->init($config, $baseurl . '/' . rawurlencode($app->getName()));
    }

    public function setKeyStatusforAPIProduct($key, $api_product, $key_status)
    {
        $this->post('keys/' . $key . '/apiproducts/' .
            rawurlencode($api_product) . '?action=' . $key_status);
    }
}