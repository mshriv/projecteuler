#include <stdio.h>

void p9()
{
	for (size_t i = 1; i < 1000; i++)
	{
		for (size_t j = 1; j < 1000; j++)
		{
			if (1000 * (i + j) == (500000 + i*j))
			{
				printf("%u\n", i*j*(1000 -i -j));
				return;
			}
		}
	}

}