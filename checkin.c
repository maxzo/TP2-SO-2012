#include <stdio.h>

void main()
{
	char buffer[1];
	int asiento = 1;
	
	while (read(0, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
		{
			printf("_%d\n", asiento++);
		}
		else
		{
			printf("%c", buffer[0]);
		}
	}
}
