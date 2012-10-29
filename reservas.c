/* lee archivo pasajeros.txt y agrega id de vuelo al nombre de pasajero y codigo de reserva */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define RD_WR 0666

void main(int argc, char* argv[])
{
	int fd;
	int fw;
	int vuelo = system("sed 's/$/_AR234/' pasajeros.txt> temp.txt");
	/* char id_vuelo[6] = "_AR234"; */
	fd = open( "pasajeros.txt", O_RDWR | O_APPEND);
}
