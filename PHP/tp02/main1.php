<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> Jukebox </title>
	</head>
	<body>
		<?php
			require_once('music.php');
			$tmp = loadMusicDB();
			//var_dump($tmp);
			
			if(isset($_GET["music"]))
			{
				$music = $_GET["music"];
				?>
					<img src = "http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/img/<?php echo $tmp[$music]->_cover ?>" width=200 height=200></a>
					<br/>
					<audio src= "http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/mp3/<?php echo $tmp[$music]->_mp3?>" controls="" autoplay=""></audio>
				<?php
			}
			else
			{
				for($i = 1 ; $i < 11 ; $i++)
				{
					?>
						<a href="main1.php?music=<?php echo (int)$tmp[$i]->_id ?>"/>
						<img src = "http://www-info.iut2.upmf-grenoble.fr/intranet/enseignements/M3104/TP02/data/img/<?php echo $tmp[$i]->_cover ?>" width=200 height=200></a>
					<?php
				}
			}
		?>
	</body>
</html>
