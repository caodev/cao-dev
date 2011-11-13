<?php
// $Id: node.tpl.php,v 1.1.2.3 2010/01/11 00:08:12 sociotech Exp $
?>

<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <div class="inner">

  <?php if (!$page): ?>
      <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<div id="event-date" class="float-left"><?php print vsc_fusion_return_date_block_time($field_event_time[0]['value'],1); ?></div>
     <div id="event-location" class="float-left"><?php print $eventlocation;?></div>
     <div id="event-info" class="border float-left"><?php print $field_event_description[0]['safe'] ?></div>
    <?php endif; ?>   <!-- ending the $teaser -->

  <?php if ($page): ?>
 <?php if ($submitted): ?>
 <div class="meta">
   <span class="submitted"><?php print $submitted ?></span>
 </div>
 <?php endif; ?>
   <div class="content clearfix">
      <?php print vsc_fusion_return_sharethis("float-right"); ?>
    <div id="event-details" <?php print ($eventlocation) ? 'class="grid12-3 float-left"' : 'class="grid12-1 float-left"'; ?>>
     <div id="event-date" class="float-left"><?php print vsc_fusion_return_date_block_time($field_event_time[0]['value'],1); ?></div>
 <div id="event-location"><?php print $eventlocation;?></div><br /><?php print $field_gallery_email[0]['safe']; ?></div>
<div id="event-image" class="float-left clear"><?php print  $field_event_picture[0]['view']; ?></div>
<div id="event-info"  <?php print ($eventlocation) ? 'class="grid12-7 grid12-indent-3 border"' : 'class="grid12-9 grid12-indent-1 border"'; ?>><div id="event-description"><?php print  $field_event_description[0]['safe'] ?></div><div id="event-artists"><?php print $eventartists;?></div><br />
<div id="event-galleries"><?php print $eventgalleries;?></div> 
        </div> <!-- end event-detials -->
      </div> <!-- end content -->
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
