<?php

/**
 * implementation of hook_theme()
 */
function vsc_fusion_theme() {
  return array(
    'candidate_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_candidate_node_form',
       ),

    'visual_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_visual_node_form',
       ),

    'video_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_video_node_form',
       ),

    'vsc_profile_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_vsc_profile_node_form',
       ),

    'profile_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_profile_node_form',
       ),

    'statement_node_form' => array(
       'arguments' => array('form' => NULL),
       'function' => 'vsc_fusion_statement_node_form',
       ),
   );
}

/**
 * Prepreprocess function for page.tpl.php.
 */
function vsc_fusion_preprocess_page(&$vars) {
  global $user;

  $vars['path'] = base_path() . path_to_theme() .'/';

  // An anonymous user has a user id of zero.
  if ($user->uid > 0) {
    // The user is logged in.
    $vars['logged_in'] = TRUE;
  }
  else {
    // The user has logged out.
    $vars['logged_in'] = FALSE;
  }

  $body_classes = array();
  // classes for body element
  // allows advanced theming based on context (home page, node of certain type, etc.)
  // sniffing for the arg(0) of home and if so setting the $vars['is_front'] = TRUE and removing the override for the
  // css class so that it adds the class front only if $vars['is_front'] is true
  if (arg(0) == 'home') {
    $vars['is_front'] = TRUE;
  }
  $body_classes[] = ($vars['is_front']) ? 'front' : 'not-front';
  $body_classes[] = ($vars['logged_in']) ? 'logged-in' : 'not-logged-in';
  if ($vars['node']->type) {
    $body_classes[] = 'node-page'; // we're on a single node view page
    $body_classes[] = 'ntype-'. vsc_fusion_id_safe($vars['node']->type);
  }
  if ($vars['right']) {
    $body_classes[] = 'sidebar-right';
  }
  // we want country codes
  global $language;
  $body_classes[] = 'lang-' . strtolower(substr($language->language, 0, 2));
  $body_classes[] = 'locale-' . strtolower($language->language);

  if (!$vars['is_front']) {
    // Add unique classes for each page and website section
    $path = drupal_get_path_alias($_GET['q']);
    list($section,) = explode('/', $path, 2);
    $body_classes[] = vsc_fusion_id_safe('page-'. $path);
    $body_classes[] = vsc_fusion_id_safe('section-'. $section);
    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-add'; // Add 'section-node-add'
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-'. arg(2); // Add 'section-node-edit' or 'section-node-delete'
      }
    }
  }

  $vars['body_classes'] = 'color-scheme-'. theme_get_setting('vsc_fusion_color_scheme');
  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
  // Implode with spaces.
  $vars['body_classes'] = implode(' ', $body_classes);

  // Users Online
  $vars['registered_users'] = module_invoke('sonybmg_fans', 'total');
  $vars['online_users'] = module_invoke('sonybmg_fans', 'online');

  // Switch primary_links based on country_code and language.  Looks for the most
  // appropriate menu based on a list of suggestions.
  // menu-primary-links-en-us
  // menu-primary-links-en
  // <default primary links>
  // Note: the menu- part of the name is added automatically when creating new menus
  if(module_exists('country_code')) {
    $suggestions = array(
      strtolower('menu-primary-'. $GLOBALS['language']->language .'-'. country_code()),
      strtolower('menu-primary-'. $GLOBALS['language']->language),
    );
    foreach($suggestions as $menu_name) {
      if($country_links = menu_navigation_links($menu_name)) {
        $vars['primary_links'] = $country_links;
        break;
      }
    }
  }

  // landing page support
  if ($vars['node']->type =='landingpage'){
    if ((arg(2) != 'edit') && (arg(2) != 'delete')){
      $vars['template_files'] = array('page-landingpage');
    }
  }

  // hiding page titles for a certain node type
   if (isset($vars['node'])) {
    if($vars['node']->type == 'visual' || $vars['node']->type == 'video') {
      unset($vars['title']);

    }
  }
}

