<?php

$sn1 = $_GET["a"];
$sn2 = $_GET["b"];

$file1 = fopen("sensors.txt","w") or die ("Subor neexistuje");
$text1 = "a=" . $sn1 . " b=" . $sn2;

fwrite($file1, $text1);
fclose($file1);

$file2 = fopen("actuator.txt","r") or die ("Subor neexistuje");
$text2 = fread($file2,filesize("actuator.txt"));
echo $text2;
fclose($file2);

?>