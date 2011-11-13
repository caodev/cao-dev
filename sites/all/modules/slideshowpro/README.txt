// $Id: README.txt,v 1.4 2009/02/27 00:37:38 alexb Exp $

SLIDESHOWPRO MODULE

Slideshow Pro Integration for Drupal Image Module

[ Please note this version of the module is an unofficial Drupal 6 port supplied by danielb http://drupal.org/user/134005 ]

---------------------------------------------------------------------------------------------------


REQUIRED MODULES
Views http://www.drupal.org/project/views

RECOMMENDED MODULES
Image and Image Gallery http://www.drupal.org/project/image


---------------------------------------------------------------------------------------------------


INSTALLATION

1) Get Slideshow Pro from http://www.slideshowpro.net 
   and create an swf file like described in ssphowto.png, export the flash movie as ssp.swf to the slideshowpro module directory. Be sure to start with an ActionScript 2 file and use the AS2 version of the extension.

2) Install the module

3) Configure module at Administer -> Site Configuration -> Slideshow Pro integration (admin/settings/ssp)

4) You can now create a slide show feed with Views module:
	- Create a Node View
	- Add a new Display of type 'Feed'
	- Set the Style to 'SlideShowPro: XML feed'
	- Set the Row style to 'Node'
	- Set the Path for the feed e.g. 'path/to/your/feed'
	- Set up your custom Filters (e.g. to only show published nodes, and your content type or categories, etc..)

5) Go to Administer -> Site Configuration -> Input formats (admin/settings/filters) and turn on "Inline SSP Slideshows" for 
   the input format of your choice.

5) Embed the slideshow by adding the following filter macro to the body of your post
	[ssp|path=path/to/your/feed]
	[ssp|path=path/to/your/feed|width=300]
	[ssp|path=path/to/your/feed|width=300|height=200]
	There are also more advanced options like:
	[ssp|path=path/to/your/feed|width=300|height=200|params=autoFinishMode:Restart,navAppearance:Hidden]
	you should be able to pass in any kind of documented SSP setting.
	* Refer to your SSP User Guide for more options. 
	* Use camelCase for options spelled Camel Case. 


---------------------------------------------------------------------------------------------------


ACTION SCRIPT SNIPPET FOR YOUR SWF

Put this action script snippet into frame no 1 of your flash application. 
This snippet copies all values passed in from HTML to the SSP component.
Keep the settings on the SSP component to their defaults if you would like
to set them with the filter macro. 

// begin
// ssp is the name of your SSP component Movie Clip
ssp.xmlFilePath = unescape(xmlfilepath);
ssp_vars = parameters.split(',');
for (var i = 0; i < ssp_vars.length; i++) {
	var_value = ssp_vars[i].split(':');
	if (var_value[1] == "True") {
		var_value[1] = true;
	}
	else if (var_value[1] == "False") {
		var_value[1] = false;
	}
	ssp[var_value[0]] = var_value[1];
}
// end


---------------------------------------------------------------------------------------------------


SSP AND CCK FIELDS

For using SlideShowPro together with CCK fields such as the image field, follow the 
instructions here: http://drupal.org/node/195274#comment-649275
(BTW: a how-to write up for this readme file would be highly appreciated)