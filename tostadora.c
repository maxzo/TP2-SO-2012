#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void tostarBlanco(int sig);
void tostarNegro(int sig);

int tostadas = 0;

int main()
{
	signal(SIGUSR1, &tostarBlanco);
	signal(SIGUSR2, &tostarNegro);
		
	while (1)
	{
		pause();
	}
	
	return 0;
}

void tostarBlanco(int sig)
{
	printf("Deseo tostadas de pan blanco.\nTostadas de pan blanco. (%d)\n", ++tostadas);
	//sleep(2);
	printf("Tostadas listas.\nTostadora libre, esperando pan.\n");
}

void tostarNegro(int sig)
{
	printf("Deseo tostadas de pan negro.\nTostadas de pan negro. (%d)\n", ++tostadas);
	//sleep(1);
	printf("Tostadas listas.\nTostadora libre, esperando pan.\n");
}
