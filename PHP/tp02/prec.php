<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> Tables de multiplications </title>
	</head>
	<body>
		<?php
			$replace = array(
				'PHP' => 'Hypertext PreProcessor',
				'HTML' => 'HyperText Markeup Language',
				'XML' => 'eXtended Markeup Language',
				'CSS' => 'Cascading Style Sheets');
			
			function abbr($code)
			{
				global $replace ;
				echo '<abbr title="';
				echo $replace[$code];
				echo '">';
				echo $code;
			}

			function abbrAll()
			{
				global $replace;
			
			?>
			<table border = "1">
			<?php
				print("<th>Abréviation</th>");
				print("<th>Résult</th>");
				foreach($replace as $key => $value)
				{
					print("<tr>\n");
						print("<td>");
							echo $key;
						print("</td>\n");
						
						print("<td>");
							echo $value;
						print("</td>\n");
					print("</tr>\n");
				}
			?>
			</table>
			<?php
			}

		?>
		<p>Le langage <?php abbr('PHP');?> produit généralement
		du <?php abbr('HTML');?> mais peu produire aussi
		du <?php abbr('XML');?> ou même du <?php abbr('CSS');?>
		<?php abbrAll() ?>
		</p>
	</body>
</html>
