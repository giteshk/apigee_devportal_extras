Steps :

1. Enable the apiproduct_catalog module
2. Upload the default image on the Product Image field of the API Product Content Type
3. Upload the default image on the Model Image field of the SmartDocs Model Taxonomy
4. Navigate to admin/config/apigee_extras/apiproduct_catalog and set the correct visibility for API Products based on access level in Edge (public, private, internal)
5. If you need Private products to be visible to a specific role please go ahead and create a role and update this entry.
6. Run Cron to sync the API Products from Edge
7. Make sure to Rebuild the permissions the first time (admin/reports/status/rebuild)
8. When you import Swagger files make sure to import them using the correct proxy name.


On Edge :
For API Products you can define the following attributes
- categories  (Can be multiple seperated by ,)

Requires apiproduct_catalog_product_owners module
- product_owner (Email addresses can be multiple seperated by ,) - will give them view & edit access to the node + ability to add other consumers
- product_owner_role (Roles can be multiple seperated by ,) - will give that role view & edit access to the node + ability to add other consumers
- team_name  (Can be multiple seperated by ,)
- audience_role (To control which user can see what products)
Make sure to set the "Access level" on the API Product or it will be defaulted to "public"
