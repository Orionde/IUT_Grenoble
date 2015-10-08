<!DOCTYPE htm>
<?php
	foreach($_GET as $value)
	{
		
	}
?>

<html>
<head>
		<meta charset="utf-8" />
		<title> Jukebox </title>
	</head>
	<body>
		<form>
			<fieldset>
			<legend>Conversion</legend>
			<p>
				Entrez un nombre à convertir :
				<input type="number" value="in"autofocus>
				Celsius égal <input type="number" value="out" readonly> Farenheit
				action: <input type="submit" value="Convertir" />
			</p>
			</fieldset>
		</form>
	</body>
</html>
