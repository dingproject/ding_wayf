<?php

function ding_wayf_admin_settings_form() {
  $form = array(
    '#tree' => TRUE,
  );

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
    '#description' => t('The name of the SP to use from /var/simplesamlphp/config/authsources.php.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['data_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Which attribute from simpleSAMLphp should be used as to extract credentials'),
    '#default_value' => isset($default['data_field']) ? $default['data_field'] : 'schacPersonalUniqueID',
    '#description' => t('The name of the information string that contains the credentials.'),
    '#required' => TRUE,
  );

  $form['ding_wayf']['data_field_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Which string should be extracted'),
    '#default_value' => isset($default['data_field_id']) ? $default['data_field_id'] : 'CPR',
    '#description' => t('Default the CPR number will be extracted (urn:mace:terena.org:schac:uniqueID:dk:CPR:0708741234).'),
    '#required' => TRUE,
  );
  $form['ding_wayf']['https'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force https'),
    '#default_value' => isset($default['https']) ? $default['https'] : TRUE,
    '#description' => t('Should be enabled on production sites.'),
  );

  return system_settings_form($form);
}

function ding_wayf_admin_settings_form_validate($form, $form_state) {
  // TODO: Check that simple saml php is found
}
