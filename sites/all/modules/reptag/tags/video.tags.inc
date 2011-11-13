<?php
// $Id: video.tags.inc,v 1.2.2.1 2009/01/08 03:24:01 dman Exp $

/**
 * @file
 * Tags for embedding offsite videos like Youtube
 */

/**
 * Implimentation of _reptag_HOOK_init()
 */
function _reptag_video_init($context) {
  return array(
    "#{GOOGLEVIDEO:([\-0-9]*):(.*?):([0-9]*)x([0-9]*)}#e"     => "_reptag_video_googlevideo('\\1', \\3, \\4, '\\2');",
    "#{GOOGLEVIDEO:([\-0-9]*):([0-9]*)x([0-9]*)}#e"           => "_reptag_video_googlevideo('\\1', \\2, \\3);",
    "#{GOOGLEVIDEO:([\-0-9]*):(.*?)}#e"                       => "_reptag_video_googlevideo('\\1', 400, 350, \\2);",
    "#{GOOGLEVIDEO:([\-0-9]*)}#e"                             => "_reptag_video_googlevideo('\\1');",
    
    "#{YOUTUBE:(.*?):([0-9]*)x([0-9]*)}#e"                    => "_reptag_video_youtubevideo('\\1', \\2, \\3);",
    "#{YOUTUBE:(.*?)}#e"                                      => "_reptag_video_youtubevideo('\\1');",
    
    "#{MYSPACE:([0-9]*):([0-9]*)x([0-9]*)}#e"                 => "_reptag_video_myspacevideo('\\1', \\2, \\3);",
    "#{MYSPACE:([0-9]*)}#e"                                   => "_reptag_video_myspacevideo('\\1');",
    
    "#{IFILM:([0-9]*):([0-9]*)x([0-9]*)}#e"                   => "_reptag_video_ifilm('\\1', \\2, \\3);",
    "#{IFILM:([0-9]*)}#e"                                     => "_reptag_video_ifilm('\\1');"
  );
}

function _reptag_video_info() {
  return array(t('Video embedding tags (Google, YouTube, MySpace, iFilm)'), TRUE);
}

function _reptag_video_help() {
  return array(
    "{GOOGLEVIDEO:id:title:50x50}"      => "Google Video with title and dimensions (width x height)",
    "{GOOGLEVIDEO:id:50x50}"            => "Google Video with dimensions (width x height)",
    "{GOOGLEVIDEO:id:title}"            => "Google Video with title",
    "{GOOGLEVIDEO:id}"                  => "Google Video (replace id with the docid from your Google video)",
    
    "{YOUTUBE:id:50x50}"                => "YouTube Video with dimensions (width x height)",
    "{YOUTUBE:id}"                      => "YouTube Video (replace id with the 'v' id from your YouTube video)",
    
    "{MYSPACE:id:50x50}"                => "MySpace Video with dimensions (width x height)",
    "{MYSPACE:id}"                      => "MySpace Video (replace id with the 'videoid' id from your MySpace video)",
    
    "{IFILM:id:50x50}"                  => "iFilm Video with dimensions (width x height)",
    "{IFILM:id}"                        => "iFilm Video (replace id with the id from your iFilm video)"
  );
}

function _reptag_video_googlevideo($googleid, $width = 400, $height = 350, $googleh1 = '') {
  $googleh1 = urlencode($googleh1);
  $output = <<<EOF
    <embed style="height:${height}px; width:${width}px;"
    id="VideoPlayback" type="application/x-shockwave-flash" src="http://video.google.com/googleplayer.swf?docId=$googleid&hl=$googleh1" flashvars="">
    </embed>
EOF;

  return $output;
}

function _reptag_video_youtubevideo($youtubeid, $width = 400, $height = 350) {
  $output = <<<EOF
    <object width="$width" height="$height">
    <param name="movie" value="http://www.youtube.com/v/$youtubeid"></param>
    <param name="wmode" value="transparent"></param>
    <embed src="http://www.youtube.com/v/$youtubeid" type="application/x-shockwave-flash" wmode="transparent" height="$height" width="$width"></embed>
    </object>
EOF;

  return $output;
}

function _reptag_video_myspacevideo($myspaceid, $width = 430, $height = 346) {
  $output = <<<EOF
    <embed src="http://lads.myspace.com/videos/vplayer.swf"
    flashvars="m=$myspaceid&type=video" type="application/x-shockwave-flash" height="$height" width="$width">
    </embed>
EOF;

  return $output;
}

function _reptag_video_ifilm($ifilmid, $width = 448, $height = 365) {
  $output = <<<EOF
    <embed height="$height" width="$width" src="http://www.ifilm.com/efp" quality="high" bgcolor="000000" name="efp" align="middle" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" flashvars="flvbaseclip=$ifilmid&">
    </embed>
EOF;

  return $output;
}
