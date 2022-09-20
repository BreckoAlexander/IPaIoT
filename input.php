<?php
    $myfile = fopen("sens.txt", "w") or die("Unable to open file!");
    $input_1 = $_GET["a"];
    $input_2 = $_GET["b"];
    fwrite($myfile, $input_1);
    fwrite($myfile, $input_2);
    fclose($myfile);


    $myfile = fopen("sens.txt", "r") or die("Unable to open file!");
    echo fread($myfile,filesize("webdictionary.txt"));
    fclose($myfile);
?>
