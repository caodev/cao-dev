<?php
// $Id: node.tpl.php,v 1.1.2.3 2010/01/11 00:08:12 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <div class="inner">
  <?php if (!$page): ?>
  <!--for the content, we are letting drupal handle just the images-->

  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print t('@title by @name', array('@title' =>  $title, '@name' =>  strip_tags($name)));?>"><?php print t('"@title" by @name', array('@title' =>  $title, '@name' =>  strip_tags($name))); ?></h2>
      <div id="collection-info" class="content clearfix">
  <?php print ($field_collection_image[0]['view']) ? vsc_fusion_build_tag_markup('div', 'float-left', $field_collection_image[0]['view']) :'' ;?>
   <?php print ($submitted) ? vsc_fusion_build_tag_markup('div', 'submitted teaser', $submitted) :'' ;?>
  <?php print vsc_fusion_build_tag_markup('div', 'collection-substance', $field_visual_substance[0]['safe']) ;?>

  <?php print ($terms) ? vsc_fusion_build_tag_markup('span', 'terms', $terms) :'' ;?>
  </div>
  <?php endif; ?>   <!-- ending the $teaser -->

  <?php if ($page): ?>
  <?php print ($submitted) ? vsc_fusion_build_tag_markup('div', 'submitted', $submitted) :'' ;?>
  <!--for the content,again we are letting drupal handle just the images-->
  <div id="collection-info" class="content clearfix">
  <?php print ($field_collection_image[0]['view']) ? vsc_fusion_build_tag_markup('div', 'float-left', $field_collection_image[0]['view']) :'' ;?>
  <?php print vsc_fusion_build_tag_markup('div', 'collection-substance', $field_visual_substance[0]['safe']);?>
  </div>
  <div id="visual-collection" class="content clearfix"><?php print $collection ?></div>
  <div id="artist-five-star" class="content clearfix"><?php print $fivestar ?></div>
    <?php if ($node_bottom): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
      <?php endif; ?>
      <?php print ($terms) ? vsc_fusion_build_tag_markup('span', 'terms', $terms) :'' ;?>
      <?php print ($links) ? vsc_fusion_build_tag_markup('span', 'links', $links) :'' ;?>
  <?php endif;?> <!-- ending the $page -->
  </div><!-- /inner -->

</div><!-- /node-<?php print $node->nid; ?> -->
