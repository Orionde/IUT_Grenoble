#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

//#define MILLION 1000000.0

int main(int argc, char* argv[])
{
	struct timeval t1, t2;
	// on prend la mesure du temps avant le fork()
	// pour avoir des mesures plus stables
	// à compléter : 1ère mesure du temps dans t1
	gettimeofday(&t1, NULL);
	pid_t res;

	// à compléter : création d'un processus fils et test d'échec
	res=fork();
	
	if (res == -1) {perror("Echec fork "); exit(errno); }
	else if (res == 0)
	{ // on est dans le fils
		// à compléter : vérification du nombre d'arguments et exécution du fils
		if(argc > 1)
		{
			execvp(argv[1], argv+1);
		}
	}
	else
	{ // on est dans le père
		// à compléter : attente de la fin du fils
  		waitpid(res, NULL, 0 );
		// à compléter : 2ème mesure du temps dans t2
		gettimeofday(&t2, NULL);
		printf("fin du fils\n");

		// à compléter : calcul du temps
		double temps_ecoule_sec = t2.tv_sec - t1.tv_sec;
		double temps_ecoule_Msec = t2.tv_usec - t1.tv_usec;
		printf("temps écoulé : %lf secondes et %lf micro secondes\n", temps_ecoule_sec, temps_ecoule_Msec);
	}

	return EXIT_SUCCESS;
}
