#include<stdio.h>

int main()
{
    int a,min,max,count=0;
    double aver,sum=0;
    while(scanf("%d",&a)==1)
    {
        sum+=a;
        count++;
        if(count==1)
            min=max=a;
        else
        {
            if(min>a)
                min=a;
            if(max<a)
                max=a;
        }
    }
    aver=sum/count;
    printf("%d %d %.3lf\n",min,max,aver);
    return 0;
}
