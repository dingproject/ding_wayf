<?php

/**
 * Provides the ding! WAYF administraion settings form.
 */
function ding_wayf_admin_settings_form() {
  $form = array(
    '#tree' => TRUE,
  );

  // Load default values
  $default = variable_get('ding_wayf', array());

  $form['ding_wayf']['installdir'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple SAML php instalation directory'),
    '#default_value' => isset($default['installdir']) ? $default['installdir'] : '/var/simplesamlphp',
    '#description' => t('Absolute path with no trailing slash to simple SAML installation.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['sp'] = array(
    '#type' => 'textfield',
    '#title' => t('Autenticaton source for this SP'),
    '#default_value' => isset($default['sp']) ? $default['sp'] : 'default-sp',
    '#description' => t('The name of the service provider (SP) to use from /var/simplesamlphp/config/authsources.php.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['attribute'] = array(
    '#type' => 'textfield',
    '#title' => t('Which attribute from simpleSAMLphp should be used as to extract credentials'),
    '#default_value' => isset($default['attribute']) ? $default['attribute'] : 'schacPersonalUniqueID',
    '#description' => t('The attribute that contains the credentials.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['attribute_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Which field should be extracted'),
    '#default_value' => isset($default['attribute_field']) ? $default['attribute_field'] : 'CPR',
    '#description' => t('Default the CPR number will be extracted (urn:mace:terena.org:schac:uniqueID:dk:CPR:0708741234).'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Login link text'),
    '#default_value' => isset($default['link_text']) ? $default['link_text'] : 'WAYF login',
    '#description' => t('The text string that will be used to generate WAYF login link.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect fallback URL'),
    '#default_value' => isset($default['redirect']) ? $default['redirect'] : 'user/%uid/status',
    '#description' => t('Redirect to this URL after login. The token %uid is avaliable'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['default'] = array(
    '#type' => 'password',
    '#title' => t('Default password'),
    '#description' => t('Default password is used together with e.i. the extracted CPR number to log into the library system.'),
  );

  return system_settings_form($form);
}

/**
 * Validation function for the administration settings form above.
 */
function ding_wayf_admin_settings_form_validate($form, $form_state) {
  // Check that simple saml php is found at the location given.
  $path = $form_state['values']['ding_wayf']['installdir'];
  if (!file_exists($path . '/lib/_autoload.php')) {
    form_set_error('installdir', t('Simple SAML php was not found at the location given.'));
  }
}
