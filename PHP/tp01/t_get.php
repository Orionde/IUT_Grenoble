<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> Variables</title>
		<link rel="stylesheet" type="text/css" href="clock/styleTable.css">
	</head>

	<body>
		<table border = "1">
			<?php
				print("<th>Nom de variable</th>");
				print("<th>Valeur</th>");
				foreach($_GET as $key => $value)
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

	</body>
</html>
