#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	unsigned long long num = 600851475143;
	unsigned int sqrtnum = sqrt(long double(num)) - 1;
	bool *arr = new bool[sqrtnum+1];
	vector <unsigned long long> primes;
	memset(arr, 1, sizeof(bool)*(sqrtnum + 1));
	arr[1] = false;
	for (unsigned int i = 2; i <= sqrtnum; i++)
	{
		if (arr[i] == false)
			continue;
		else
			primes.push_back(i);
		for (int j = i; i*j <= sqrtnum; j++)
		{
			arr[i*j] = false;
		}
	}
	delete[] arr;


	unsigned long long largestprime = num;
	
	for (unsigned long long i = 0 ; i < primes.size() && (largestprime != primes[i]); i++)
	{
		if (largestprime%primes[i] == 0)
		{
	
			largestprime = largestprime / primes[i];
			i--;
		}


	}
	printf("%llu\n", largestprime);
	while (1);
}