function vsc_fusion_preprocess_node(&$vars) {
  switch ($vars['node']->type) {
    case 'statement':
     $vars['node']->submitted = theme_node_submitted($vars['node']);
     $vars['artistpagelink'] = vsc_fusion_return_artist_page ($vars['node']->name);
     break;
    case 'blog':
    case 'article':
  if ($vars['teaser'] && $vars['node']->teaser) {
    $vars['content'] = vsc_fusion_strip_tease($vars['node']->teaser, 450, $vars['nid']);
    } 
    break;
    case 'gallery':
     $vars['gallerylogo'] = vsc_fusion_return_gallery_logo($vars);
     $vars['gallerylocation'] = vsc_fusion_return_location($vars);
     break;
    case 'collection':
     $vars['collection'] = vsc_fusion_return_collection ($vars);
     if ($vars['page']){drupal_set_title(t('"@title" by @name', array('@title' =>  $vars['node']->title, '@name' =>  strip_tags($vars['node']->name))));}
     break;
    case 'event':
      $vars['eventgalleries'] = vsc_fusion_multiples_to_print($vars['node']->field_event_gallery, $class = "event-galleries", "Listed Galleries");
     $vars['eventartists'] = vsc_fusion_multiples_to_print($vars['node']->field_event_artists, $class = "event-artists", "Artists Involved");
     //$vars['gallerylogo'] = vsc_fusion_return_gallery_logo($vars);
     $vars['eventlocation'] = vsc_fusion_return_location($vars);
     break;
    case 'visual':
     //dsm($vars['node']->field_visual_image);
     $vars['visual_image'] = $vars['node']->field_visual_image[0]['view'];
     if ($vars['page']){drupal_set_title(t('"@title" by @name', array('@title' =>  $vars['node']->title, '@name' =>  strip_tags($vars['node']->name))));}
    //dsm($vars['node']->content['fivestar_widget']);
     // vars for teasers
     if($vars['teaser'] == TRUE) {
        //$vars['visual_image']= vsc_fusion_visual_or_media($vars);
        $vars['compiled_dimensions']= vsc_fusion_return_dimensions($vars);
        $vars['teaser_text'] = vsc_fusion_strip_tease($vars['node']->field_visual_substance[0]['value'], 450, $vars['nid']);
    }else{
       // vars for pages
        $vars['visual_bottom'] = vsc_fusion_return_visual_bottom($vars);
        $vars['fivestar'] = $vars['node']->content['fivestar_widget']['#value'];
      }
      break;
    case 'video':
     $vars['visual_media'] = $vars['node']->field_visual_media[0]['view'];
     // adding the video js hack
     if ($vars['node']->field_video_js[0]['value']){
     
     
     
        $vars['video_js'] = vsc_fusion_video_js_display($vars['node']);      
     }
     if ($vars['page']){drupal_set_title(t('"@title" by @name', array('@title' =>  $vars['node']->title, '@name' =>  strip_tags($vars['node']->name))));}
    // vars for teasers
     if($vars['teaser'] == TRUE) {
        //$vars['visual_image']= vsc_fusion_visual_or_media($vars);
        $vars['compiled_dimensions']= vsc_fusion_return_dimensions($vars);
        $vars['teaser_text'] = vsc_fusion_strip_tease($vars['node']->field_visual_substance[0]['value'], 450, $vars['nid']);
    }else{
       // vars for pages
        $vars['visual_bottom'] = vsc_fusion_return_visual_bottom($vars);
        $vars['fivestar'] = $vars['node']->content['fivestar_widget']['#value'];
      }
      break;
      }
 }

function vsc_fusion_return_artist_page ($name){
  $output = l(t('Visit the artist page of '.$name),'artist/'.$name, array('attributes' => array('class'=>'tip link-block large-text', 'title' => 'Each one of our artists has their own artist page where you can survey their work.')));
  return  vsc_fusion_build_div_markup("button-link", null, $output);
}

 function vsc_fusion_visual_or_media($visualNode){
   if($visualNode['field_visual_media'][0]['value']){
   $output = $visualNode['field_visual_media'][0]['data'];
   } else {
   $output = ' <img src="'.$visualNode['field_visual_image'][0]['filepath'].'" />';
   }
 return $output;
 }

