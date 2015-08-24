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

  foreach ($menus as $key => $value) {
    // dsm($key);
    // dsm(menu_tree_all_data($key, $link = NULL, $max_depth = NULL));
    $form['menus'][$key] = array(
      '#type'=>'checkbox',
      '#title'=>t($value),
      '#default_value'=>0,
      '#access'=>TRUE,
      );
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
