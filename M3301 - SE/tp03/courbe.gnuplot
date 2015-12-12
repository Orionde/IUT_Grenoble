set title "Programme tableau1d-auto"

set xlabel "Taille du tableau"
set logscale x
set ylabel "Nb d'opérations par seconde"
plot [][0:] "resu.data" using 1:2 title "resu.data" with lines

pause -1  "Appuyer sur Entrée ..."