function vsc_fusion_multiples_to_print($whatArray, $class = "multiple" , $title = null){
  if($whatArray[0]['view']){
  $sizeof = sizeof($whatArray)-1 ;
  $content = '';
  $content .= ($title) ? '<h2>'. t($title).'</h2>' :'';
  $content .= '<ul class="'.$class.'">';
  for($i = 0; $i <= $sizeof ; $i++){
      $printsize = $i + 1;
      $content .= '<li class="multiple-'.$i.'">'.$whatArray[$i]['view'].'</li>';
     }
  $content .= '</ul';
  return $content;
  }
}

/**
* Converts a string to a suitable html ID attribute.
* - Preceeds initial numeric with 'n' character.
* - Replaces space and underscore with dash.
* - Converts entire string to lowercase.
* - Works for classes too!
*
* @param string $string
*  the string
* @return
*  the converted string
*/
function vsc_fusion_id_safe($string) {
  if (is_numeric($string{0})) {
    $string = 'n'. $string;
  }
  return strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
}

/**
 * strips text for teaser. i couldn't resist this name ~ johnvsc
 */

function vsc_fusion_strip_tease ($body, $length, $nid){
        // Trim teaser and add "read more" link
        //dsm($vars['node']->field_visual_substance[0]['value']);
        //$body = $vars['node']->content['body']['#value'];
        $body_stripped = strip_tags($body, '<a><em><strong>');
        $body_trimmed = truncate_utf8($body_stripped, $length, TRUE, FALSE);
        $output = _filter_htmlcorrector($body_trimmed);
        $readmore = (drupal_strlen($body_stripped) > drupal_strlen($body_trimmed)) || $vars['readmore'];
        if ($readmore) {
          $more = '<span class="more"> &hellip; '. l(t('read more'), 'node/'. $nid) .' &gt;</span>';
          $output .= $more;
        }
        return $output;
}

/**
 * Override of theme_breadcrumb().
 */
function vsc_fusion_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $item = menu_get_item();
    $breadcrumb[] = '<span>'. $item['title'] .'</span>';
    return '<div class="breadcrumb">'. implode(' / ', $breadcrumb) .'</div>';
  }
}

/**
 * Override of theme_admin_block().
 */
function vsc_fusion_admin_block($block) {
  // Don't display the block if it has no content to display.
  if (empty($block['content'])) {
    return '';
  }

  $class = strtolower(preg_replace('/[^a-zA-Z0-9]/', '-', $block['title']));
  $output = <<< EOT
  <div class="admin-panel $class">
    <h3>
      $block[title]
    </h3>
    <div class="body">
      <p class="description">
        $block[description]
      </p>
      $block[content]
    </div>
  </div>
EOT;
  return $output;
}

/**
 * Build the visuals dimensions
 */
function vsc_fusion_return_dimensions($visualNode){
 // create variables to use below
 $title = $visualNode['title'];
 $dimension_type =  $visualNode['field_visual_dimension_type'][0]['safe'];
 $visual_height = $visualNode['field_visual_height'][0]['safe'].'h x ';
 $visual_width = $visualNode['field_visual_width'][0]['safe'].'w';
 $visual_duration = ($visualNode['field_visual_duration'][0]['safe']) ? '<br/>'.t('Time:').$visualNode['field_visual_length'][0]['safe'].' '.$visualNode['field_visual_duration'][0]['safe']:'';
 $visual_depth = ($visualNode['field_visual_depth'][0]['safe']) ? ' x '.$visualNode['field_visual_depth'][0]['safe'].'d':'';
 $output = $visual_height.$visual_width.$visual_depth.' '.$dimension_type.$visual_duration;
 return $output;
}

