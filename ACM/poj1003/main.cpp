#include<stdio.h>

int main()
{
    int n;
    float len,sum;
    while(scanf("%f",&len) && len != 0)
    {
        n = 1;
        sum = 0;
        do
        {
            sum += 1.0/(n+1);
            if(sum > len)
                break;
        }while(n++);
        printf("%d card(s)\n",n);
    }
    return 0;
}
