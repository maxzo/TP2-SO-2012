#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int valor;

void nodo1();
/*void nodo1_1();
void nodo1_2();*/
void nodo2();

void main(int argc, char* argv[])
{
	valor = atoi(argv[1]);
	int pid = fork();

	if (pid == 0)
	{
		nodo1();
		//nodo2();
	}
	else
	{
		printf("NODO R - VALOR = %d\nID PROCESO PRINCIPAL: %d\n", valor, pid);
	}
}

void nodo1()
{
	int pid = fork();
	int ppid = getppid();

	if (pid == 0)
	{
		
	}
	else
	{
		printf("\nNODO 1 - VALOR = %d\nID NODO 1: %d - ID PADRE NODO 1 (NODO R): %d\n", valor + 100, pid, ppid);
	}
}

void nodo2()
{
	printf("\nNodo 1 - PID: %d\n", getpid());
}
