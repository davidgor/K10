<?php
	echo '<main>
		<form action="/">
		<button type="submit" class="button" style="vertical-align:middle"><span>Terug </span></button><br></br>
		</form>';
	
		$i=0;
		$dirname = "afb/";
		$images = glob($dirname."*.JPG");
		foreach($images as $image) {
		echo ' <a href="'.$image.'"><img width="33%" src="'.$image.'" /></a> ';
		$i=$i+1;
		if($i%3==0)
			echo '<br /><br />';
		}
		
	echo '</main>';
?>
