
#include <stdio.h>
#include <math.h>


unsigned long long FindNumDivisor(unsigned long long num)
{
	unsigned long long numDiv = 0;
	for (unsigned long long i = 1; i < ceil(sqrt(num)); i++)
	{
		if (num%i == 0)
		{
			numDiv += 2;
		}
	}

	if (sqrt(num) == ceil(sqrt(num)))
	{
		numDiv += 1;
	}

	return numDiv;

}

void p12()
{
	// 9699690 is mult of first 8 primes. Because the number(mult) with first 8 prime
	// has 2^8(256) different divisor. So it's an optimization to start with this number.
	unsigned long long startNum = 9699690;

	for (unsigned long long i = 1; ; i++)
	{
		if (i*(i + 1) > 2 * startNum)
		{
			if (FindNumDivisor((i*(i + 1)) / 2) > 500)
			{
				printf("%llu\n", (i*(i + 1)) / 2);
				break;
			}
		}
	}


}