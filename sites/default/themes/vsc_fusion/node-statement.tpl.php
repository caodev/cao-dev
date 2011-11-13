<?php
// $Id: content_profile-display-view.tpl.php,v 1.1.2.2 2009/01/04 11:46:29 fago Exp $

/**
 * @file content-profile-display-view.tpl.php
 *
 * Theme implementation to display a content-profile.
 */
 ?>

<div class="content-profile-display" id="content-profile-display-<?php print $type; ?>">
  <?php if (isset($tabs)) : ?>
    <ul class="tabs content-profile">
      <?php foreach ($tabs as $tab) : ?>
        <?php if ($tab): ?>
          <li><?php print $tab; ?></li>
        <?php endif; ?>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
  <?php if (isset($node->nid) && isset($content)){
      if(arg(0) == 'user'|| $teaser){
        print vsc_fusion_strip_tease($node->field_artist_statement[0]['safe'], 400, $node->nid);
      }else {
       $output = '<div class="meta"><span class="submitted">'.$submitted.'</span></div>'.vsc_fusion_build_tag_markup('div', 'float-left', $node->field_artist_picture[0]['view']). vsc_fusion_build_tag_markup('div', 'content two-c', $node->field_artist_statement[0]['safe']);
       $output .= '<hr/>'.vsc_fusion_build_tag_markup('h2', 'node-title', t('Biography')).vsc_fusion_build_tag_markup('div', 'content clear two-c', $node->field_artist_biography[0]['safe']).$artistpagelink ;
       print $output;
      }
  }
  ?>
</div>
