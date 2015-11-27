<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> HDJKFHSJKLFHHJKLFHKLESSS</title>
		<link rel="stylesheet" type="text/css" href="clock/styleTable.css">
	</head>
	<body>
		<table border = 1>
			<?php
				$location = array("Europe/Paris", "Asia/Singapore");
				?><tbody><?php
				foreach($location as $value)
				{
			?><tr><th><?php
					echo $value;
					?></th></td><td><?php
						date_default_timezone_set($value);
						echo date("H:i:s d/m/Y\n");
					?></td><?php
					?></tr><?php
				}
				?></tbody><?php
			?>
		</table>
	</body>
</html>
