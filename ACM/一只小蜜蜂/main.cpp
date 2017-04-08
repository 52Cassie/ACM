#include<stdio.h>

long long int wayf[55];

int main()
{
    int N,a,b;
    int i,step,j;

    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d%d",&a,&b);
            for(j=0;j<3;j++)
                wayf[j]=j;
            for(j=3;j<=b-a;j++)
                wayf[j]=wayf[j-1]+wayf[j-2];
            printf("%I64d\n",wayf[b-a]);
        }
    }
    return 0;
}
