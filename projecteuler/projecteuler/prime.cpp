

#include "prime.h"
#include<math.h>

void GetPrimes(std::vector<unsigned long long> &primes, unsigned long long limit)
{
	bool *isPrime = new bool[limit + 1];

	for (size_t i = 0; i <= limit; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;

	unsigned long long root = ceil(sqrt(limit));
	for (unsigned long long i = 2; i < root; i++)
	{
		if (isPrime[i])
		{

			for (size_t j = i; i*j <= limit; j++)
			{
				isPrime[i*j] = false;
			}
		}
	}
	
	for (unsigned long long i = 0; i <= limit; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
}