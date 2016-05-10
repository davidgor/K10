<?php
	echo '<main>
                <form action="/">
                <button type="submit" class="button" style="vertical-align:middle"><span>Terug </span></button><br></br>
                </form>';
	$time=time();
	echo shell_exec('raspistill -o /var/www/afb/'.$time.'.JPG');
	sleep ( 3 );
	echo '<img src="/afb/'.$time.'.JPG" alt="pic" style="width:100%;">';
	echo '</main>'
?>
