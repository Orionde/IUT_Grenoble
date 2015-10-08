<?PHP
if (isset($_GET['prenom']))
{
	echo "<html> <head> <meta charset=\"UTF-8\"> </head><body>";
	echo "<h1>Bienvenue ";
	echo $_GET['prenom'];
	echo "</h1>";
	?>
	<ul><li><a href="choix1.php?prenom=<?php echo $_GET['prenom']?>">choix1</a></li>
	<li><a href="choix2.php?prenom=<?php echo $_GET['prenom']?>">choix2</a></li>
	<li><a href="choix3.php?prenom=<?php echo $_GET['prenom']?>">choix3</a></li></ul>
	</h1></body></html>
	<?php
}
else
{
	header('Location: formulaire.php');
}
?>
