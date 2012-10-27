#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char* argv[], char* envp[])
{       
	printf("Id proceso que invoca: %d\n", getpid());
	
	char* comando = "./factorial";
	int esnum = 1;
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (!isdigit(argv[1][i++]))
			{
				esnum = 0;
				break;
			}
		}
	}
	if (fork() == 0)
	{
		if (argc != 2 || !esnum || execve(comando, argv, envp) == -1)
		{
			printf("Error. Usar %s [número]\n", argv[0]);
			printf("Id de Prg-Factorial: %d\n", getpid());
		}
	}
}
