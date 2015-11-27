<?php
	class Music
	{
		public $_id;
		public $_author;
		public $_title;
		public $_cover;
		public $_mp3;
		public $_category;
	
		public function __construct($id, $author, $title, $cover, $mp3, $category)
		{
			$this->_id = $id;
			$this->_author = $author;
			$this->_title = $title;
			$this->_cover = $cover;
			$this->_mp3 = $mp3;
			$this->_category = $category;
		}

	
	}

	function loadMusicDB()
	{
		$handle = fopen("musicDB.txt","r");
		$musiques = array();
		$i = 0;
		if ($handle)
		{
			while (($buffer = fgets($handle, 4096)) !== false)
			{
				$buffer = rtrim($buffer);
				$tmp = explode("|", $buffer);
				//print_r($tmp);
				$mu = new Music($tmp[0], $tmp[1], $tmp[2], $tmp[3], $tmp[4], $tmp[5]);
				$musiques[$i] = $mu;
				$i++;
			}
		}
		//print_r($musiques);
		fclose($handle);
		return $musiques;
	}
	
	//$tmp = loadMusicDB();
	//var_dump($tmp);

?>
