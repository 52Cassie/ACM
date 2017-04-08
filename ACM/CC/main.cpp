#include<stdio.h>
#include<string.h>

int main()
{
    int x,a,v[105];
    int i,j;
    int n,sum;
    while(scanf("%d",&n) != EOF && n != 0)
    {
        memset(v,0,sizeof(v));
        sum = 0;
        for(i = 0;i < n;i ++)
        {
            scanf("%d%d",&x,&a);
            v[a]++;
            for(j = a+1;j < 105;j++)
                sum += v[j];
            sum %= 1000000;
        }
        printf("%d\n",sum);
    }
    return 0;
}
