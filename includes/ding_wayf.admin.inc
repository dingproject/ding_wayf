<?php

function ding_wayf_admin_settings_form() {
  $form = array(
    '#tree' => TRUE,
  );

  

  return system_settings_form($form);
}