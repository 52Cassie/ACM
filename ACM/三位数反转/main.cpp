#include<stdio.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    i=n/100;
    j=n/10%10;
    k=n%10;
    printf("%d%d%d\n",k,j,i);
    return 0;
}
