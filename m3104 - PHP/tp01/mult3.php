#!/usr/bin/php
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> Tables de multiplications </title>
	</head>

<body>
	<table border="1" width="400">
		<?php
			$colones = 10;
			$lignes = 10;
		?>

		<thead>
			<th>
				<?php
					for($i = 1 ; $i <= $lignes ; $i++)
					{
						?><td><?php
						echo $i;
						?></td> <?php
					}
				?>
			</th>
		</thead>

		<tbody>
			<?php
				for($i = 1 ; $i <= $lignes ;  $i++)
				{
					?> <tr> <?php
					for($j = 1 ; $j <= $colones ; $j++)
					{
						if ($j==1)
						{
						?><td><?php
						echo $i;
						?></td><?php
						}
						?><td><?php
						echo $i * $j;
						?></td><?php
					}
					?> </tr> <?php
					$j = 1;
				}
			?>
		</tbody>
	</table>
</body>
</html>
