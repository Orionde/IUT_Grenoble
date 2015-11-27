/*--------------------------------------------------------------------------
 * Programme à compléter pour expérimenter l'usage de fork
 * -----------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>	/* pour exit() */
#include <errno.h>	/* pour errno and co */
#include <unistd.h>	/* pour fork() */
#include <sys/types.h>  /* pour pid_t */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
	pid_t res;
	int g = 0;

	res=fork();
	if (res==-1) {perror("Echec fork "); exit(errno); }
	else if(res == 0)
		g++;
	else
	{
		res = fork();
		if(res == 0)
			g++;
	}
	printf("%d : je suis %d fils de %d, res = %d\n", g, getpid(), getppid(), (int)res);

	return 0;
}
