<?php

namespace APIProduct_Catalog\Apigee\ManagementAPI;

use Apigee\ManagementAPI\Base;
use Apigee\Util\OrgConfig;

class User extends Base
{

    /**
     * Initializes default values of all member variables.
     *
     * @param OrgConfig $config
     */
    public function __construct(OrgConfig $config, $mail)
    {
        $this->init($config, '/users/' . $mail);
    }

    public function getRoles()
    {
        try {
            $this->get('userroles');
            $response = $this->responseObj;
            $org_name = $this->getConfig()->orgName;
            $user_role = array();
            foreach ($response['role'] as $value) {
                if ($value['organization'] == $org_name) {
                    $user_role[] = $value['name'];
                }
            }
        } catch (\Exception $e) {
            //Forbidden or all exceptions we return false;
            $user_role = false;
        }
        return $user_role;
    }
}
