#include <stdio.h>
#define MAX 10000000000
unsigned long long mult(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;

	unsigned long long res = mult(a, b / 2);

	//printf("%llu\n", res);
	res = ((unsigned long long)(res *res)) % (unsigned long long)MAX;

	if (b % 2 == 1)
		res = ((unsigned long long)(res*a)) % (unsigned long long)MAX;

	return res;
}

void p48()
{
	unsigned long long sum = 0;

	//FILE *fp = fopen("simple.txt", "w");
	//FILE *fp1 = fopen("eff.txt", "w");
	//printf("%llu\n", ret);
	/*
	for (unsigned long long i = 1; i <= 1000; i++)
	{
	unsigned long long tmp = i;
	for (unsigned long long j = 1; j < i; j++)
	{
	tmp = ((unsigned long long)(tmp*i)) % (unsigned long long)MAX;;
	}
	fprintf(fp, "%llu\n", tmp);
	sum = ((unsigned long long)(sum + tmp)) % (unsigned long long)MAX;
	}
	*/
	//fclose(fp);
	//unsigned long long res = mult(16, 16);
	//printf("%llu\n", res);


	//return;

	for (unsigned long long i = 1; i <= 10; i++)
	{
		unsigned long long res = mult(i, i);
		//printf("%llu\n", res);
		//fprintf(fp1, "%llu\n", res);
		sum = ((unsigned long long)(sum + res)) % (unsigned long long)MAX;
	}
	//fclose(fp1);
	printf("%llu\n", sum);

}