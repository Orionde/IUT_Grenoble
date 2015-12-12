/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	// pour printf() and co
#include <stdlib.h>	// pour exit()
#include <errno.h>	// pour errno and co
#include <unistd.h>	// pour fork()
#include <sys/types.h>  // pour pid_t
#include <sys/wait.h>   // pour waitpid()

#define NB_FILS 2
#define NB_MAX_ARGS 5

/*--------------------------------------------------------------------------
 * Variables globales
 * -----------------------------------------------------------------------*/
static pid_t pids[NB_FILS];
/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  char* tab_cmds[NB_FILS][NB_MAX_ARGS] = {{"march_hare",NULL},
                                          {"ls","-l","-a",NULL}};
  printf("Exécutons les commandes :");
  for (int c=0; c<NB_FILS; c++)
    printf(" %s",tab_cmds[c][0]);
  printf("\n");


  int res_e;

  for (int c=0; c<NB_FILS; c++)
  {
    pids[c]=fork();
    if (pids[c]==-1) {perror("Echec fork "); exit(errno); }

    if (pids[c]==0) // fils
    {
      res_e=execvp(tab_cmds[c][0],tab_cmds[c]);
      if (res_e==-1) {perror("Echec execvp "); exit(errno); }
    }
  }

  printf("\nFils récupérés\n");

  return EXIT_SUCCESS;
}
