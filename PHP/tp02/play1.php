<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> Jukebox </title>
	</head>
	<body>
		<?php
			if(isset($_GET["music"]) && isset($_GET["cover"]))
			{
				?>
					<a href= <?php echo $_GET["cover"]?> width=200 height=200/><br/>
					<audio src= "<?php echo $_GET["music"]?> controls="" autoplay=""></audio>
				<?php
			}
			else
			{
				echo "Pas de paramètres";
			}
		?>

	</body>
</html>
