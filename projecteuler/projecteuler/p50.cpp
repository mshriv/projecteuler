#include <vector>
using namespace std;

void FindListOfPrime(vector<unsigned long> &prime, const unsigned long limit)
{
	bool *arr = new bool[limit + 1];
	for (int i = 0; i <= limit; i++) arr[i] = true;
	arr[0] = arr[1] = false;

	for (unsigned long i = 2; i <= limit; i++)
	{
		if (arr[i])
		{
			prime.push_back(i);

			for (int j = i; j * i <= limit; j++)
			{
				arr[j*i] = false;
			}
		}
	}

	delete[] arr;

}

unsigned long long FindLongestConsecutiveSumPrime(const vector<unsigned long> &prime, const unsigned long limit)
{
	unsigned long long *sum = new unsigned long long[prime.size()];
	bool *isprime = new bool[limit + 1];
	for (int i = 0; i <= limit; i++) isprime[i] = false;

	for (unsigned int i = 0; i < prime.size(); i++)
	{
		isprime[prime[i]] = true;;
		sum[i] = 0;
	}

	unsigned long long ret = 0;
	for (unsigned int i = 1; i <= prime.size(); i++)
	{
		for (unsigned int j = 0; (j <= prime.size() - i) && (sum[j] < limit); j++)
		{
			sum[j] += prime[j + i - 1];
			if ((sum[j] <= limit) && (isprime[sum[j]]))
			{
				ret = sum[j];
			}
		}
	}

	delete[] sum;
	delete[] isprime;

	return ret;
}

void p50()
{
	const unsigned long limit = 1000000;
	vector<unsigned long> primes;
	FindListOfPrime(primes, limit);
	//printf("%lu\n",primes[10000]);
	unsigned long long sum = (unsigned long long)0;
	for (unsigned int i = 0; i < primes.size(); i++)
	{
		sum += (unsigned long long)primes[i];
	}
	unsigned long long ret = FindLongestConsecutiveSumPrime(primes, limit);
	printf("\n%llu %llu\n", ret, sum);
}