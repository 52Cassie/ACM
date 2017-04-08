#include<stdio.h>
#include<string.h>

char s[5005];
int dp[5005][5005],n;

int min(int x,int y)
{
	return x<y?x:y;
}

int DP()
{
	int i,j,x;
	memset(dp,0,sizeof(dp));
		for(i=n/2;i>=0;i--)
		{
			for(j=n/2;j<n;j++)
			{
				if(s[i-1]==s[j-1])
					dp[i][j]=dp[i+1][j-1];
				else
					dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
			}
		}
	return dp[0][n-1];
}

int main()
{
	int x;
	scanf("%d",&n);
	scanf("%s",s);
	x=DP();
	printf("%d\n",x);
	return 0;
}