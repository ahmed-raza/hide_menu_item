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
  $indexCompleted = array_search('User menu', $menus);
  unset($menus[$indexCompleted]);
  //print_r($menus);
  foreach ($menus as $key => $value) {
    // print $key;
    //  if ($key == 'management' || $key == 'devel' || $key == 'features' || $key == 'navigation' || $key == 'menu-site-menu' || $key == 'user-menu') {
    //   unset($menus[$key]);
    // }
     $form['menus'][$value] = array(
    '#type'=>'fieldset',
    '#title'=>t($value),
    );


    $menu_items = menu_load_links($key);
    //dsm($menu_items);
    foreach ($menu_items as $key => $values) {
      //dsm($value);
      $form['menus'][$key] = array(
        '#type'=>'checkbox',
        '#title'=>t($values['link_title']),
        '#default_value'=>0,
        '#access'=>TRUE,
        '#prefix'=>'<div class="'.$value.' '.$values['link_title'].' hide">',
        '#suffix'=>'</div>',
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
//   $types = node_type_get_types();
//   $total_types = count($types);
//   $sliced_array = array_slice($form_state['values'], 0, $total_types);
//   foreach ($sliced_array as $key => $value) {
//     if ($value == 1) {
//       $save = array('type'=>$key);
//       dsm($save);
//     }
//   }
// }
