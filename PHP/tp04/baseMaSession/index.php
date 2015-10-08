<?PHP

function newSessionID()
{
	return rand();
}

function putSession($id, $name, $val)
{
	try
	{
		$this->_db = new PDO('sqlite:data/session.db');
	}
	catch(PDOException $e)
	{
		die("erreur de connexion :".$e->getMessage());
	}

	$inser = "INSERT 
}
?>
