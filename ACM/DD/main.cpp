#include<stdio.h>

int main()
{
    double c,sum;
    int i;
    while(scanf("%lf",&c)!=EOF && c != 0)
    {
        sum = 0;
        for(i = 1;;i ++)
        {
            sum += (1.0/(i+1));
            if(sum >= c)
                break;
        }
        printf("%d card(s)\n",i);
    }
    return 0;
}
