<?php

function varJS($name, $value) {

    $out = "";
    $out .= "<script>"; 
    
    $out .= "var " . $name . " = '" . $value . "';";
    
    $out .= "</script>"; 
    return $out;
}

function arrJS($name, $value) {
    $out = "";
    $out .= "<script>"; 
    
    $out .= "var " . $name . " = " . $value . ";";
    
    $out .= "</script>"; 
    return $out;

}

?>
