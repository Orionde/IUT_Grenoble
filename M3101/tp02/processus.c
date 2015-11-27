#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>
#include <errno.h>	/* pour errno and co */
#include <sys/types.h>
#include <sys/wait.h>

#include <sched.h>

static void fils(int numero)
{
  int res_e;
  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(1,&mask);
  if (numero==0)
  {
 	
    char* arg[]={"bin-gcc/grossesBoucles","-multi",NULL};
    res_e=execvp(arg[0],arg);
    if (res_e==-1) {perror("Echec execvp "); exit(errno); }
  }
  else
  {
    nice(-3);
    char* arg[]={"mplayer","/users/info/pub/s3/M3101/bbc.mp3",NULL};
    res_e=execvp(arg[0],arg);
    if (res_e==-1) {perror("Echec execvp "); exit(errno); }
  }

  exit(1);
}


int main(void)
{
  pid_t pid[2];	    // pids des fils

  for (int i=0; i<2; i++)
    if ((pid[i]=fork())==0) fils(i);

  for (int i=0;i<2;i++)
    waitpid(pid[i],NULL,0);

  return 0;
}
