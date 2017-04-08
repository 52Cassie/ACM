#include<stdio.h>

#define maxn 5000005

int T;
long n,a,b,sum,t[maxn];

int main()
{
	int i,j,count=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t[i]);
		}
		sum=a*t[1]*t[1]+b*t[2];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i!=j)&&(sum<a*t[i]*t[i]+b*t[j]))
					sum=a*t[i]*t[i]+b*t[j];
			}
		}
		printf("case #%d: %d\n",++count,sum);
	}
	return 0;
}
