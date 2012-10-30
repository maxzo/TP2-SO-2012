#include <stdio.h>
#include <unistd.h>

#define ID_VUELO "AR234"

void main()
{
	char buffer[1];
	
	while (read(0, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
		{
			printf("_%s\n", ID_VUELO);
		}
		else
		{
			printf("%c", buffer[0]);
		}
	}
}
