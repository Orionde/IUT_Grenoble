<?PHP
if(isset($_GET['prenom']))
{
	echo "<html> <head> <meta charset=\"UTF-8\"> </head><body>";
	echo "<h1>Bienvenue ";
	echo $_GET['prenom'];
	echo "</h1>";
	echo '<ul><li><a href="choix1.php">choix1</a></li>';
	echo '<li><a href="choix2.php">choix2</a></li>';
	echo '<li><a href="choix3.php">choix3</a></li></ul>';
	echo "</h1></body></html>";
	setcookie("CookieNom", $_GET['prenom'], time()+3600);
}
else if(isset($_COOKIE['CookieNom']))
{
	echo "<html> <head> <meta charset=\"UTF-8\"> </head><body>";
	echo "<h1>Bienvenue ";
	echo $_COOKIE['CookieNom'];
	echo "</h1>";
	echo '<ul><li><a href="choix1.php">choix1</a></li>';
	echo '<li><a href="choix2.php">choix2</a></li>';
	echo '<li><a href="choix3.php">choix3</a></li></ul>';
	echo "</h1></body></html>";
}
else
{
	header('Location: formulaire.php');
}
?>
