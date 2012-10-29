#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void tostarBlanco(int sig, siginfo_t *siginfo, void *contexto);
void tostarNegro(int sig, siginfo_t *siginfo, void *contexto);

int tostadas = 0;
//
int main()
{
	struct sigaction accionB, accionN;
	
	accionB.sa_sigaction = &tostarBlanco;
	accionN.sa_sigaction = &tostarNegro;
	accionB.sa_flags = SA_SIGINFO;
	accionN.sa_flags = SA_SIGINFO;
	
	sigaction(SIGUSR1, &accionB, NULL);
	sigaction(SIGUSR2, &accionN, NULL);
		
	while (1) pause();
	
	return 0;
}

void tostarBlanco(int sig, siginfo_t *siginfo, void *contexto)
{
	printf("Deseo tostadas de pan blanco.\nTostadas de pan blanco. (%d)\n", ++tostadas);
	sleep(2);
	printf("Tostadas listas.\nTostadora libre, esperando pan.\n");
	kill(siginfo->si_pid, SIGUSR1);
}

void tostarNegro(int sig, siginfo_t *siginfo, void *contexto)
{
	printf("Deseo tostadas de pan negro.\nTostadas de pan negro. (%d)\n", ++tostadas);
	sleep(1);
	printf("Tostadas listas.\nTostadora libre, esperando pan.\n");
	kill(siginfo->si_pid, SIGUSR1);
}
