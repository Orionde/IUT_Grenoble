<?php
class MusicDAO
{
	private $db;
	public function __construct($path)
	{
		try {
			$this->db = new PDO('sqlite:data/music.db');
		}
		catch (PDOException $e){ 
			die("erreur de connexion:".$e->getMessage()); 
		} 
	}
	public function getID($id){

		$sql = "SELECT * FROM music WHERE id ='$id'";
		$sth = $this->db->query($sql);
		$result = $sth->fetchAll(PDO::FETCH_CLASS,"Music");
		var_dump($result);
		return $result; 
	}
}

function loadMusicDB(){
	$f = fopen("musicDB.txt","r");
	$table = array();
	for($i=0;$i<554;$i++){

		$l = fgets($f);
		$l = rtrim($l);
		$array = explode ("|", $l);
		$mu = new Music;
		$mu->id=$array[0];
		$mu->author=$array[1];
		$mu->title=$array[2];
		$mu->cover=$array[3];
		$mu->mp3=$array[4];
		$mu->category=$array[5];
		$table[$array[0]]=$mu;
	}
	return $table;
}

$jukebox = new MusicDAO();
$jukebox->getID((int)1);
?>
