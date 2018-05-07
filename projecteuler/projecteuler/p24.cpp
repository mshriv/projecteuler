#include <stdio.h>

#define NUMDIGITS 10
#define NTH 1000000

int fact(int i)
{
	int ret = 1;
	for (int j = 2; j <= i; j++)
	{
		ret *= j;
	}

	return ret;
}
void p24()
{
	int limit = NTH;
	int numdig[NUMDIGITS] = { NUMDIGITS };

	for (int i = 0; i < NUMDIGITS; i++)
		numdig[i] = NUMDIGITS;
	//numdig[0] = 0;
	for (int i = NUMDIGITS; (i > 1); i--)
	{
		int numperm = fact(i - 1);
		numdig[i - 1] = limit / numperm;
		limit = limit - numperm*numdig[i - 1]; 
		if (limit == 0)
		{
			numdig[i - 1]--;
			break;
		}
	}
	//This is just printing the index of number. So 0 means smallest of remaining
	// 1 means second smallest of remaining and so on. However, there is a special
	// number equal "NUMDIGIT". It means maximum of the remaining.

	for (int i = NUMDIGITS; i > 0; i--)
	{
		printf("%d ", numdig[i-1]);
	}

	while (1);
}