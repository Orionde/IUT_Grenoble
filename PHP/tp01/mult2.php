#!/usr/bin/php
<?php
	$i = 0;
	$var = 0;
	print("Entrez valeur pour table : ");
	fscanf(STDIN, "%d\n", $var);
	while($i <= 10)
	{
		printf("$var * %d = %d\n", $i, ($i * $var));
		$i++;
	}
?>
