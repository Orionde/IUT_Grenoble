/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>	/* pour exit() */
#include <errno.h>	/* pour errno and co */
#include <unistd.h>	/* pour fork() */
#include <sys/types.h>  /* pour pid_t */
#include <sys/wait.h>   /* pour waitpid() */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  pid_t res_f,res_w;
  //char* arg[]={"ls","-l","-a",NULL};

  res_f=fork();
  if (res_f==-1) {perror("Echec fork "); exit(errno); }

  if (res_f==0)
  {
      /* --------- à compléter ----------- */

  }
  else
  {
    res_w=waitpid(res_f,NULL,0);
    if (res_w==-1) {perror("Echec wait "); exit(errno); }
  }

  return EXIT_SUCCESS;
}
