<?php

$sn1 = $_GET["a"];
$sn2 = $_GET["b"];

$file1 = fopen("sensors.txt","w") or die("Unable to open file!");
$text1 = "a=" . $sn1 . " b=" . $sn2;

fwrite($file1, $text1);
fclose($file1);



?>