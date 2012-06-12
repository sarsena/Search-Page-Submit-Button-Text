<?php

function search_page_submit_button_text_admin_form($form_state) {

	$form['submit_button'] = array(
		'#type' => 'fieldset',
		'#title' => t('Submit Button'),
		'#collapsible' => FALSE,
	);
	
	$form['submit_button']['row'] = array(
		'#type' => 'textfield',
		'#title' => t('Change Submit Button Text'),
		'#default_value' => variable_get('SEARCH_PAGE_SUBMIT_BUTTON', 'SEARCH'),
		'#size' => 30,
		'#maxlength' => 30,
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);
	
	$form['#validate'][] = 'search_page_submit_button_text_admin_validate';
	
  return $form;
}

function search_page_submit_button_text_admin_form_submit($form, &$form_state) {
	//print_r($form_state['values']);
	variable_set('SEARCH_PAGE_SUBMIT_BUTTON', $form_state['values']['row']);
		
	$form_state['redirect'] = 'admin/build';
}