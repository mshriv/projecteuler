#include <stdio.h>
#include <vector>
using namespace std;

void Mult(vector<char> &prod, int i)
{
	int carry = 0;
	for (int j = 0; j < prod.size(); j++)
	{
		int tmp = prod[j] - '0';
		tmp = tmp*i + carry;
		prod[j] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	while (carry != 0)
	{
		prod.push_back(carry % 10 + '0');
		carry /= 10;
	}
}

void p20()
{
	unsigned long long fact = 0;
	vector<char> prod;
	prod.push_back(1 + '0');
	for (int i = 1; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			Mult(prod, i / 10);
		}
		else
			Mult(prod, i);
	}

	for (int i = 0; i < prod.size(); i++)
	{
		fact += prod[i] - '0';
	}
	printf("%llu",fact);
	while (1);
}