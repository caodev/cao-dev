<?php
/**
 * @file
 * Displays the wrapper of Galleria.
 *
 * @ingroup views_templates
 */
?>
<div class="item-list views-galleria <?php print $views_galleria_id ?> clear-block">
  <div id="main_image"></div>
  <ul class="galleria" id="<?php print $views_galleria_id ?>">
    <?php foreach ($rows as $row): ?>
      <li><?php print $row ?></li>
    <?php endforeach; ?>
  </ul>
  <p class="galleria-nav"><a href="#" onclick="$.galleria.prev(); return false;"><?php echo t('&laquo; previous') ?></a> | <a href="#" onclick="$.galleria.next(); return false;"><?php echo t('next &raquo;') ?> </a></p>
</div>
