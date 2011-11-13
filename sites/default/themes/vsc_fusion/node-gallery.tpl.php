<?php
// $Id: node.tpl.php,v 1.1.2.3 2010/01/11 00:08:12 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <div class="inner">

  <?php if (!$page): ?>
      <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<div id="gallery-logo" class="float-left"><?php print $field_visual_image[0]['view']; ?></div>
<div class="float-left"><?php print $field_gallery_raison_detre[0]['safe'] ?></div>
    <div class="submitted float-right">
     <div id="gallery-info"><?php print $gallerylocation;?></div>
     <?php print vsc_fusion_member_since($created); ?><br/>
    </div>
    <?php endif; ?>   <!-- ending the $teaser -->

  <?php if ($page): ?>

    <div class="content clearfix">
      <?php print vsc_fusion_return_sharethis("float-right"); ?>
     <div id="gallery-logo" class="float-left"><?php print $gallerylogo ?></div>
     <div id=gallery-stats" class="float-left clear"><?php $email = $field_gallery_email[0]['safe']; $website = $field_gallery_website[0]['value']; print $gallerylocation .'<a href="mailto:'.$email.'">'.$email.'</a>' .'<br/>'. l($website, $website).'<br/>'.vsc_fusion_member_since($created); ?></div>
     <div id="gallery-info"><?php print $field_gallery_raison_detre[0]['safe'] ?></div>
      </div>

        <?php if ($node_bottom && !$teaser): ?>
	<div id="node-bottom" class="node-bottom row nested">
	<div id="node-bottom-inner" class="node-bottom-inner inner">
	<?php print $node_bottom; ?>
	</div><!-- /node-bottom-inner -->
	</div><!-- /node-bottom -->
	<?php endif; ?>

      <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
    <?php endif; ?>
  <?php endif;?> <!-- ending the $page -->

</div>
</div>
