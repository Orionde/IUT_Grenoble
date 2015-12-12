#include <stdio.h>

int main(void)
{
#define N 1500000000					  // #define -> constante littérale qui n'occupe pas de registre

  // on calcule les N premiers termes d'une suite
  volatile long int suite=0;
  long int suite1,suite2;      // variables intermédiaires (ne pas toucher)
  for (volatile unsigned int i=0; i<N; i++)
  {
     suite1 = suite*3;
     suite2 = suite1+3;
     suite = suite2/3;
  }
  printf("suite : %ld \n", suite);		  // affichage indispensable

  return 0;
}
