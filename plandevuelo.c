/* ejecuta los programas checkin y reservas y guarda el archivo plandevuelo.txt */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define RD_WR 0666

void main(int argc, char* argv[])
{
	int fd;
	fd = creat( "plandevuelo.txt", RD_WR);
}

