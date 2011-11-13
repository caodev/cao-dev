*****************************************************************************
                     R E P L A C E M E N T    T A G S
*****************************************************************************
Name: reptag module
Author: Thilo Wawrzik <drupal at profix898 dot de>
Drupal: 6.x
*****************************************************************************
DESCRIPTION:

The Rep[lacement]Tags module allows you to define tags (like $MYTAG$
or {DATE}) and replace them with user-defined text, images, code, ...
or use RepTag to format your pages with simple markup-style tags.

This is especially useful to save typing-time when similar phrases or
or complex text-pattern are used frequently.

*****************************************************************************
INSTALLATION:

1. Place the whole reptag folder into your Drupal sites/x/modules/
     directory.

2. Enable the reptag module by navigating to
     Administer > Site Building > Modules (admin/build/modules)
     
3. Bring up the reptag configuration screen by navigating to
     Administer > Site Configuration > RepTag (admin/settings/reptag)
     
4. Configure all settings after your fancy
   
5. Click "Save Configuration".

*****************************************************************************
UPDATE:

1. Replace all files with the latest version and run 'update.php'

2. It is very recommended to enable 'PartialCache' feature under
   'Settings / General / Expert-Settings' to increase performance.

*****************************************************************************

Visit http://www.profix898.de/drupal/reptag to read more
detailed documentation on the Rep[lacement]Tags module.

! You can use module tags in the replacement of site/user tags. This
is possible because module tags are processed after the table tags.
(order of execution: table tags first -> then module tags by weight)

*****************************************************************************
DETAILED DESCRIPTION:

The reptag module makes three different types of replacement tags
available to the user.

+ Module - Replacement Tags
There are several .tags modules in the reptag folder. Theses module
are using some kind of plugin framework to extend the basic reptag
functionality. All these modules export certain tags.
For example system.tags adds Date, Time, User ... tags like {DATE} or
{USERNAME}, which are replaced with the current date and username,
node.tags exports {AUTHOR} representing the current node's author ...
For detailed information on .tags modules take a look at sample.tags_
and read the DEVELOPER.txt documentation.

+ SiteWide - Replacement Tags
SiteWide replacement tags can be used by everyone on your site (thats
why they are called site wide ;)) These tags can be managed by users
with 'manage sitewide reptags' permission.

+ User - Replacement Tags
Every user with 'manage user reptags' permission can define his/her
own tags in addition to the modules tags and site wide tags. The
user-defined tags are available only on nodes created by the user and
have a higher priority than site wide ones by default.

SiteWide- and User-Tags are managed from the reptag administration
pages. You can easily add/delete/modify these tags online.
On sites using the 'workspace' module users can manage their reptags
from a tab within their workspace (assumed you grant them 'manage
user reptags' permissions).

Reptag provides a powerful rights management. You can enable/disable
tags modules per role and define 'exclude tags' to disable distinct
tags (modules or sitewide/user) for use in certain roles.
Additionally you can select the content fields to run the replacement
process on. What means you can also run reptag on cck (text) fields.

Reptag module provides online help and automatically generates an
overview table of all tags available for the current node and user.
You can find it under 'Rep[lacement]Tags - Help' on every node
creation form.

Read the documentation to get more information and guidelines on
how to configure, use and extend the Rep[lacement]Tags module.

*****************************************************************************
ABOUT PARTIAL CACHE

Many tags are static, what means they do not change with the user or
time a node is displayed. SiteWide- and User-Tags are always static
and .tags-Modules are marked internally static/dynamic. Most benefit
from above distinction is the ability to cache all static parts of a
node. That provides a performance boost, since most nodes are no
longer processed on every view.

*****************************************************************************
Have fun with reptag, Thilo.
