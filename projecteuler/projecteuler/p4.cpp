#include <stdio.h>
#include <math.h>

bool IsProductOfTwoNum(int curpalin)
{
	for (int i = 999; i > sqrt(curpalin); i--)
	{
		if (curpalin%i == 0)
			return true;
	}

	return false;
}

int NextPalin(int palin)
{
	int i,j, rev_i, newpalin;
	if (palin < 100000)
	{

		i = (palin / 100) - 1;
		j = i / 10;
		rev_i = (j%10)*10 + (j/10);
	
		newpalin = i * 100 + rev_i;
	}
	else
	{
		i = (palin / 1000) - 1;
		rev_i = (i%10)*100+((i/10)%10)*10 + (i/100);
		newpalin = i * 1000 + rev_i;
	}

	return newpalin;




}

void p4()
{
	int maxpalin = 999999;
	int minpalin = 10001;

	for (int curpalin = maxpalin; curpalin >= minpalin; curpalin = NextPalin(curpalin))
	{
		if (IsProductOfTwoNum(curpalin))
		{
			printf("%d\n", curpalin);
			break;
		}
	}
}