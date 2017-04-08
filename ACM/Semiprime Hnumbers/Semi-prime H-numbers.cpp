#include<stdio.h>
#include<string.h>

int num[1000001],p[1000001];
int z=1000001;

void biao()
{
	memset(num,0,sizeof(num));
	int i,j;
	for(i=5;i<=z;i+=4)
	{
		for(j=5;i*j<=z;j+=4)
		{
			if(num[i]||num[j])
				num[i*j]=-1;
			else
				num[i*j]=1;
		}
	}
	int cnt=0;
	for(i=1;i<=z;i++)
	{
		if(num[i]==1)cnt++;

		p[i]=cnt;
	}
}

int main()
{
	biao();
	int H;
	while(scanf("%d",&H)!=EOF&&H)
	{
		H=(H-1)/4*4+1;
		printf("%d %d\n",H,p[H]);
	}
	return 0;
}