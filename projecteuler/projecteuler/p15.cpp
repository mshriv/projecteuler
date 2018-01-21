#include <stdio.h>
#define GRID 20
unsigned long long CalculatePath(int sr, int sc, int er, int ec, unsigned long long mat[GRID+1][GRID+1])
{
	unsigned long long num = 0;
	unsigned long long tmp = 0;
	if ((sr == er) && (ec == sc))
		return 1;
	if (sr < er)
	{
		if (mat[sr + 1][sc] != 0)
			tmp = mat[sr + 1][sc];
		else
		{
			tmp = CalculatePath(sr + 1, sc, er, ec, mat);
			mat[sr + 1][sc] = tmp;
		}
		num += tmp;
	}
	if (sc < ec)
	{
		if (mat[sr][sc+1] != 0)
			tmp = mat[sr][sc+1];
		else
		{
			tmp = CalculatePath(sr, sc + 1, er, ec, mat);
			mat[sr][sc + 1] = tmp;
		}
		num += tmp;
	}

	return num;
}

void p15()
{
	int num = GRID;
	int sr = 0, sc = 0, er = num, ec = num;
	unsigned long long mat[GRID+1][GRID+1];
	for (int i = 0; i <= GRID; i++)
	{
		for (int j = 0; j <= GRID; j++)
			mat[i][j] = 0;
	}
	unsigned long long numpath = CalculatePath(sr, sc, er, ec,mat);

	printf("%llu\n", numpath);
	while (1);
}