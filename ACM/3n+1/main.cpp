#include<stdio.h>

int main()

{
    long long int n1,n;
    int step=0;
    scanf("%I64d",&n1);
    n=n1;
    while(n!=1)
    {
        if(n%2==0)
            n=n/2;
        else
            n=3*n+1;
        step++;
    }
    printf("%d\n",step);
    return 0;
}
