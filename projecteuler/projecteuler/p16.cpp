#include <stdio.h>
#include <vector>
using namespace std;
#define POWER 1000
void p16()
{
	vector<char> prod;
	prod.push_back(8);
	prod.push_back(6);
	prod.push_back(7);
	prod.push_back(2);
	prod.push_back(3);

	for (int i = 16; i <= POWER; i++)
	{
		int carry = 0;
		for (int j = 0; j < prod.size(); j++)
		{
			int tmp = ((prod[j] * 2) + carry);
			carry = tmp / 10;
			prod[j] = tmp % 10;
		}
		if (carry != 0)
			prod.push_back(carry);
	}
	unsigned long long sum = 0;
	for (int i = 0; i < prod.size(); i++)
	{
		sum += prod[i];
	}

	printf("%llu", sum);
	while (1);
}