function vsc_fusion_return_visual_bottom($visualNode){
  // '<br/>'. $visualNode['submitted'].
 //$artistName = $visualNode['cc']->metadata['creator'];
 //$artistProfileLink = $visualNode['name'];//'<a href="users/'.$visualNode['name'].'">'.$artistName.'</a>';
 //$statement = '<div id="artist-statement" class="grid12-3 float-left first"><h3 class="block-title">'.$artistName.'\'s '. t('Artist Statement').'</h3>'.views_embed_view('artist_statement').'</div>';
 //$sharethis = vsc_fusion_return_sharethis("float-left");
 //$art_info = '<div id="picture-info">'.$sharethis.vsc_fusion_return_dimensions($visualNode).'<br/>'.$visualNode['terms'].'</div>';
 //$artist_page = '<div id="artist-page-link"><a href="/artist/'. strip_tags($artistProfileLink).'">'.t('Visit the artist page of '). strip_tags($artistProfileLink).'</a></div>';
 $substance = '<div id="visual-substance" class="grid12-4 float-left"><h3 class="block-title">'. t('About ').'"'.$visualNode['title'].'"</h3>'.$art_info.$visualNode['field_visual_substance'][0]['safe'].'</div>';
 //$gallery = '<div id="artist-gallery" class="grid12-4 float-left last">'.$artist_page.'<br/>'.views_embed_view('visual_grids').'</div>';
 return $substance.$gallery.$statement;
}

function vsc_fusion_return_sharethis($class = ""){
 $sharethis = '<div id="addthis" class="'.$class.'"><script type="text/javascript" src="http://w.sharethis.com/button/sharethis.js#publisher=271b49b4-3c2e-461e-a540-09151b9c9efd&amp;type=website"></script></div>';
return $sharethis;

}

function vsc_fusion_return_user_link($username, $pre = ""){
  // return  l(t($pre).$username,"user/".$username);
   return  t($pre).$username;
}

/**
 * theme_username() with added argument for uppercase
 */
function vsc_fusion_username($object, $upper = FALSE) {

  if ($object->uid && $object->name) {
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) .'...';
    }
    else {
      $name = $object->name;
    }

    if ($upper) {
      $name = drupal_strtoupper($name);
    }

    if (user_access('access user profiles')) {
      $output = l($name, 'user/'. $object->uid, array('title' => t('View user profile.')));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if ($object->homepage) {
      $output = l($object->name, $object->homepage);
    }
    else {
      $output = check_plain($object->name);
    }

    //$output .= ' ('. t('not verified') .')';
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }

  return $output;
}

function vsc_fusion_return_date_block($date,$string = 0) {
  //convert string to a UNIX timestamp!
  // if we need it !
  if($string) {
    $date = strtotime ($date);
  }
  $day   = date( 'd', $date);
  $month = date( 'F', $date);
  $year  = date( 'Y', $date);

  $date_block = '<div class="date-block">';
  $date_block .=  '<span class="month">' . $month . '</span>';
  $date_block .=  '<span class="day">' .  $day . '</span>';
  $date_block .=  '<span class="year">' . $year . '</span>';
  $date_block .= '</div>';

  $output = $date_block . $vars['content'];
  return $output;
}
function vsc_fusion_member_since($date ,$string = 0){
   if($string) {
    $date = strtotime ($date);
  }
  $day   = date( 'd', $date);
  $month = date( 'F', $date);
  $year  = date( 'Y', $date);
  $output = t('Member since '). $day.' '. $month .', '.$year;
  return $output;
}

/**
 * changing the title on the forms
 */
function vsc_fusion_candidate_node_form($form) {
    $title = t('Show your work on Visual Substance');
    drupal_set_title($title);
}
function vsc_fusion_visual_node_form($form) {
    $title = t('Add a Visual');
    drupal_set_title($title);
}
function vsc_fusion_video_node_form($form) {
    $title = t('Embed a Video');
    drupal_set_title($title);
}
function vsc_fusion_vsc_profile_node_form($form) {
    $title = t('Your profile for VSC internal use');
    drupal_set_title($title);
}
function vsc_fusion_profile_node_form($form) {
    $title = t('Your Public Profile');
    drupal_set_title($title);
}
function vsc_fusion_statement_node_form($form) {
    $title = t('Your Artist Statement');
    drupal_set_title($title);
}

