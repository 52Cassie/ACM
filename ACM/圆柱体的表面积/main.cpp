#include"stdio.h"
#include<math.h>
int main()
{
    double r,h,S,s1,s2;
    const double PI=acos(-1.0);

    scanf("%lf%lf",&r,&h);
    s1=PI*r*r;
    s2=2*PI*r*h;
    S=s2+2*s1;
    printf("%lf\n",S);
    return 0;
}
