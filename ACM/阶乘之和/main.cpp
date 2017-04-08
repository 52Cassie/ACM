#include<stdio.h>

int main()
{
    const int MOD=1000000;
    int sum=0,i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        k=1;
        for(j=1;j<=i;j++)
        {
            k=(j*k)%MOD;
        }
        sum=(sum+k)%MOD;
    }
    printf("%d\n",sum);
    return 0;
}
