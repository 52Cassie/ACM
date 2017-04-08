#include<stdio.h>

int main()
{
    int n,i;
    long long int way[55];

    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            if(i==1)
                way[i]=3;
            else if(i==2||i==3)
                way[i]=6;
            else
            {
                if(i%2==0)
                    way[i]=way[i-1]*2+6;
                else
                    way[i]=way[i-1]*2-6;
            }
        }
        printf("%I64d\n",way[n]);
    }
    return 0;
}
