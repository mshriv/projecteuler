#include <vector>
#include "prime.h"
using namespace std;

void p10()
{
	vector<unsigned long long> primes;
	const unsigned long long limit = 2000000;
	GetPrimes(primes, limit);
	unsigned long long sum = 0;
	for (size_t i = 0; i < primes.size(); i++)
	{
		sum += primes[i];
	}

	printf("%llu\n", sum);
	
}