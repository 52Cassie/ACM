#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int a[1000001][11];

int _tmax(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int main()
{
	int n, i, j, x, t, maxi;
	while (scanf("%d", &n) != EOF&&n)
	{
		memset(a, 0, sizeof(a));
		maxi = 0;
		for (i = 0; i<n; i++)
		{
			scanf("%d%d", &x, &t);
			a[t][x]++;
			if (t>maxi)
				maxi = t;
		}
		for (i = maxi - 1; i >= 0; i--)
		{
			for (j = 0; j <= 10; j++)
			{
				if (j == 0)
					a[i][j] += _tmax(a[i + 1][j], a[i + 1][j + 1]);
				else if (j == 10)
					a[i][j] += _tmax(a[i + 1][j - 1], a[i + 1][j]);
				else
					a[i][j] += _tmax(_tmax(a[i + 1][j - 1], a[i + 1][j]), a[i + 1][j + 1]);
			}
		}
		printf("%d\n", a[0][5]);
	}
	return 0;
}