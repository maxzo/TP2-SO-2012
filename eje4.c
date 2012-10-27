#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char* argv[])
{
	if (argc == 3)
	{
		if (chdir(argv[2]) == -1)
		{
			printf("Error. Directorio inválido.\n");
			exit(0);
		}
	}
	
	if (argv[1][0] == '-')
	{
		switch (argv[1][1])
		{
			case 'l':
				printf("\nListado del directorio %s:\n\n", argv[2]);
				system("ls -l --format=single-column");
				printf("\n");
				break;
			case 't':
				printf("\nTipos de archivos del directorio %s:\n\n", argv[2]);
				system("ls -F --classify > temp.txt");
				system("sed -i '/temp.txt/d' temp.txt");
				system("sed -i 's/$/ -- Regular/g' temp.txt");
				system("sed -i 's/* -- Regular$/ -- Ejecutable/g' temp.txt");
				system("sed -i 's/\\/ -- Regular$/ -- Directorio/g' temp.txt");
				system("sed -i 's/@ -- Regular$/ -- Enlace Simbólico/g' temp.txt");
				system("sed -i 's/| -- Regular$/ -- FIFO/g' temp.txt");
				system("sed -i 's/= -- Regular$/ -- Directorio/g' temp.txt");
				system("cat temp.txt");
				system("rm temp.txt");
				printf("\n");
				break;
			case 'i':
				printf("\nNúmero de inodo de archivos del directorio %s:\n\n", argv[2]);
				system("ls -i | awk '{ print $2, \"-\", $1 }'");
				printf("\n");
				break;
		}
	}
}
