<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title> cacul</title>
	</head>

	<body>
		<?php
			$a = $_GET["a"];
			$b = $_GET["b"];
			$var = $_GET["var"];
			$res = 0;

			echo $a;
			switch ($var)
			{
				case "+":
					print(" + ");
					$res = $a + $b;
					break;
				case "-":
					print(" - ");
					$res = $a - $b;
					break;
				case "*":
					print(" * ");
					$res = $a * $b;
					break;
				case "/":
					print(" / ");
					$res = $a / $b;
					break;
			}
			echo $b;
			printf(" = %d",$res);
		?>
	</body>
</html>
