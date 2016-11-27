#include <stdio.h>
#include <vector>

using namespace std;

void FindPrime(bool *&isprime, unsigned int limit)
{
	isprime = new bool[limit + 1];

	for (size_t i = 0; i <= limit; i++)
	{
		isprime[i] = true;
	}
	isprime[0] = isprime[1] = false;

	for (size_t i = 0; i <= limit; i++)
	{
		if (!isprime[i])
			continue;
		for (size_t j = i; i*j <= limit; j++)
		{
			isprime[j*i] = false;
		}
	}
}

bool AreThisSame(unsigned int a, unsigned int b, unsigned int c)
{

	int isthere[10];
	int isthere1[10];
	for (int i = 0; i < 10; i++)
	{
		isthere[i] = 0;
		isthere1[i] = 0;
	}

	char str[5];

	sprintf(str, "%u", a);
	isthere[str[0] - '0']++;
	isthere[str[1] - '0']++;
	isthere[str[2] - '0']++;
	isthere[str[3] - '0']++;

	sprintf(str, "%u", b);
	isthere1[str[0] - '0']++;
	isthere1[str[1] - '0']++;
	isthere1[str[2] - '0']++;
	isthere1[str[3] - '0']++;

	if ((isthere[str[0] - '0'] != isthere1[str[0] - '0']) || (isthere[str[2] - '0'] != isthere1[str[2] - '0']) || (isthere[str[3] - '0'] != isthere1[str[3] - '0']) || (isthere[str[1] - '0'] != isthere1[str[1] - '0']))
		return false;

	sprintf(str, "%u", c);
	isthere1[str[0] - '0']--;
	isthere1[str[1] - '0']--;
	isthere1[str[2] - '0']--;
	isthere1[str[3] - '0']--;

	if (isthere1[str[0] - '0'] || isthere1[str[2] - '0'] || isthere1[str[3] - '0'] || isthere1[str[1] - '0'])
		return false;

	return true;

}

void p49()
{
	bool *prime;
	unsigned int highestnumber = 10000;

	FindPrime(prime, highestnumber);

	unsigned int i = 0;
	while (i>1000 && !prime[i]) i++;

	for (unsigned int j = i; j <= highestnumber; j++)
	{
		if (!prime[j])
			continue;
		for (unsigned int dist = 1; (((j + dist) <= highestnumber) && ((j + dist + dist) <= highestnumber)); dist++)
		{
			if (prime[j + dist] && prime[j + dist + dist])
			{

				if (AreThisSame(j, dist + j, dist + dist + j))
					printf("%u%u%u\n", j, dist + j, dist + dist + j);
			}

		}
	}
	printf("======");
}