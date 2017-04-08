// Mr. Kitayuta's Gift.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"windows.h"
#define inf 66553
	
int n, k, m=0, a[101], b[101];
bool v[101] = { 0 };
int sum = 0,j=0;

int _tprim()
{
	int i,min=inf;
	int y;
	while (j <= n)
	{
		min = inf;
		for (i = 0; i < n; i++)
		{
			if (!v[i] && a[i] < min)
			{
				min = a[i];
				y = i;
			}
		}
		v[y] = 1;
		if (sum < k)
		{
			sum += a[y];
			if (sum <= k)
			{
				b[m++] = y + 1;
			}
			else
				break;
		}
		j++;
	}
	return m;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	scanf_s("%d%d", &n,&k);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	m=_tprim();
	printf("%d\n", m);
	if (m>0)
	{
		for (i = 0; i < m - 1; i++)
			printf("%d ", b[i]);
		printf("%d\n", b[m-1]);
	}
	system("pause");
	return 0;
}

