<?php
// $Id: node.tpl.php,v 1.1.2.3 2010/01/11 00:08:12 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <div class="inner">
  <?php if (!$page): ?>
  <!--for the content, we are letting drupal handle just the images-->
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print t('@title by @name', array('@title' =>  $title, '@name' =>  strip_tags($name)));?>"><?php print t('"@title"', array('@title' =>  $title)); ?></h2>
  <div class="grid12-3 float-left"><?php print $visual_media; ?></div>
  <div class="grid12-3 float-left"> <?php print vsc_fusion_return_user_link($name,'by ').' ('.$cc->metadata['creator'].')';?>
  <div id="picture-info-teaser" ><?php print $compiled_dimensions; ?><span class="submitted"><?php print $submitted ?></span><br /><span class="terms"><?php print t('Tagged as'); ?>: <?php print $terms; ?></span></div>
</div>
    <div class="grid12-5 float-left"><?php print $teaser_text; ?></div>
  <?php endif; ?>   <!-- ending the $teaser -->

  <?php if ($page): ?>

  <!--for the content,again we are letting drupal handle just the images-->
  <div id="artist-visual" class="content clearfix"><?php print $visual_media ?></div>
  <div id="video-js" class="content clearfix"><?php print $video_js ?></div>
  <div id="artist-five-star" class="content clearfix"><?php print $fivestar ?></div>

  <div id="visual-bottom" class="clearfix"><?php print $visual_bottom ?></div>

    <?php if ($node_bottom): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
      <?php endif; ?>
      <?php print ($links) ? vsc_fusion_build_tag_markup('span', 'links', $links) :'' ;?>
  <?php endif;?> <!-- ending the $page -->
  </div><!-- /inner -->

</div><!-- /node-<?php print $node->nid; ?> -->
