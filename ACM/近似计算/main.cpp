#include<stdio.h>
#include<math.h>

int main()
{
    const double PI=acos(-1.0);
    int n=0;
    double sum=0,sum1;
    do
    {
        n++;
        if(n%2==0)
            sum-=1.0/(2*n-1);
        else
            sum+=1.0/(2*n-1);
    }while(1.0/(2*n-1)>1e-6);
    sum1=PI/4;
    printf("%lf %lf\n",sum,sum1);
    return 0;
}
