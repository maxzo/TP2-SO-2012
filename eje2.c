#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int valor;

void nodo1();
void nodo1_1();
void nodo1_2();
void nodo2();

void main(int argc, char* argv[])
{
	valor = atoi(argv[1]);
	
	printf("NODO R - VALOR = %d\nID PROCESO PRINCIPAL: %d\n", valor, getpid());
	
	int pid = fork();

	if (pid == 0)
	{
		nodo1();
	}
	else
	{
		wait(NULL);
		pid = fork();
		if (pid == 0)
		{
			nodo2();
		}
		else
		{
			wait(NULL);
		}
	}
}

void nodo1()
{
	valor += 100;
	
	printf("\nNODO 1 - VALOR = %d\nID NODO 1: %d - ID PADRE NODO 1 (NODO R): %d\n", valor, getpid(), getppid());
	
	int pidN1 = fork();

	if (pidN1 == 0)
	{
		nodo1_1();
	}
	else
	{
		wait(NULL);
		pidN1 = fork();
		if (pidN1 == 0)
		{
			nodo1_2();
		}
		else
		{
			wait(NULL);
		}
	}
}

void nodo1_1()
{
	printf("\nNODO 1.1 - VALOR = %d\nID NODO 1.1: %d - ID padre NODO 1.1 (NODO 1): %d\n", valor * 2, getpid(), getppid());
}

void nodo1_2()
{
	printf("\nNODO 1.2 - VALOR = %d\nID NODO 1.2: %d - ID padre NODO 1.2 (NODO 1): %d\n", valor / 2, getpid(), getppid());
}

void nodo2()
{
	printf("\nNODO 2 - VALOR = %d\nID NODO 2: %d - ID padre NODO 2 (NODO R): %d\n", valor - 100, getpid(), getppid());
}
