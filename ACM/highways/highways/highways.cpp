// highways.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"windows.h"
#include <iostream>
 #include <cstring>
 #include <string>
 #include <algorithm>

 const int maxn = 501;
 int g[maxn][maxn];
 bool vis[maxn];
 int d[maxn];
 int n, t;
 int _min, _max;

 void _tprim()
{
     memset(vis, 0, sizeof(vis));
     vis[0] = 1;
     int size = 1;
     _max = 0;
     for (int i = 1; i < n; i++)
	 {
        d[i] = g[0][i];
	 }
     while (size < n) 
	 {
         _min = 65536;
         int k;
         for (int i = 1; i < n; i++) 
		 {
             if (!vis[i] && d[i] < _min) 
			 {
                 _min = d[i];
                 k = i;
			 }
		 }
         vis[k] = 1;
         if (_min > _max) _max = _min;

         for (int i = 0; i < n; i++) {
             if (!vis[i] && g[i][k] < d[i])
                 d[i] = g[k][i];
		 }
         size++;
	 }
 }

int _tmain(int argc, _TCHAR* argv[])
{
	scanf_s("%d", &t);
     while (t--){
         scanf_s("%d", &n);
         for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
                 scanf_s("%d", &g[i][j]);
         _tprim();
         printf("%d\n", _max);
	}
	system("pause");
	return 0;
}