function vsc_fusion_return_date_block_time($date,$string = 0) {
  //convert string to a UNIX timestamp!
  // if we need it !
  //$time  = date( 'g:ia', $date);
  if($string) {
    $date = strtotime ($date);
  }
  $day   = date( 'd', $date);
  $month = date( 'F', $date);
  $year  = date( 'Y', $date);
   $time  = date( 'g:ia', $date);
  $date_block = '<div class="date-block">';
  $date_block .=  '<span class="month">' . $month . '</span>';
  $date_block .=  '<span class="day">' .  $day . '</span>';
  $date_block .=  '<span class="year">' . $year . '<br/>'.$time.'</span>';
  $date_block .= '</div>';

  $output = $date_block . $vars['content'];
  return $output;
}

function vsc_fusion_return_gallery_logo($vars) {
   $logo =   $vars['field_gallery_logo'][0]['view'];
   $path = $vars['field_gallery_website'][0]['safe'];
   if ($path){
       $output = '<a href="'.$path.'" target="blank">'.$logo.'</a>';
   } else{
       $output = $path;
   }
   return $output;
}

function vsc_fusion_links($links, $attributes = array('class' => 'links')) {
  global $language;
  $output = '';
  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
       $class = 'menu-item-'.vsc_fusion_id_safe($link['title']);
       $class .= ' '.$key;
      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language->language)) {
        $class .= ' active';
      }
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

function vsc_fusion_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
  return '<li class="'. $class .'">'. $link . $menu ."</li>\n";
}


 function vsc_fusion_menu_item_link($link) {
  if (empty($link['options'])) {
    $link['options'] = array();
  }
  $menu_class_title = 'menu-item-'.vsc_fusion_id_safe($link['title']);
  $classes = array($menu_class_title);

  // If an item is a LOCAL TASK, render it as a tab
  if ($link['type'] & MENU_IS_LOCAL_TASK) {
    $link['title'] = '<span class="tab">'. check_plain($link['title']) .'</span>';
    $link['options']['html'] = TRUE;
  }

  if (empty($link['type'])) {
    $true = TRUE;
  }
  $link['options']['attributes'] = array('class' => vsc_fusion_implode_array($classes," "));
  return l($link['title'], $link['href'], $link['options']);
}

/**
 * _div_markup creates the content
 */
function vsc_fusion_build_div_markup($id ="region", $classes = null, $content ){
   $classesPrint = ($classes[0]) ? 'class="'.vsc_fusion_implode_array($classes," ").'"' : "";
   $output = '<div id="'.$id.'" '.$classesPrint.'>'.$content.'</div>';
   return $output;
}
/**
 * _div_markup creates the HTML around almost everything created by this theme
 */
function vsc_fusion_build_tag_markup($tag, $classes, $content ){
   $output = '<'.$tag.' class="'.$classes.'">'.$content.'</'.$tag.'>';
   return $output;
}

function vsc_fusion_implode_array($array, $space = " "){
   $output = implode($space, $array);
   return $output;
}
function vsc_fusion_return_location($vars){
  $location = $vars['location'];
  if($location){
  $output = vsc_fusion_build_tag_markup("h3", 'title', $location['name'] );
  $address = $location['street'].'<br/> '.$location['city'].', '.$location['province_name'].' '.$location['postal_code'].'<br/>'. $location['country_name'].'<br/>';
  $output .= vsc_fusion_build_tag_markup("span", 'address', $address);
  $output .= vsc_fusion_build_tag_markup("span", 'phone', $location['phone']);
  return $output;
  }
}
function vsc_fusion_classes_for_roles ($account){
  $roles = $account->roles;
  //this gets passed an array of a usrs roles
  $classes[] = '';
  if($roles[5]){
   $classes[] ='artist';
  }
  if($roles[6]){
   $classes[] ='gallery';
  }
  if($roles[8]){
   $classes[] ='patron';
  }
  $output = vsc_fusion_implode_array($classes);
  return $output;
}

