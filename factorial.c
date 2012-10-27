#include <stdio.h>

void main(int argc, char* argv[], char* envp[])
{ 	
        int valor = atoi(argv[1]);
        
	if (valor > 0 && valor < 11)
	{
		printf("Factorial de %d = %d\n", valor, factorial(valor));
	}
	else
	{
		printf("Número fuera de rango: %d\n", valor);
	}
	printf("Id de Prg-Factorial: %d\n", getpid());
}

int factorial (int num)
{
	if (num < 2) return 1;
	else return num * factorial(num - 1);
}
