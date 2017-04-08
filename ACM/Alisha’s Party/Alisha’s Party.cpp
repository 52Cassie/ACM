#include<stdio.h>
#define maxn 150005
#define inf -32768

struct friends//人信息
{
	char name[200];
	int value;
	int sort;
}fri[maxn];

struct door//开门信息
{
	int t;
	int p;
}doo[maxn];

bool sign[maxn]={0};//标记
int k,m,q,que[105],th=0,doo_th=1,max;
int main()
{
	int T,i,j,tt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&k,&m,&q);
		for(i=1;i<=k;i++)
		{
			scanf("%s%d",fri[i].name,&fri[i].value);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&doo[i].t,&doo[i].p);
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d",&que[i]);
		}
		tt=1;
		while(m--)
		{
			max=inf;
			int temp;
			//doo_th=;
			th++;
			for(i=1;i<=doo[th].p;i++)
			{
				max=inf;
				for(j=1;j<=doo[th].t;j++)
				{
					if(fri[j].value>max&&!sign[j])
					{
						max=fri[j].value;
						temp=j;
					}
				}
				fri[temp].sort=doo_th++;
				if(que[tt]==fri[temp].sort&&q!=1)
				{
					printf("%s ",fri[temp].name);
					tt++;
					q--;
				}
				else if(que[tt]==fri[temp].sort&&q==1)
				{
					printf("%s\n",fri[temp].name);
					tt++;
					break;
				}
				sign[temp]=1;
			}
			if(q==0)
				break;
		}
		//printf("time=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
	}
	return 0;
}
