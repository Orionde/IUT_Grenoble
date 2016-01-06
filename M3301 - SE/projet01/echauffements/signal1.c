/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	// pour printf() and co
#include <stdlib.h>	// pour exit()
#include <errno.h>	// pour errno and co
#include <unistd.h>	// pour fork()
#include <sys/types.h>  // pour pid_t
#include <sys/wait.h>   // pour waitpid()
#include <signal.h> //Pour sig

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/

int main(void)
{

	pid_t res_f,res_w;
	int res_e;
	char *arg[]={"./march_hare",NULL};
	struct sigaction sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;

	res_f=fork();

	if (res_f==-1) {perror("Echec fork"); exit(errno); }

	if (res_f==0) //Si on est dans l'environnement fils
	{
		sig.sa_handler = SIG_DFL; //remet l'action par défaut dans la structure
		sigaction(SIGINT, &sig, NULL); //Relet l'action par défaut

		res_e = execvp(arg[0],arg);//On exécuter l'action
		if (res_e==-1) {perror("Echec execvp"); exit(errno); }
	}
	else
	{
		sig.sa_handler=SIG_IGN;
		sigaction(SIGINT, &sig, NULL);
		res_w= waitpid(res_f, NULL, 0);

		if (res_w==-1) {perror("Echec wait"); exit(errno); }

		sig.sa_handler=SIG_DFL;
		sigaction(SIGINT, &sig, NULL);
		printf("Cela marche ! \n");
		pause();
	}

	return EXIT_SUCCESS;
}
