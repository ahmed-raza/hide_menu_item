<?php

function hide_menu_item_config(){
  return drupal_get_form('hide_menu_item_configuration_form');
}

function hide_menu_item_configuration_form($node, &$form_state){

  $form = array();

  $form['markup'] = array(
    '#type'=>'markup',
    '#markup'=>t('<p>Select a menu.</p>'),
    );

  $menus = menu_get_menus($all = TRUE);
  $indexCompleted = array_search('Development', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Management', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Navigation', $menus);
  unset($menus[$indexCompleted]);
  foreach ($menus as $key => $value) {
    $form['menus'][$value] = array(
      '#type'=>'fieldset',
      '#title'=>t($value),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $menu_items = menu_load_links($key);
    foreach ($menu_items as $key => $values) {
      $form['menus'][$value][$values['link_title']] = array(
        '#type'  => 'checkbox',
        '#title' => t($values['link_title']),
        '#default_value' => 1
        );
    }
  }
  $form['config_submit'] = array(
    '#type'=>'submit',
    '#value'=>'Save configuration',
    );
  return $form;
}

function hide_menu_item_configuration_form_submit(&$form, &$form_state){
  dsm($form_state);
 }
