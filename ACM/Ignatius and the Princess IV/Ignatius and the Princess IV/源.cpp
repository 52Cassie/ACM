#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int a[1000005];

int main()
{
	int N,i,b,n,max;
	while (scanf("%d", &N) != EOF)
	{
		n = (N + 1) / 2;
		memset(a, 0, sizeof(a));
		for (i = 0; i < N; i++)
		{
			scanf("%d", &b);
			a[b]++;
			if (a[b] >= n)
			{
				max = b;
			}	
		}
		printf("%d\n", max);
	}
	return 0;
}