#include<stdio.h>

int main()
{
    int n,a,sum,min,max,count=1;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sum+=a;
            if(i==1)
                min=max=a;
            else
            {
                if(min>a)
                    min=a;
                if(max<a)
                    max=a;
            }
        }
        printf("Case %d:%d %d %.3f\n\n",count++,min,max,(float)sum/n);
    }
}
