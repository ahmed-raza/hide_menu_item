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
  //print_r($menus);
  $indexCompleted = array_search('Development', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Features', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Management', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Navigation', $menus);
  unset($menus[$indexCompleted]);
  $indexCompleted = array_search('Site Menu', $menus);
  unset($menus[$indexCompleted]);
  // $indexCompleted = array_search('User menu', $menus);
  // unset($menus[$indexCompleted]);
  foreach ($menus as $key => $value) {
     $form['menus'][$value] = array(
    '#type'=>'fieldset',
    '#title'=>t($value),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    );


    $menu_items = menu_load_links($key);
    // dsm($menu_items);
    foreach ($menu_items as $key => $values) {
      // dsm($values);
      $form['menus'][$value]['items'][$key] = array(
        // '#type' => 'checkboxes',
        // '#options' => drupal_map_assoc(array($values['link_title'])),
        '#type'=>'checkbox',
        '#title'=>t($values['link_title']),
        '#default_value'=>0,
        '#value'=>$values['link_title'],
        '#access'=>TRUE,
        '#prefix'=>'<div class="'.$value.' '.$values['link_title'].' hide">',
        '#suffix'=>'</div>',
        );
      $form['menus'][$value]['urls'] = array(
        '#type'=>'textarea',
        '#title'=>t('Enter URLs'),
        '#access'=>TRUE,
        '#weight'=>1,
        '#description'=>t('Enter the urls where you want to hide these menus sparated by commas.')
        );
    }
  }
  $form['config_submit'] = array(
    '#type'=>'submit',
    '#value'=>'Save configuration',
    );

  return $form;
}

 // function hide_menu_item_configuration_form_submit(&$form, &$form_state){
 //  // dsm($form_state);
 //  $allinputs = $form_state['input'];
 //  foreach ($allinputs as $key => $value) {
 //    if (is_numeric($key)) {
 //      // dsm($key);
 //    }
 //  }
 //  dsm($form_state);
 // }
