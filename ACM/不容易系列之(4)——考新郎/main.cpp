#include<stdio.h>
long long int way[25],sum,c,m,n;

int fac(int x)
{
    int f;
    if(x==0||x==1)
        f=1;
    else
        f=fac(x-1)*x;
    return f;
}

int main()
{
    int i;
    while(scanf("%d",&c)!=EOF)
    {
        while(c--)
        {
            scanf("%d%d",&n,&m);
            way[1]=0;
            way[2]=1;
            for(i=3;i<=m;i++)
            {
                way[i]=(way[i-1]+way[i-2])*(i-1);
            }
            sum=fac(n)/fac(m)/fac(n-m);
            printf("%I64d\n",sum*way[m]);
        }
    }
    return 0;
}
