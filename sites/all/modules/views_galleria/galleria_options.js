var options = {
  onImage : function(image, caption, thumb) {
    // let's add some image effects for demonstration purposes
    // fade in the image & caption
    if(!($.browser.mozilla && navigator.appVersion.indexOf("Win")!=-1) ) { // FF/Win fades large images terribly slow
      image.css('display','none').fadeIn(500);
    }
    caption.css('display','none').fadeIn(500);

    // fetch the thumbnail container
    var _li = thumb.parents('li');

    // fade out inactive thumbnail
    _li.siblings().find('.selected').fadeTo('fast',0.7).removeClass('selected');

    // fade in active thumbnail
    thumb.fadeTo('fast',1).addClass('selected');

    // add a title for the clickable image
    image.attr('title','Next image >>');

    $('.galleria-nav').show();
  },

  onThumb : function(thumb) {
    // thumbnail effects goes here
    // fetch the thumbnail container
    var _li = thumb.parents('li');

    // if thumbnail is active, fade all the way.
    var _fadeTo = _li.is('.active') ? 1 : 0.7;

    // fade in the thumbnail when finished loading
    thumb.css({display:'none',opacity: 0.7}).fadeIn(500);

    // hover effects
    thumb.hover(
      function() { thumb.fadeTo('fast', 1); },
      function() { _li.not('.active').find('img').fadeTo('fast', 0.7); } // don't fade out if the parent is active
    )
  },

  history : false
};

// run Galleria in Drupal.behaviors
Drupal.behaviors.initGalleria = function(context) {
  // init on plain gallerias
  var $g = $('#main_image').next();
  $('> li',$g).each(function(i){ $(this).html($('span',this).html() ); });
  $g.galleria(options);
  gal_exdtend();
  // when the ajax call is complete, load galleria - used when viewing in a lightbox!
  $('body').bind("ajaxComplete", function() {
    $g.galleria(options);
    gal_exdtend();
  });

  function gal_exdtend() {
   $g.find('> li:first').addClass('active').each(function(i){
      $(this).trigger('click');
   });
  }

};
