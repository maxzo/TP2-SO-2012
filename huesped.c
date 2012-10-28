#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//void alarma(int sig) { }

int main(int argc, char* argv[])
{
	int huesped = 1, i, j, pid = atoi(argv[1]);
	
	//signal(SIGALRM , &alarma);
	
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 4; j++)
		{
			kill(pid, SIGUSR1);
			printf("Pedido de tostada de Pan Blanco. Huésped: %d\n", huesped++);
			//pause();
		}
		kill(pid, SIGUSR2);
		printf("Pedido de tostada de Pan Negro. Huésped: %d\n", huesped++);
		//pause();
	}
	
	return 0;
}
