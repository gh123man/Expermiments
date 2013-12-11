<?php
/*
    By Brian Floersch (gh123man@gmail.com)
    An autonomous browser cache manager.
*/

class PHPC {

    public static function js($uri) {
        return '<script type="text/javascript" src="' . PHPC::uri($uri) . '"></script>' . "\n";
    }
    
    public static function css($uri) {
        return '<LINK href="' . PHPC::uri($uri) . '" rel="stylesheet" type="text/css">' . "\n";
    }
    
    public static function uri($uri) {
        if (substr($uri, 0, 1) == "/") {
            $localFile = substr($uri, 1, strlen($uri));
        } else {
            $localFile = $uri;
        }
       
        return $uri . "?PHPC=" . filemtime($localFile);
    }
}

?>
