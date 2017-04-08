#define _CRT_SECURE_NO_WARNINGS
#include <string.h>  
#include <stdio.h>  
#include <queue>  
using namespace std;

int s, n, m;
int vis[105][105][105];

struct node
{
	int s, n, m, step;
};
int check(int x, int y, int z)//ƽ������  
{
	if (x == 0 && y == z)
		return 1;
	if (y == 0 && x == z)
		return 1;
	if (z == 0 && x == y)
		return 1;
	return 0;
}

int bfs()
{
	queue<node> Q;
	node a, next;
	a.s = s;
	a.n = 0;
	a.m = 0;
	a.step = 0;
	vis[s][0][0] = 1;
	Q.push(a);
	while (!Q.empty())
	{
		a = Q.front();
		Q.pop();
		if (check(a.s, a.n, a.m))
			return a.step;
		if (a.n)//��n���л���  
		{
			if (a.n>s - a.s)//��n������s�����ܽ�s������  
			{
				next = a;
				next.n = next.n - (s - a.s);
				next.s = s;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else//��n������s���в��ܽ�s������  
			{
				next = a;
				next.s = next.n + next.s;
				next.n = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			if (a.n>m - a.m)//��n������m�����ܽ�m������  
			{
				next = a;
				next.n = next.n - (m - a.m);
				next.m = m;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else//��n������m���в��ܽ�m������  
			{
				next = a;
				next.m = next.n + next.m;
				next.n = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
		}
		if (a.m)//ͬ��  
		{
			if (a.m>s - a.s)
			{
				next = a;
				next.m = next.m - (s - a.s);
				next.s = s;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else
			{
				next = a;
				next.s = next.m + next.s;
				next.m = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			if (a.m>n - a.n)
			{
				next = a;
				next.m = next.m - (n - a.n);
				next.n = n;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else
			{
				next = a;
				next.n = next.m + next.n;
				next.m = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
		}
		if (a.s)//ͬ��  
		{
			if (a.s>n - a.n)
			{
				next = a;
				next.s = next.s - (n - a.n);
				next.n = n;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else
			{
				next = a;
				next.n = next.s + next.n;
				next.s = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			if (a.s>m - a.m)
			{
				next = a;
				next.s = next.s - (m - a.m);
				next.m = m;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
			else
			{
				next = a;
				next.m = next.m + next.s;
				next.s = 0;
				if (!vis[next.s][next.n][next.m])
				{
					next.step = a.step + 1;
					Q.push(next);
					vis[next.s][next.n][next.m] = 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int ans;
	while (~scanf("%d%d%d", &s, &n, &m), s || n || m)
	{
		if (s % 2)//�����϶�����ƽ�֣���Ϊ���������������С  
		{
			printf("NO\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		ans = bfs();
		if (ans)
			printf("%d\n", ans);
		else
			printf("NO\n");
	}

	return 0;
}