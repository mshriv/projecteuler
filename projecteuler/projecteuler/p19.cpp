#include <stdio.h>

void p19()
{
	int sday = 2;
	int sunday5[7] = { 1, 0, 0, 0, 0, 1, 1 };
	int numdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int numsun = 0;
	bool isleap = false;

	for (int i = 1901; i <= 2000; i++)
	{
		isleap = false;
		if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
			isleap = true;

		for (int j = 1; j <= 12; j++)
		{
			if (sday == 0)
			{
				numsun++;
			}
			if (isleap && j==2)
				sday = (sday + (numdays[j] + 1) % 7) % 7;
			else
				sday = (sday + numdays[j] % 7) % 7;
		}
	}

	printf("%d", numsun);
	while (1);
}