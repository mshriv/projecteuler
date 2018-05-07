#include <vector>
#include <stdio.h>
using namespace std;

#define MAXLIMIT 28123

void p23()
{
	vector <int> nonab;
	int sum = 1; // 1 would always be a divisor;
	for (int i = 2; i < MAXLIMIT; i++)
	{
		int root = (int)floor(sqrt(i));
		for (int j = 2; j <= root; j++)
		{
			if (i%j == 0)
			{
				sum += j;
				if (j != (i/j))
					sum += (i / j);
			}
		}

		if (sum > i)
		{
			nonab.push_back(i);
		}
		sum = 1;
	}
	sum = 0;
	int arr[MAXLIMIT + 1] = { 0 };
	for (int i = 0; i < nonab.size(); i++)
	{
		for (int j = 0; (j < nonab.size()) && ((nonab[i] + nonab[j]) <= MAXLIMIT)  ; j++)
		{
			if (arr[nonab[i] + nonab[j]] != 1)
			{
				sum += (nonab[i] + nonab[j]);
				arr[nonab[i] + nonab[j]] = 1;
			}
		}
	}

	sum = (MAXLIMIT*(MAXLIMIT + 1) / 2) - sum;

	printf("%d\n", sum);
}