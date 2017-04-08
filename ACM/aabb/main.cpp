#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,n;
    for(a=1;a<=9;a++)
    {
        for(b=0;b<10;b++)
        {
            n=sqrt(a*1100+b*11);
            if(n*n==a*1100+b*11)
                printf("%d\n",a*1100+b*11);
        }
    }
    return 0;
}
