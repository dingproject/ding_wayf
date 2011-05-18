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
  );

  $form['ding_wayf']['sp'] = array(
    '#type' => 'textfield',
    '#title' => t('Autenticaton source for this SP'),
    '#default_value' => isset($default['sp']) ? $default['sp'] : 'default-sp',
    '#description' => t('The name of the SP to use from /var/simplesamlphp/config/authsources.php.'),
  );

  $form['ding_wayf']['data'] = array(
    '#type' => 'textfield',
    '#title' => t('Which attribute from simpleSAMLphp should be used as to extract CPR number'),
    '#default_value' => isset($default['data']) ? $default['data'] : 'eduPersonPrincipalName',
    '#description' => t('The name of the information string that contains the CPR number.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}