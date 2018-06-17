#include <stdio.h>

#define NUM 1000

void p25()
{
	char *prev = new char[NUM];
	prev[0] = 1;
	char *curr = new char[NUM];
	curr[0] = 1;
	char *sum = new char[NUM];
	char *tmp = NULL;
	for (int i = 1; i < NUM; i++)
	{
		prev[i] = 0;
		curr[i] = 0;
		sum[i] = 0;
	}
	char carry = 0;
	int currlen = 1;
	unsigned long long index = 2;
	while (currlen < NUM)
	{

		for (int i = 0; i < currlen; i++)
		{
			sum[i] = (prev[i] + curr[i] + carry) % 10;
			carry = (prev[i] + curr[i] + carry) / 10;
			if ((carry != 0) && (i == currlen - 1))
			{
				currlen++;
			}
		}

		tmp = prev;
		prev = curr;
		curr = sum;
		sum = tmp;
		index++;
	}
	printf("%llu\n", index);

	delete[] prev;
	delete[] curr;
	delete[] sum;;

}