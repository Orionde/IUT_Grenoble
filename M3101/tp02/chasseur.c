#define _POSIX_SOURCE
/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>	/* pour exit() */
#include <errno.h>	/* pour errno and co */
#include <sys/types.h>  /* pour pid_t, open() et kill()*/
#include <sys/stat.h>   /* pour open() */
#include <fcntl.h>      /* pour open() */
#include <unistd.h>     /* pour write() et close()*/
#include <signal.h>     /* pour kill() */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{

  int desc;
  pid_t pid;

  desc = open("/tmp/vent",O_RDONLY);
  if (desc == -1) {perror("Echec open "); exit(errno); }

  read(desc,&pid,sizeof(pid_t));
  close(desc);

  printf("Je vise %d\n",(int)pid);
  sleep(5);

  printf("pan!\n");
  /* à compléter */

  return EXIT_SUCCESS;
}
