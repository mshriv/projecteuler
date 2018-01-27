#include<stdio.h>


int sumdivisor(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n%i == 0)
		{
			sum += i;
		}
	}

	return sum;
}

void p21()
{
	int sum = 0;
	int done[10000] = { 0 };
	for (int i = 1; i < 10000; i++)
	{
		if (done[i] == 1)
			continue;
		int a = sumdivisor(i);
		if ((a != i) && (sumdivisor(a) == i))
		{
			sum += (a + i);
			done[a] = 1;
			done[i] = 1;
		}
	}
	printf("%d", sum);
	while (1);
}