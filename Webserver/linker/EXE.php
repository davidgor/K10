<?php
	$myfile = fopen("EXE.txt", "a+") or die("Unable to open file!");
	$pre    = $_GET['data']."\n";
	fwrite($myfile, $pre);
	echo "OK";
	echo $_GET['data'];
?>
