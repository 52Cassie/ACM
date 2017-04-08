#include<stdio.h>

int main()
{
    int n,m,a,b;
    double a1,b1;
    scanf("%d%d",&n,&m);
    a=a1=(4*n-m)/2;
    b=b1=n-a1;
    if(a>0&&b>0&&a1-a<1e-6)
        printf("%d %d\n",a,b);
    else
        printf("no answer.\n");
    return 0;
}
