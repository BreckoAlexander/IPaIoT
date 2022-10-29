<?php

$sn1 = $_GET["a"];
$sn2 = $_GET["b"];

$file1 = fopen("sensors.txt","w") or die("Unable to open file!");
$text1 = "a=" . $sn1 . " b=" . $sn2;

fwrite($file1, $text1);
fclose($file1);


$file2 = fopen("actuator.txt","w");
fwrite($file2, "Hodnoty z akcneho clena");
fclose($file2);

$file3 = fopen("actuator.txt","r");
$text2 = fread($file2,filesize("actuator.txt"));
echo $text2;
fclose($file3);

?>