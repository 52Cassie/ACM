#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define maxn 100000

struct student
{
	char sub[105];
	int D, C;
}Home[15];

struct subject
{
	char xue[100];
}SUB[15];

int main()
{
	//char copy[15][100];
	int T, N, red;
	int k;
	int i, j, day, min1 = maxn, min2 = maxn;
	
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			red = 0;
			day = 0;
			k = 0;
			int sign[15] = { 0 };
			scanf("%d", &N);
			for (i = 0; i < N; i++)
			{
				scanf("%s%d%d", Home[i].sub, &Home[i].D, &Home[i].C);
			}
			for (int n = 0; n < N;n++)
			{
				min1 = maxn;
				min2 = maxn;
				for (i = 0; i < N; i++)
				{
					if (min1 >= Home[i].D&&!sign[i])
					{
						if (min1>Home[i].D)
						{
							min1 = Home[i].D;
							min2 = Home[i].C;
							j = i;
						}
						else
						if (min2 > Home[i].C)
						{
							min1 = Home[i].D;
							min2 = Home[i].C;
							j = i;
						}

					}
				}
				
				sign[j] = 1;
				strcpy(SUB[k++].xue, Home[j].sub);
				day += Home[j].C;
				if (Home[j].D < day)
				{
					red += day - Home[j].D;
				}
			}
			printf("%d\n", red);
			for (i = 0; i < N; i++)
			{
				printf("%s\n", SUB[i].xue);
			}
		}
	}
	return 0;
}