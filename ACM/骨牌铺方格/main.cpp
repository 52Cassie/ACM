#include<stdio.h>

int main()
{
    int n,i;
    long long int way[55];

    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            if(i<=2)
                way[i]=i;
            else
                way[i]=way[i-1]+way[i-2];
        }
        printf("%I64d\n",way[n]);
    }
    return 0;
}
