<?php
// $Id: views_plugin_row_mediarss.inc,v 1.4.2.3 2009/05/14 09:26:44 microbe Exp $
/**
 * @file
 * Contains the Meida RSS row plugin.
 */

/**
 * Media RSS row plugin to render an RSS feed.
 *
 */

class views_plugin_row_mediarss extends views_plugin_row {
function option_definition() {
    $options = parent::option_definition();
    $options['teaser']['item_length'] = array('default' => 'default');
    $options['mediarss_typename'] = array('default' => array());
    $options['mediarss_imgfield'] = array('default' => array());
    $options['teaser']['mediarss_cachepreset'] = array('default' => array());
	$options['teaser']['item_picture_size'] = array('default' => 'preview');
	$options['content']['mediarss_cachepreset'] = array('default' => array());
	$options['content']['item_picture_size'] = array('default' => '_original');
	$options['thumbnail']['mediarss_cachepreset'] = array('default' => array());
	$options['thumbnail']['item_picture_size'] = array('default' => 'thumbnail');
	$options['content']['mediarss_displaytitle']=true;
	$options['teaser']['mediarss_allowcck']=false;
    return $options;
  }

  function options_form(&$form, &$form_state) {

  $nodetypes = node_get_types();
  foreach ($nodetypes as $nodetype) {
$nodetypes2[$nodetype->type]=$nodetype->name;
}
$form['mediarss_typename'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node types to convert'),
    '#options' => $nodetypes2,
    '#default_value' => $this->options['mediarss_typename'],
    '#description' => t("The content types you want images to be displayed for."),
    '#weight' => -3,
  );
  $form['teaser'] = array(
    '#type' => 'fieldset',
    '#title' => t('Teaser/Body'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
      $form['teaser']['item_length'] = array(
      '#type' => 'select',
      '#title' => t('Display type'),
      '#options' => array(
        'fulltext' => t('Full text'),
        'teaser' => t('Title plus teaser'),
        'title' => t('Title only'),
        'fulltextpic2' => t('Full text plus pics'),
	  'teaserpic2' => t('Title plus pictures plus teaser'),
	  'titlepic2' => t('Title plus pictures'),
	  'fulltextpic' => t('Full text plus single pic'),
	  'teaserpic' => t('Title plus single picture plus teaser'),
	  'titlepic' => t('Title plus single picture'),
        'default' => t('Use default RSS settings'),
      ),
      '#default_value' => $this->options['teaser']['item_length'],
    );

  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Media:Content'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['thumbnail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Media:Thumbnail'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
if(module_exists('imagefield') && module_exists('imagecache')){
$cckimagefields =db_query("SELECT * FROM {content_node_field}");
$cckimagefieldsarray=array();
while ($cckimagefield = db_fetch_array($cckimagefields)){
$cckimagefieldsarray[$cckimagefield['field_name']]=$cckimagefield['field_name'];
}
  $form['mediarss_imgfield'] = array(
    '#type' => 'checkboxes',
    '#title' => t('CCK ImageFields'),
    '#options' => $cckimagefieldsarray,
    '#default_value' => $this->options['mediarss_imgfield'],
    '#description' => t("The field name you assigned to the CCK ImageField you wish to display."),
    '#weight' => -2,
  );
  $form['teaser']['mediarss_allowcck'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow CCK and other modules to change node content'),
    '#default_value' => $this->options['teaser']['mediarss_allowcck'],
    '#description' => t("If checked it will allow CCK and other modules to change node content before it is displayed"),
  );
$form['content']['mediarss_displaytitle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Image Title'),
    '#default_value' => $this->options['content']['mediarss_displaytitle'],
    '#description' => t("If checked it will replace node title for image title (if it has one) in the <media:title> tag"),
  );
$imagecachepresets= array();
  foreach (imagecache_presets() as $preset) {
    $imagecachepresets[$preset['presetname']] =$preset['presetname'];
  }
  $imagecachepresets['MediaRSSOriginal'] = 'Original Image';
  $form['teaser']['mediarss_cachepreset'] = array(
    '#type' => 'select',
    '#title' => t('ImageCache Preset'),
    '#options' => $imagecachepresets,
    '#default_value' => $this->options['teaser']['mediarss_cachepreset'],
    '#description' => t("The name of the ImageCache preset you want to use to display the images."),
  );
  $form['content']['mediarss_cachepreset'] = array(
    '#type' => 'select',
    '#title' => t('ImageCache Preset'),
    '#options' => $imagecachepresets,
    '#default_value' => $this->options['content']['mediarss_cachepreset'],
    '#description' => t("The name of the ImageCache preset you want to use to display the images."),
  );
  $form['thumbnail']['mediarss_cachepreset'] = array(
    '#type' => 'select',
    '#title' => t('ImageCache Preset'),
    '#options' => $imagecachepresets,
    '#default_value' => $this->options['thumbnail']['mediarss_cachepreset'],
    '#description' => t("The name of the ImageCache preset you want to use to display the images."),
  );
}
if(module_exists('image')){
foreach(image_get_sizes() as $key => $size){
$imagesizes[$key]=$size['label'];
}
    $form['teaser']['item_picture_size'] = array(
      '#type' => 'select',
      '#title' => t('Image Module Picture Size'),
      '#options' => $imagesizes,
      '#default_value' => $this->options['teaser']['item_picture_size'],
    );
    $form['content']['item_picture_size'] = array(
      '#type' => 'select',
      '#title' => t('Image Module Picture Size'),
      '#options' => $imagesizes,
      '#default_value' => $this->options['content']['item_picture_size'],
    );
    $form['thumbnail']['item_picture_size'] = array(
      '#type' => 'select',
      '#title' => t('Image Module Picture Size'),
      '#options' => $imagesizes,
      '#default_value' => $this->options['thumbnail']['item_picture_size'],
    );
}
  }

  function render($row) {
    // For the most part, this code is taken from node_feed() in node.module
    global $base_url;

    $item_length = $this->options['teaser']['item_length'];
    
    if ($item_length == 'default') {
      $item_length = variable_get('feed_item_length', 'teaser');
    }

    if (empty($this->view->style_plugin->namespaces)) {
      $this->view->style_plugin->namespaces['xmlns:dc'] = 'http://purl.org/dc/elements/1.1/';
    }
    $this->view->style_plugin->namespaces['xmlns:media'] = 'http://search.yahoo.com/mrss/';
    // Load the specified node:
    $item = node_load($row->nid);
    $item->build_mode = NODE_BUILD_RSS;
    $item->link = url("node/$row->nid", array('absolute' => TRUE));

    $teaser = ($item_length == 'teaser'|| $item_length == 'teaserpic' || $item_length == 'teaserpic2') ? TRUE : FALSE;
      // Filter and prepare node teaser
    if (node_hook($item, 'view')) {
      $item = node_invoke($item, 'view', $teaser, FALSE);
    }else {
      $item = node_prepare($item, $teaser);
    }
    // Allow modules to change $node->teaser before viewing.
    if($this->options['teaser']['mediarss_allowcck']==True){
		node_invoke_nodeapi($item, 'view', $teaser, FALSE);
		$item_content = drupal_render($item->content);
	}else{
		if($teaser){
			$item_content = ($item->teaser);
		}else{
			$item_content = ($item->body);
		}
	}
	
    // Allow modules to add additional item fields and/or modify $item
    $extra = node_invoke_nodeapi($item, 'rss item');
    $extra = array_merge($extra,
      array(
        array('key' => 'pubDate', 'value' => gmdate('r', $item->created)),
        array('key' => 'dc:creator', 'value' => $item->name),
        array(
          'key' => 'guid',
          'value' => $item->nid . ' at ' . $base_url,
          'attributes' => array('isPermaLink' => 'false')
        ),
	  )
    );
	$titlekey = array('key' => 'media:title', 'attributes' => array('type' => 'plain',), 'value' => $item->title);
	$creditrolePhotographer = array('key' => 'media:credit', 'attributes' => array('role' => 'photographer',), 'value' => $item->name);
	$imagefields = $this->options['mediarss_imgfield'];
	foreach($this->options['mediarss_typename'] as $mediarsstype){
	//$item->teaser.=$mediarsstype.' ';
	if($item->type==$mediarsstype && $mediarsstype!='0' && $mediarsstype=='image' && module_exists('image')){
	   if($item->images){
	   //$item->teaser.="image-loop ";
	   $attributes['url'] =  file_create_url($item->images[$this->options['thumbnail']['item_picture_size']]);
         $media['url'] =  file_create_url($item->images[$this->options['content']['item_picture_size']]);
         $media['type'] = file_get_mimetype($item->images[$this->options['content']['item_picture_size']]);
 $extra = array_merge($extra,
array(
        array('key' => 'media:content', 'attributes' => $media, 'value'=>array(
		$titlekey,
        $creditrolePhotographer,
		),
		array('key' => 'media:thumbnail', 'attributes' => $attributes),
		)
      )
    );
$picture_text2 = l(image_display($item, $this->options['teaser']['item_picture_size']), url('node/'.$item->nid, array('absolute' => TRUE)), array('html' => TRUE));
$picture_text = $picture_text2;
 $media=array();
$attributes=array();
}
}
if(module_exists('imagefield') && $item->type==$mediarsstype && $mediarsstype!='0'){
	//$item->teaser.="imagefield-type ";
		$picture_text3="";
		foreach($imagefields as $imagefield){
			if($item->{$imagefield}){
			foreach($item->{$imagefield} as $itemImagefield){
			if($itemImagefield['filepath']){
	                  //$item->teaser.="imagefield-loop ";
				$imagecache = $this->options['mediarss_cachepreset'];
				$picture_text = l(theme('imagecache', $this->options['teaser']['mediarss_cachepreset'], $itemImagefield['filepath']), url("node/".$item->nid, array('absolute' => TRUE)), array('html'=> TRUE));
				if ($this->options['content']['mediarss_cachepreset']=='MediaRSSOriginal'){
					$contentfilepath=$base_url."/".$itemImagefield['filepath'];
				}else{
					$contentfilepath = imagecache_create_url($this->options['content']['mediarss_cachepreset'], $itemImagefield['filepath']);
				}
				if ($this->options['thumbnail']['mediarss_cachepreset']=='MediaRSSOriginal'){
					$thumbnailfilepath=$base_url.$itemImagefield['filepath'];;
				}else{
					$thumbnailfilepath=imagecache_create_url($this->options['thumbnail']['mediarss_cachepreset'], $itemImagefield['filepath']);
				}
				$attributes['url'] =  $thumbnailfilepath;
				$media['url'] = $contentfilepath;
				$media['type'] = file_get_mimetype($media['url']);
				if($this->options['content']['mediarss_displaytitle']){
					$image_title = isset($itemImagefield['data']['title']) ? $itemImagefield['data']['title'] : $item->title;
					$titlekey = array('key' => 'media:title', 'attributes' => array('type' => 'plain',), 'value' => $image_title);
				}
				$extra = array_merge($extra,
					array(
						array('key' => 'media:content', 'attributes' => $media, 'value'=>array(
							$titlekey,
							$creditrolePhotographer,
							array('key' => 'media:thumbnail', 'attributes' => $attributes),
							)
						),
					)
				);
				$picture_text3.=$picture_text;
				}
				}
			}
		}
	}
}
    foreach ($extra as $element) {
      if (isset($element['namespace'])) {
        $this->view->style_plugin->namespaces = array_merge($this->view->style_plugin->namespaces, $element['namespace']);
      }
    }

    // Prepare the item description
    switch ($item_length) {
      case 'fulltext':
        $item_text = $item_content;
        break;
      case 'teaser':
        $item_text = $item_content;
        if (!empty($item->readmore)) {
          $item_text .= '<p>' . l(t('read more'), 'node/' . $item->nid, array('absolute' => TRUE, 'attributes' => array('target' => '_blank'))) . '</p>';
        }
        break;
      case 'title':
        $item_text = '';
        break;
      case 'fulltextpic2':
        $item_text = $picture_text2.$picture_text3.$item_content;
        break;
      case 'teaserpic2':
        $item_text = $picture_text2.$picture_text3.$item_content;
        if (!empty($item->readmore)) {
          $item_text .= '<p>' . l(t('read more'), 'node/' . $item->nid, array('absolute' => TRUE, 'attributes' => array('target' => '_blank'))) . '</p>';
        }
        break;
      case 'titlepic2':
        $item_text = $picture_text2.$picture_text3;
        break;
      case 'fulltextpic':
        $item_text = $picture_text.$item_content;
        break;
      case 'teaserpic':
        $item_text = $picture_text.$item_content;
        if (!empty($item->readmore)) {
          $item_text .= '<p>' . l(t('read more'), 'node/' . $item->nid, array('absolute' => TRUE, 'attributes' => array('target' => '_blank'))) . '</p>';
        }
        break;
      case 'titlepic':
        $item_text = $picture_text;
        break;
	default:
		$item_text = $item_content;
		break;
    }

    return format_rss_item($item->title, $item->link, $item_text, $extra);
  }

}