function vsc_fusion_names_for_roles ($account){
  $roles = $account->roles;
  global $user;
    if ($account->uid == $user->uid && $user->uid > 0 && !$roles[7]) {
      $items[] = l(t('Edit your profile to gain "Aficionado" status!'), "user/$account->uid/edit");
    }
  if($roles[7]){
   $items[] ='<span class="">Aficionado</span>';
  }
  if($roles[5]){
   $items[] ='<span class="artist">Artist</span>';
  }
  if($roles[3] || $roles[4] ){
   $items[] ='<span class="vsc">Visual Substance Employee</span>';
  }
  if($roles[6]){
   $items[] ='<span class="dealer">Art Dealer</span>';
  }
  if($roles[8]){
   $items[] ='<span class="patron">Patron</span>';
  }
  // this was going to be a separate function, but it just is simpler to have it be here!
  if ($account->uid == $user->uid && $user->uid > 0 && !$account->picture) {
      $items[] = l(t('Upload a personal avatar!'), "user/$account->uid/edit");
    }

  $output = theme_item_list($items, NULL, $type = 'ul', NULL);
  return vsc_fusion_build_div_markup($id ="user-roles-list", null, $output );
}
function vsc_fusion_return_collection ($node){
  // snag the thumbnail size
  $thumbnail_size = $node['field_collection_thumbs_options'][0]['value'];
  $number_of_columns = vsc_fusion_return_collection_column($thumbnail_size);
  $end_of_row = $number_of_columns;
  $class = 'collection-thumb';
  $sort = $node['field_collection_sort'][0]['value'];
  //$vars['cover_art_big'] = theme('imagecache', 'discography_large', $vars['node']->field_album_cover[0]['filepath'], $vars['node']->field_artist[0]['view'] . ': ' . $vars['node']->title);
  // for each node, grab the full node front the db
  $images = $node['field_collection_artwork'];
  $nodes = Array();
 foreach($images as &$image){
  $num = (int)$image['nid'];
  $node = node_load($num);
  //let's take only what we need :)
  $nodes[] =  array(
       'nid' => $num,
       //we need a string version of the nid
       'sid' => $image['nid'],
       'title' => $node->title,
       'filepath' => $node->field_visual_image[0]['filepath'],
       'creator'=> $node->cc->metadata['creator'],
       'creation'=> $node->cc->metadata['date'],
       'delta'=> $node->field_visual_delta[0]['value'],
       );
 }
  // sort the nodes
  if($sort) {
  $nodes = vsc_fusion_subval_sort($nodes,$sort);
  }
  //build the thumbs
  $sizeof = sizeof($nodes);
  for($i = 0; $i < $sizeof; $i++ ) {
  $true_iteration = $i+1;
   if($true_iteration == $end_of_row){
    $class_override = " row-override";
    $end_of_row = $end_of_row + $number_of_columns;
   }else{
    $class_override = "";
   }
   $title = $nodes[$i]['creator'] . ': ' . $nodes[$i]['title'];
  //theme_imagecache($presetname, $path, $alt = '', $title = '', $attributes = NULL, $getsize = TRUE)
  //$content = theme('imagecache', $thumbnail_size, $nodes[$i]->filepath ,$title). '<br/>'.l($nodes[$i]->title,'node/'.$nodes[$i]->nid);
  //theme_imagefield_image_imagecache_thickbox($namespace, $path, $alt = '', $title = '', $gid = '', $attributes = NULL)
  $titleLink = ($number_of_columns < 7) ? l($nodes[$i]['title'],'node/'.$nodes[$i]['sid'],array('attributes' => array('class' => 'title',))) : l(t('View'),'node/'.$nodes[$i]['sid'],array('attributes' => array('class' => 'title',))) ;
  $content = $titleLink. '<br/>'. theme('imagefield_image_imagecache_thickbox', $thumbnail_size, $nodes[$i]['filepath'], $title, $title);
  $link = l($content,'node/'.$nodes[$i]['sid'], array('html' => TRUE, 'attributes' => array('title' => $title,)));
  $output .= vsc_fusion_build_tag_markup('div', $class.$class_override , $link);
  }
 return $output;
}
function vsc_fusion_return_collection_column($preset){
  switch ($preset){
   case "grid12-6-480px" :
   return 2 ;
   break;
   case "grid12-4-320px" :
   return 3 ;
   break;
      case "grid12-3-240px" :
   return 4 ;
   break;
      case "grid12-2-160px" :
   return 6 ;
   break;
      case "grid12-1-80px" :
   return 12 ;
   break;
  }
}

