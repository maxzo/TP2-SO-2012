#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void funcion(int sig) { }
//
int main(int argc, char* argv[])
{
	signal(SIGUSR1, &funcion);
		
	int huesped = 1, i, j, pid = atoi(argv[1]);
	
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("Pedido de tostada de Pan Blanco. Huésped: %d\n", huesped++);
			kill(pid, SIGUSR1);
			pause();
		}
		printf("Pedido de tostada de Pan Negro. Huésped: %d\n", huesped++);
		kill(pid, SIGUSR2);
		pause();
	}
	
	return 0;
}
