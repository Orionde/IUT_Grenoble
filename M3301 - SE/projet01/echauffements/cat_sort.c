/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>     /* pour fopen() printf() close() */
#include <unistd.h>    /* pour dup2() fork() */
#include <sys/types.h> /* pour pid_t */
#include <sys/wait.h>  /* pour waitpid() */
#include <errno.h>     /* pour errno */
#include <stdlib.h>    /* pour exit() */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
	pid_t fils[2];
	char* arg0[]={"cat",NULL};
	char* arg1[]={"sort",NULL};

	// création du tube
	/*TODO à compléter TODO*/
	int mon_tube[2];

	if (pipe(mon_tube)==-1)
	{perror("Echec création tube"); exit(errno);}

	fils[0] = fork();
	if (fils[0]==-1) {perror("Echec fork"); exit(errno);}

	if (fils[0]==0) //le premier fils lit depuis stdin et écrit dans le tube
	{
		/*TODO à compléter TODO*/
    	close(mon_tube[1]); // le fils n'écrit pas dans le tube
		dup2(mon_tube[0],STDIN_FILENO);
		close(mon_tube[0]);
		int res=execvp(arg0[0],arg0);
		if (res==-1) {perror("Echec execvp "); exit(errno);}
	}
	else
	{
		fils[1] = fork();
		if (fils[1]==-1) {perror("Echec fork"); exit(errno);}

		if (fils[1]==0) //le deuxième fils lit depuis le tube et écrit dans stdout
		{
			/*TODO à compléter TODO*/
			close(mon_tube[0]);
			dup2(STDOUT_FILENO,mon_tube[1]);
			close(mon_tube[1]);
			int res=execvp(arg1[0],arg1);
			if (res==-1) {perror("Echec execvp "); exit(errno);}
		}
	}

	// le père ne lit ni n'écrit dans le tube
	/*TODO à compléter TODO*/
	close(mon_tube[0]);
	close(mon_tube[1]);
	//pendant ce temps le père les attend
	for (int i=0; i<2; i++)
		waitpid(fils[i],NULL,0);

	return EXIT_SUCCESS;
}