function vsc_fusion_subval_sort($a,$subkey) {
	foreach($a as $k=>$v) {
		$b[$k] = strtolower($v[$subkey]);
	}
	asort($b);
	foreach($b as $key=>$val) {
		$c[] = $a[$key];
	}
	return $c;
}

/**
 * Return code that emits an feed icon.
 *
 * @param $url
 *   The url of the feed.
 * @param $title
 *   A descriptive title of the feed.
  */
function vsc_fusion_feed_icon($url, $title) {
  $path = drupal_get_path_alias($_GET['q']);
  $page_match = drupal_match_path($path, 'explore*');
  if($page_match == 1){
    $node = node_load(44);
    $output = '<div id="full-screen">'.node_page_view($node, $cid = NULL).'</div>';
    return $output;
  }else{
  if ($image = theme('image', 'misc/feed.png', t('Syndicate content'), $title)) {
    return '<a href="'. check_url($url) .'" class="feed-icon">'. $image .'</a>';
  }
  }
}

/**
 * Generate HTML mark for flash content, using SWF Tools if it is available
 *
 * Flash node uses SWF Tools to handle JavaScript replacement but this isn't
 * always easy to set up. To assist users flash node will fall back to direct
 * HTML embedding if it can't find SWF Tools. This means flash node will work
 * 'out of the box' in a basic fashion, and is extended when SWF Tools is available
 * rather than being entirely dependent upon it.
 *
 * This function is called with an array of parameters that define a flashnode and an
 * optional array of parameters for swf tools.
 *
 * See the description of theme_flashnode for details.
 */
function vsc_fusion_flashnode_markup($flashnode, $options = array()) {

  // Generate HTML markup, using SWF Tools if available, fallback if not
  if (defined('SWFTOOLS_INSTALLED')) {

    // If a width is defined, add it to $params, else leave undefined
    if (round($flashnode['width'])) {
      $params['width'] = round($flashnode['width']);
    }

    // If a height is defined, add it to $params, else leave undefined
    if (round($flashnode['height'])) {
      $params['height'] = round($flashnode['height']);
    }

    // Store base setting to parameters array
    $params['base'] = $flashnode['base'];

    // Create additional parameters if any are provided, and merge
    $params = array_merge($params, flashnode_get_params($flashnode['params']));

    // Retrieve default substitution content if required
    // Note we are bypassing the filters here, so we assume the administrator
    // created valid mark-up that everyone else can use!
    $preview = t($flashnode['substitution'], array('!default' => variable_get('flashnode_default_html_alt', FLASHNODE_DEFAULT_HTML_ALT)));
    $othervars = array_merge($options, array('html_alt' => $preview));

    // Get HTML from SWF Tools
    // johnvsc injecting the media rss for the ssp :)
   $path = drupal_get_path_alias($_GET['q']);
   $page_match = drupal_match_path($path, 'explore*');
   if($page_match == 1){
    $options = array(
      'params' => $params,
      'flashvars' => "ssp=".arg(0)."&xmlfiletype=Media RSS",
      'othervars' => $othervars,
    );
    }else{
    $options = array(
      'params' => $params,
      'flashvars' => $flashnode['flashvars'],
      'othervars' => $othervars,
    );
    }

    // Assign filepath to $file
    $file = $flashnode['filepath'];

    // If using public download then encode spaces that the upload module may have allowed
    // Private downloads will do this for us
    if (variable_get('file_downloads', FILE_DOWNLOADS_PUBLIC) == FILE_DOWNLOADS_PUBLIC) {
      $file = str_replace(' ', '%20', $file);
    }

    // Generate markup by calling swf()
    $output = swf(file_create_url($file), $options);

    // Return result
    return $output;
  }

  // Initialise variable to ensure we only show error once if trying to render mp3 or flv with basic embedding
  static $markup_error_shown = false;

  // If file type is flv or mp3 we can't show it without SWF Tools
  if (preg_match('@flv|mp3$@i', $flashnode['filepath'])) {
    if (!$markup_error_shown) {
      drupal_set_message(t('Flash node needs <a href="@swftools">SWF Tools</a> in order to play mp3 or flv files.', array('@swftools' => 'http://drupal.org/project/swftools')), 'warning');
      $markup_error_shown = true;
    }
    return;
  }

  // Create path to the swf file
  $filepath = file_create_url($flashnode['filepath']);

  // Discard $base_root since this isn't needed for a local file
  $filepath = str_replace($GLOBALS['base_root'], '', $filepath);

  // Do the same for the base path
  $basepath = str_replace($GLOBALS['base_root'], '', $flashnode['base']);

  // Use t() to substitute parameters in to basic Flash markup
  $output = t('<div class="flashnode"><object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0" width="!width" height="!height" id="myMovieName"><param name="allowScriptAccess" value="sameDomain" /><param name="allowFullScreen" value="true" /><param name="movie" value="!filepath" /><param name="quality" value="high" /><param name="flashvars" value="!flashvars" /><param name="base" value="!base" /><embed src="!filepath" allowScriptAccess="sameDomain" allowFullScreen="true" quality="high" width="!width" height="!height" flashvars="!flashvars" name="myMovieName" align="" type="application/x-shockwave-flash" base="!base" pluginspage="http://www.macromedia.com/go/getflashplayer" /></object></div>',
    array(
      '!height' => $flashnode['height'],
      '!width' => $flashnode['width'],
      '!filepath' => $filepath,
      '!flashvars' => $flashnode['flashvars'],
      '!base' => $basepath,
    )
  );

  return $output;
}

