#include <stdio.h>

void p2()
{
	int prev1 = 2;
	int prev2 = 1;
	int sum = 2;
	while (prev2 + prev1 <= 4000000)
	{
		int temp = prev2 + prev1;
		if (temp % 2 == 0)
		{
			sum += temp;
		}
		prev2 = prev1;
		prev1 = temp;
	}
	printf("%d\n", sum);
}