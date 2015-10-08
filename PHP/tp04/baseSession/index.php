<?PHP
session_start();
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
	$_SESSION['prenom'] = $_GET['prenom'];
}
else if(isset($_SESSION['prenom']))
{
	echo "<html> <head> <meta charset=\"UTF-8\"> </head><body>";
	echo "<h1>Bienvenue ";
	echo $_SESSION['prenom'];
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
