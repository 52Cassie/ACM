// Milking Cows.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"windows.h"
#include"iostream"

using namespace std;

int _tmax(int x, int y)
{
	if (x > y)return x;
	else return y;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int N, begin[5001], end[5001],tmpbegin,tmpend;
	int ans1, ans2, i, j, t;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> begin[i] >> end[i];
	for (i = 0; i < N-1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (begin[i]>begin[j])
			{
				t = begin[i];
				begin[i] = begin[j];
				begin[j] = t;
				t = end[i];
				end[i] = end[j];
				end[j] = t;
			}
		}
	}
	tmpbegin = begin[0];
	tmpend = end[0];
	ans1 = tmpend - tmpbegin;
	ans2 = 0;
	for (i = 1; i < N; i++)
	{
		if (begin[i] <= tmpend)
		{
			tmpend = _tmax( tmpend, end[i] );
			ans1 = _tmax( ans1, tmpend - tmpbegin );	
		}
		else
		{
			ans1 = _tmax( ans1, tmpend - tmpbegin );
			ans2 = _tmax( ans2, begin[i] - tmpend );
			tmpbegin = begin[i];
			tmpend = end[i];
		}
	}
	tmpbegin = begin[N - 1];
	tmpend = end[N - 1];
	ans1 = _tmax( ans1, tmpend - tmpbegin );
	cout << ans1 <<' '<< ans2 << endl;
	system("pause");
	return 0;
}

