<?php
// $Id: image.tags.inc,v 1.2.2.2 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Image embedding and layout tags
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_image_init($context) {
  return array(
    
    "#{IMAGE:([0-9]*)x([0-9]*):(.*?)}#e"        => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' />'",  
    "#{IMAGE:(.*?)}#e"                          => "'<img src=\'\\1\' alt=\'\' />'",
    
    "#{IMG:([0-9]*)x([0-9]*):(.*?)}#e"          => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' />'",
    "#{IMG:(.*?)}#e"                            => "'<img src=\'\\1\' alt=\'\' />'",
    
    "#{IMAGELEFT:([0-9]*)x([0-9]*):(.*?)}#e"    => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' align=\'left\' />'",
    "#{IMAGELEFT:(.*?)}#e"                      => "'<img src=\'\\1\' alt=\'\' align=\'left\' />'",
    "#{IMGLEFT:([0-9]*)x([0-9]*):(.*?)}#e"      => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' align=\'left\' />'",
    "#{IMGLEFT:(.*?)}#e"                        => "'<img src=\'\\1\' alt=\'\' align=\'left\' />'",
    
    "#{IMAGERIGHT:([0-9]*)x([0-9]*):(.*?)}#e"   => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' align=\'right\' />'",
    "#{IMAGERIGHT:(.*?)}#e"                     => "'<img src=\'\\1\' alt=\'\' align=\'right\' />'",
    "#{IMGRIGHT:([0-9]*)x([0-9]*):(.*?)}#e"     => "'<img src=\'\\3\' alt=\'\' width=\'\\1\' height=\'\\2\' align=\'right\' />'",
    "#{IMGRIGHT:(.*?)}#e"                       => "'<img src=\'\\1\' alt=\'\' align=\'right\' />'",
  
    "#{SPACER:([0-9]*)x([0-9]*)}#e"                   => "'<img src=\"'. _reptag_image_spacer('\\1', '\\2') .'\" width=\'\\1\' height=\'\\2\' alt=\'\' />'",
    "#{SPACERLEFT:([0-9]*)x([0-9]*)}#e"               => "'<img src=\"'. _reptag_image_spacer('\\1', '\\2') .'\" width=\'\\1\' height=\'\\2\' alt=\'\' align=\'left\' />'",
    "#{SPACERRIGHT:([0-9]*)x([0-9]*)}#e"              => "'<img src=\"'. _reptag_image_spacer('\\1', '\\2') .'\" width=\'\\1\' height=\'\\2\' alt=\'\' align=\'right\' />'"
    
  );
}

function _reptag_image_info() {
  return array(t('Images (IMG, IMGLEFT, SPACER, ...)'), TRUE);
}

function _reptag_image_help() {
  $basepath_images = base_path() . drupal_get_path('module', 'reptag') .'/images';
  
  return array(
    
    "{IMAGE:50x50:path/to/sample.png}"        => "text<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' />text",
    "{IMAGE:path/to/sample.png}"              => "text<img src='". $basepath_images ."/sample.png' alt='' />text",
    
    "{IMG:50x50:path/to/sample.png}"          => "<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' />text",
    "{IMG:path/to/sample.png}"                => "<img src='". $basepath_images ."/sample.png' alt='' />text",
    
    "{IMAGELEFT:50x50:path/to/sample.png}"    => "<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' align='left' />text",
    "{IMAGELEFT:path/to/sample.png}"          => "<img src='". $basepath_images ."/sample.png' alt='' align='left' />text",
    "{IMGLEFT:50x50:path/to/sample.png}"      => "<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' align='left' />text",
    "{IMGLEFT:path/to/sample.png}"            => "<img src='". $basepath_images ."/sample.png' alt='' align='left' />text",
    
    "{IMAGERIGHT:50x50:path/to/sample.png}"   => "text<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' align='right' />",
    "{IMAGERIGHT:path/to/sample.png}"         => "text<img src='". $basepath_images ."/sample.png' alt='' align='right' />",
    "{IMGRIGHT:50x50:path/to/sample.png}"     => "text<img src='". $basepath_images ."/sample.png' alt='' width='50' height='50' align='right' />",
    "{IMGRIGHT:path/to/sample.png}"           => "text<img src='". $basepath_images ."/sample.png' alt='' align='right' />",
  
    "{SPACER:100x20}"                         => "text<img src='". _reptag_image_spacer(100, 20) ."' width=\'100\' height=\'20\' alt='' />text",
    "{SPACERLEFT:100x10}"                     => "<img src='". _reptag_image_spacer(100, 10) ."' width=\'100\' height=\'10\' alt='' align='left' />text",
    "{SPACERRIGHT:100x10}"                    => "<img src='". _reptag_image_spacer(100, 10) ."' width=\'100\' height=\'10\' alt='' align='right' />text"
    
  );
}

function _reptag_image_spacer($width, $height) {
  if (function_exists('imagegif')) {
    $img = imagecreate($width, $height);
    $bkg = imagecolorallocate($img, 0, 255, 255);
    imagefill($img, 0, 0, $bkg);
    imagecolortransparent($img, $bkg);
    ob_start();
    imagegif($img);
    $data = ob_get_contents();
    ob_end_clean();
    imagedestroy($img);
    
    return 'data:image/gif;base64,'. base64_encode($data);
  }
  else {
    $spacergif = 'data:image/gif;base64,R0lGODlhZAAUAIAAAAD//wAAACH5BAEAAAAALAAAAABkABQAAAIshI+py+0Po5y02ouz3rz7D4biSJbmiabqyrbuC8fyTNf2jef6zvf+DwwKZwUAOw==';
    
    return $spacergif;
  }
}
