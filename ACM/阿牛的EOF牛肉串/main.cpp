#include<stdio.h>

int main()
{
    int n,i;
    long long int way[45];

    while(scanf("%d",&n)!=EOF)
    {
        way[1]=3;
        way[2]=8;
        for(i=3;i<=n;i++)
        {
            way[i]=2*(way[i-1]+way[i-2]);
        }
        printf("%I64d\n",way[n]);
    }
    return 0;
}