/*
function theme_imagecache_imagelink($presetname, $path, $alt = '', $title = '', $attributes = NULL) {
  $image = theme('imagecache', $presetname, $path, $alt, $title);
  $original_image_url = file_create_url($path);
  return l($image, $original_image_url, array('absolute' => FALSE, 'html' => TRUE));
}*/
function vsc_fusion_video_js_display($node){
    // get the values that we need
    $src          = $node->field_video_js[0]['value'];
    $poster_image = substr($src ,0,-3) . 'png';
    $height       = ($node->field_visual_height[0]['value']) ? $node->field_visual_height[0]['value'] :  "896";    
    $width        = ($node->field_visual_width[0]['value']) ? $node->field_visual_width0[0]['value'] :  "504";
   
    // add the js file here
     $js_file = 'sites/libraries/video-js/video.js';
     drupal_add_js($js_file);
     // add the css file here
     $css_file = path_to_theme() . '/css/video-js.css';
     drupal_add_css($css_file); 
     $main_css_file = path_to_theme() . '/css/video-js-main.css';
     drupal_add_css($main_css_file);

     // package for output
     $output = '<!-- Begin VideoJS -->';
     $output .= ' 	<div class="video">';
     $output .= '		<div class="video-js-box cao-css">';
     $output .= '			<video id="main-video" class="video-js" width="'.$width.'" height="'.$height.'" controls="controls"  preload="true">';
     $output .= '				<source src="'.$src.'" type=\'video/mp4;  codecs="avc1.42E01E, mp4a.40.2"\' />';
     $output .= '';				
     $output .= '				<!-- Flash Fallback. Use any flash video player here. Make sure to keep the vjs-flash-fallback class. -->';
     $output .= '				<object id="flash_fallback_1" class="vjs-flash-fallback" width="'.$width.'" height="'.$height.'" style="visibility: visible;" type="application/x-shockwave-flash" data="http://releases.flowplayer.org/swf/flowplayer-3.2.1.swf">';
     $output .= '					<param name="movie" value="http://releases.flowplayer.org/swf/flowplayer-3.2.1.swf" />';
     $output .= '					<param name="allowfullscreen" value="true" />';
     $output .= '					<param name="flashvars" value=\'config={"playlist":["'.$poster_image.'", {"url": "'.$src.'","autoPlay":false,"autoBuffering":true}]}\' />';
     $output .= '					<!-- Image Fallback. Typically the same as the poster image. -->';
     $output .= '				</object>';
     $output .= '			</video>';
     $output .= '		</div>';
     $output .= '	</div>';
     $output .= '	<!-- End VideoJS -->';
     return $output;
}