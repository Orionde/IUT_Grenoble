#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // vérification de la présence des paramètres sur la ligne de commande
  if (argc-1 != 2)
  {
     printf("Usage : %s taille_tableau nb_repetitions\n", argv[0]);
     exit(1);
  }

  // récupération des paramètres de la ligne de commande
  unsigned int N=(unsigned int)atoi(argv[1]);
  unsigned int nb_repetitions=(unsigned int)atoi(argv[2]);

  // allocation d'un tableau de taille N*N
  int* tableau=malloc(N*N*sizeof(int));		  // ne marche pas en cas de dépassement
  if (tableau==0)
  {
    perror("échec malloc");
    exit(EXIT_FAILURE);
  }

  // remplissage du tableau
  for (unsigned int l=0; l<N; l++)			  // pour chaque ligne
    for (unsigned int c=0; c<N; c++)			  // pour chaque colonne
       tableau[l*N+c] = (int)(l+c);			  // rand() est trop long

  int somme=0;					  // peu importe si on a un débordement
  // relectures du tableau
  for (unsigned int i=0; i<nb_repetitions; i++)
    for (unsigned int l=0; l<N; l++)			  // pour chaque ligne
      for (unsigned int c=0; c<N; c++)			  // pour chaque colonne
        somme += tableau[l*N+c];
  printf("somme : %d\n", somme);		  // affichage indispensable

  free(tableau);

  return 0;
}
