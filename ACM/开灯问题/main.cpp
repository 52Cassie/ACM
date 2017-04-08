#include<stdio.h>
#include<string.h>

int main()
{
    int n,k,i,j,a[1005],sum=0;
    scanf("%d%d",&n,&k);
    memset(a,0,sizeof(a));
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j%i==0)
                a[j]=!a[j];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i])
        {
            sum++;
            if(sum==1)printf("%d",i);
            else printf(" %d",i);
        }
    }
    return 0;
}
