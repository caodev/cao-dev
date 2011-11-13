$Id: README.txt,v 1.4 2008/06/23 23:20:38 kbahey Exp $

Image Watermark

by Khalid Baheyeldin of http://2bits.com
modified by schnizZzla for http://BerlinerStrassen.com

Scaling option based on patch (http://drupal.org/node/81161)
by michael curry (inactivist) of http://exodusdev.com/

Description:
-------------

This modules allows a Drupal site running the image module to overlay each image
with a watermark.

- Path for watermark is configurable.
- The location of the watermark can be any one of nine positions.
- Can select which images to apply the watermark to (e.g. preview and _original, but
  not thumbnail.
- Preserve original image type after watermark has been applied
- Support alpha blending
- Apply watermark only when a new image is uploaded, do not not apply watermarks twice!
- Apply watermark on previews, too
- Watermark can be scaled, percentage of image width and minimum width in pixels can be set.
- Toggle: Exclude image nodes with specific gallery terms from watermark

Known Limitations:
- Changing watermark settings does not work retroactive, watermark settings apply to
  new images only.
- Saving image module settings "breaks" watermark SETTINGS, even if you did not change
  anything. That means watermarks disappear or apply to all image sizes, when the node
  or gallery is viewed.


Requirements:
-------------

This module requires no patches to Drupal nor image module.

It does require the PHP GD library to be configured by your host, and
PHP must be compiled in with --enable-exif.

GD is enabled by default in PHP 4.3 and later, and can be added
to earlier version if compiled in them.
For more information see http://php.net/image

The module was tested with PHP 4.4.0 and 5.1.2, but should work with other
versions that had GD.

Check the output of phpinfo() from your server to see if you have all
required pieces.

Usage:
------

Enable the module and navigate to admin/settings/image_watermark to enable watermark processing
for new image uploads.

To do:
------
- complete implementation of watermark_admin_settings_validate
- complete watchdog error reports
- animated gif support (a detection to exclude gif images automatically or a method to process animated gifs)
