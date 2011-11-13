$Id: README.txt,v 1.2 2009/05/16 20:00:38 lipcpro Exp $
Description
-----------------------
Another tool in the fight against spam and false users

Author
-----------------------
Wes Roepken < wes at lipcpro dot com >

Features
-----------------------
When you first install Spamicide, it inserts an input field on certain core
forms as a first line of defense against comment spam, bogus users, etc...
the field is then hidden with a very small .css file, if the spammer or his bot
fills in the field the form is rejected with no notice to the user, redirecting
back to the same page if it's not the login page (else the home page).

It provides better usability (no user interaction at all) and smaller code
base (no large database tables or need to communicate with another site) than
other alternatives.

The admin interface provides the ability
1) to enable/disable it for the base core forms mentioned and delete others
2) to add forms for Spamicide to protect if you know the form id
3) add links for admins to add the from on any form a module might provide
4) to enable logging of attempts to spam your site with the ip address of
the attacker
5) to change the name of the field if logs show that the spammers have
learned how to defeat this trick with that particular name

Needed
-----------------------
Help with translations, feedback, suggestions.