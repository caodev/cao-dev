<div id="reptag-dialog" class="reptag-dialog">
  <div class="reptag-dialog-bar">
    <?php if (!empty($title)) { print $title; } ?>
    <div class="reptag-dialog-close">
      <a href="#" id="reptag-dialog-close">
        <img src="<?php print base_path() . drupal_get_path('module', 'reptag') .'/images/close.png'; ?>" alt="" />
      </a>
    </div>
  </div>
  <div id="reptag-dialog-content" class="reptag-dialog-content">
    <?php if (empty($content)) { ?>
    <div class="reptag-dialog-load">
      <img src="<?php print base_path() . drupal_get_path('module', 'reptag') .'/images/busy.gif'; ?>" alt="" />
    </div>
    <?php } else { print $content; } ?>
  </div>
</div>
