#include <stdio.h>

void main(int argc, char* argv[])
{
	int i, j;

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
					for (j = 0; j < argc; j++)
					{
						printf("%s ", argv[j]);
					}
					printf("\n");
					break;
			}
			i++;
		}
	}
}
