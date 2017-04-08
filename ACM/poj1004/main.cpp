#include<stdio.h>

int main()
{
    double sum = 0,a,ave;
    int i;
    for(i = 1;i <= 12;i ++)
    {
        scanf("%lf",&a);
        sum += a;
    }
    ave = sum/12.0;
    printf("$%.2lf\n",ave);
    return 0;
}
