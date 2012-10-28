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
		
	while (tostadas != 30);
	
	return 0;
}

void tostarBlanco(int sig)
{
	printf("Blanco\n");
	tostadas++;
}

void tostarNegro(int sig)
{
	printf("Negro\n");
	tostadas++;
}
