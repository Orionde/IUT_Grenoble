/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>     /* pour printf() close() */
#include <unistd.h>    /* pour fork() pipe() */
#include <sys/types.h> /* pour pid_t */
#include <errno.h>     /* pour errno */
#include <stdlib.h>    /* pour exit() */

#define LONGUEUR_MESSAGE 30

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  int mon_tube[2];

  //attention à créer le tube avant fork()
  if (pipe(mon_tube)==-1)
    {perror("Echec création tube"); exit(errno);}

  pid_t p = fork();
  if (p==-1) {perror("Echec fork"); exit(errno);}

  if (p==0) //le fils lit depuis le tube
  {
    char message[LONGUEUR_MESSAGE]={"Que la force soit avec toi."};

    close(mon_tube[1]); // le fils n'écrit pas dans le tube

    ssize_t nb_lus = read(mon_tube[0],message,LONGUEUR_MESSAGE);
    if (nb_lus==-1) {perror("Echec read"); exit(errno);}

    printf("Mon père m'a écrit : %s \n",message);

  }
  else //le père écrit dans le tube
  {
    char message[LONGUEUR_MESSAGE]={"Luke, je suis ton père."};

    close(mon_tube[0]); // le père ne lit pas depuis le tube

    ssize_t nb_ecrits = write(mon_tube[1],message,LONGUEUR_MESSAGE);
    if (nb_ecrits==-1) {perror("Echec write"); exit(errno);}
  }

  return EXIT_SUCCESS;
}
