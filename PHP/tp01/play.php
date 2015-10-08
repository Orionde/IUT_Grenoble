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
				switch($_GET["music"])
				{
					case "JUSTICE/D.A.N.C.E"
						?>
						<img src = "jukebox/Justice/D.A.N.C.E.jpeg" width=200 height=200>
						<br/>
						<audio src="jukebox/Justice/D.A.N.C.E.mp3"controls="" autoplay="">
						</audio>
						<?php
						break;
					case "Kesha/TikTok"
					?>
						<img src = "jukebox/Ke$ha//Tiktok.jpeg" width=200 height=200>
						<br />
						<audio src='jukebox/Ke$ha/Tiktok.mp3' controls="" autoplay="">
						</audio>
					<?php
						break;
					case "Black/Feeling"
					?>
						<img src = "jukebox/The Black Eyed Peas/I Gotta Feeling.jpeg" width=200 height=200>
						<br />
						<audio src="jukebox/The Black Eyed Peas/I Gotta Feeling.mp3" controls="" autoplay="">
						</audio>
					<?php
				}
			}
			else
			{?>
			<a href="http://www-etu-info.iut2.upmf-grenoble.fr/~congiohj/PHP/tp01/play.php?music=JUSTICE/D.A.N.C.E">
			<img src = "jukebox/Justice/D.A.N.C.E.jpeg" width=200 height=200></a>
			<a href="http://www-etu-info.iut2.upmf-grenoble.fr/~congiohj/PHP/tp01/play.php?music=Kesha/TikTok">
			<img src = "jukebox/Ke$ha/Tiktok.jpeg" width=200 height=200></a>
			<a href="http://www-etu-info.iut2.upmf-grenoble.fr/~congiohj/PHP/tp01/play.php?music=Black/Feeling">
			<img src = "jukebox/The Black Eyed Peas/I Gotta Feeling.jpeg" width=200 height=200></a>
			<?php
			}
		?>

	</body>
</html>
