#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long FindLength(unsigned long long num, unsigned long long *length)
{
	
	if (num % 2 == 0)
	{
		if ((num/2 < 1000000) && length[num/2] != 0)
		{
			return length[num / 2] + 1;
		}
		else
		{
			return FindLength(num / 2, length) + 1;
		}
	}
	else
	{
		if (((3 * num + 1) < 1000000) && length[3 * num + 1] != 0)
		{
			return length[3 * num + 1] + 1;
		}
		else
			return FindLength(3 * num + 1, length) + 1;
	}
}

void p14()
{
	unsigned long long *length = new unsigned long long[1000000];
	memset(length, 0, sizeof(unsigned long long) * 1000000);
	length[1] = 1;
	unsigned long long max = 1;
	unsigned long long maxnum = 1;
	for (unsigned long long i = 2; i < 1000000; i++)
	{
		length[i] = FindLength(i, length);
		if (length[i] > max)
		{
			max = length[i];
			maxnum = i;
		}
		//printf("%llu\n",i );
	}
	printf("%llu %llu\n", max, maxnum);
	
	while (1);
}