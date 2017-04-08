#include<stdio.h>
/*全局变量是会自动初始化为0的，这是OJ中使用全局变量的一个目的；
全局数据存储在静态区，如果数据很大的话，栈会溢出，堆会慢，存在静态区比较好。*/
double way[25], sum;

double fac(int x)
{
    int i;
    double f=1;
    for(i=1;i<=x;i++)
        f=f*i;
    return f;
}

int main()
{
    int c,n,i,j;

    while(scanf("%d",&c)!=EOF)
    {
        for(i=1;i<=c;i++)
        {
            scanf("%d",&n);
            way[1]=0;
            way[2]=1;
            for(j=3;j<=n;j++)
            {
                way[j]=(way[j-1]+way[j-2])*(j-1);
            }
            sum=fac(n);
            printf("%.2lf%%\n",(way[n]*100.0)/sum);
        }
    }
    return 0;
}
