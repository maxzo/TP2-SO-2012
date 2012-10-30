#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char* argv[])
{
	if (argc == 3 && !strcmp(argv[1], "-rc"))
	{
		int fd_entrada = open("pasajeros.txt", O_RDONLY);
		int fd_salida = open(argv[2], O_CREAT + O_WRONLY, 0777);
		int tuberia[2];
		
		pipe(tuberia);
		
		if (fork())
		{
			if (fork())
			{
				char *argumentos[] = { (char *) 0 };
				
				close(0);
				dup(fd_entrada);
				
				close(tuberia[0]);
				close(1);
				dup(tuberia[1]);
						
				execve("./reservas", argumentos, NULL);
			}
			else
			{
				char *argumentos[] = { (char *) 0 };
				
				close(tuberia[1]);
				close(0);
				dup(tuberia[0]);
				
				close(1);
				dup(fd_salida);
						
				execve("./checkin", argumentos, NULL);
			}
		}
	}
}
