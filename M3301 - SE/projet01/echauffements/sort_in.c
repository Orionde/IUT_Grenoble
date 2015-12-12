/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/

#include <stdio.h>     /* pour fopen() */
#include <unistd.h>    /* pour dup2() execvp() */
#include <errno.h>     /* pour errno */
#include <stdlib.h>    /* pour exit() */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/

int main(void)
{
	char* arg[]={"sort",NULL}; 
	pid_t res = fork();
	if (res==-1)
	{
		perror("Echec fork ");
		exit(errno);
	}


	FILE* fin=fopen("fichier.txt","r");
	FILE* fout = fopen("/dev/pts/1", "w");
	if (fin==NULL) {perror("Echec fopen r"); exit(errno);}
	if (fout==NULL) {perror("Echec fopen r"); exit(errno);}

	if(dup2(fileno(fin), STDIN_FILENO) == -1){
		perror("Echec execvp "); exit(errno);}

	close(fileno(fin)); // on ne se sert désormais que de stdout
	//           pour écrire dans le fichier
	//dup2(STDOUT_FILENO, fileno(fout));
	dup2(fileno(fout), STDOUT_FILENO);
	close(fileno(fout));
	if(res == 0)
	{
		int res1=execvp(arg[0],arg);
		if (res1==-1) {perror("Echec execvp "); exit(errno);}
	}


	/* si l'on arrive là c'est qu'il y a eu un soucis */
	return EXIT_FAILURE;
}
