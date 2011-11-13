$(function(){
	$('.two-c').columnize({columns: 2 });
	$('.three-c').columnize({columns: 3 });
	$('.four-c').columnize({columns: 4 });
});
 $(document).ready(function() {
    $('a.tip').tinyTips('title');
	$(".vjs-progress-control").live("mouseover mouseout click",
		function (event) {
			if (event.type == "mouseover") $('.vjs-time-control').show();
			else if (event.type == "mouseout") $('.vjs-time-control').hide();
		});
	$(".embed-link").click(function(){
		$(this).parent().toggleClass("clicked");
	});
	$(".overlay-switch").live(
		"mouseover mouseout click",
		function (event) {
			if (event.type == "mouseover") {
				$('#wrapper').fadeOut();
				$('.overlay-switch').find('span').html('OFF');
			}
			else if (event.type == "mouseout"){
				$('#wrapper').fadeIn();
				$('.overlay-switch').find('span').html('ON');}
			else $('#wrapper').addClass('clicked');
		});
$('.vjs-fullscreen-control').live('click',function(){
	$('body').toggleClass('vjs-fullscreen');
});
	var overlay = $(".overlay-controls").length;
	if(overlay){
		$(".vjs-controls").append("<div class='overlay-switch'>OVERLAY <span>ON</span></div><div class='legal-link'><a href='http://cao.usvinc.com/' target='_blank'> © MMXI</a></div>");
	}	    
});

VideoJS.DOMReady(function(){			
			
			var myPlayer = VideoJS.setup("main-video");
			myPlayer.options = {
				controlsAtStart: true, 
				controlsHiding: false
			};
});