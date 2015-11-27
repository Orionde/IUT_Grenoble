<!DOCTYPE html>
<?php 
	require_once('Music.php');
	$tmp=loadMusicDB();
?>
<html>
	<head>
		<meta charset="utf-8" />
		<link rel="stylesheet" href="styleTable.css" type="text/css" />
		<title> Musique</title>
	</head>
	
	<body>
		<h1> Jukebox</h1>
		
		<?php
		if(isset($_GET["firstID"]))
			$p = $_GET["firstID"];
		else
			$p = 1;
		
		if(!isset($_GET["music"])){
		
		?>
			<a href="main.php?firstID=<?php echo $p-5;?>">
			<?php	
			?>
				<img src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/sujet/img/Actions-arrow-left-icon.png">
				</a>
				<?php echo $p; ?>
				<a href="main.php?firstID=<?php echo $p+5;?>">
				<img src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/sujet/img/Actions-arrow-right-icon.png">
				</a></br>
			<?php
			for($i=$p;$i<=($p+4);$i++)
			{
			?>
				<a href="main.php?music=<?php echo (int)$tmp[$i]->id;?>">
				<img src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/img/<?php echo $tmp[$i]->cover?>", width=200 height=200></a>
			<?php
			}
		?>
		<?php
		}
		else{
			$a=$_GET["music"];
			?>
				
				<img src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/img/<?php echo $tmp[$a]->cover?>", width=200 height=200></br>
				<audio src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/mp3/<?php echo $tmp[$a]->mp3 ?> " controls="" autoplay="" width=200></audio></br>
				<a href="main.php?firstID=<?php echo $_GET["music"]; ?>">
				<img src="http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/sujet/img/Actions-arrow-top-icon.png">
				</a>
				
			<?php	
		}	
		?>
		
	</body>
</html>
