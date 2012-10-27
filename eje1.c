#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char* argv[])
{
	int fd, i, j;
	char* nombre_archivo;

	if (argc == 1)
	{
		printf("Uso: %s [-cl] [-s nombre_archivo]\n", argv[0]);
	}
	else if (argv[1][0] == '-')
	{
		i = 1;
		while (argv[1][i] != '\0')
		{
			switch (argv[1][i])
			{
				case 'c':
					printf("Cantidad de argumentos: %d\n", argc);
					break;
				case 'l':
					
					for (j = 0; j < argc; j++)
					{
						printf("Argumento: -%d %s\n", j, argv[j]);
					}
					break;
				case 's':
					nombre_archivo = argv[2];
					fd = open(nombre_archivo, O_CREAT + O_RDWR, 0777);
					close(1);
					dup(fd);
					for (j = 0; j < argc; j++)
					{
						printf("%s ", argv[j]);
					}
					break;
			}
			i++;
		}
	}
}
