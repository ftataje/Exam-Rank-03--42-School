#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main(void)
{
	char buffer [1000];
	int i;
	int j;
	j = 1; 
	while (j<100)
	{
		i = 0;
		while (i < 1000)
		{
			if (i % j == 0)
			{
				buffer[i] = '\n';
			}
			else
				buffer[i] = 'a';
			write(1, buffer, i);
			i++;
		}
		j++;
	}
	return(0);
}

