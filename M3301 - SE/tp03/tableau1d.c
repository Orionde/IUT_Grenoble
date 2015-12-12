#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // vérification de la présence des paramètres sur la ligne de commande
  if (argc-1 != 2)
  {
     printf("Usage : %s taille_tableau_en_octets nb_repetitions\n", argv[0]);
     exit(1);
  }

  // récupération des paramètres de la ligne de commande
  unsigned long N=(unsigned long)(atol(argv[1]))/sizeof(int);
  int nb_repetitions=atoi(argv[2]);

  // allocation d'un tableau de taille N
  int* tableau=malloc(N*sizeof(int));
  if (tableau==0)
  {
    perror("échec malloc");
    exit(EXIT_FAILURE);
  }

  // remplissage du tableau
  for (unsigned long i=0; i<N; i++)
    tableau[i] = rand();

  int somme=0;					  // peu importe si on a un débordement
  // relectures du tableau
  for (int r=0; r<nb_repetitions; r++)
    // parcours du tableau
    for (unsigned long i=0; i<N; i++)
      somme += tableau[i];
  printf("somme : %d\n", somme);		  // affichage indispensable

  free(tableau);

  return 0;
}
