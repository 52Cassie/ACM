#include<stdio.h>
#define maxn 1005

int main()
{
    double count = 0,temp1,temp;
    double j[maxn],f[maxn];
    int m,n,i,q;
    double sign[maxn],sum = 0;
    while(scanf("%d%d",&m,&n)!=EOF && (m!=-1&&n!=-1))
    {
        sum = 0;
        count = 0;
        for(i = 0;i < n;i ++)
        {
            scanf("%lf%lf",&j[i],&f[i]);
            sign[i] = j[i]/f[i];
        }
        for(i = 0;i < n-1;i ++)
            for(q = i+1;q < n;q ++)
            {
                if(sign[i]<sign[q])
                {
                    temp = sign[i];sign[i] = sign[q];sign[q] = temp;
                    temp = j[i];j[i] = j[q];j[q] = temp;
                    temp = f[i];f[i] = f[q];f[q] = temp;
                }
            }
        for(i = 0;i < n;i ++)
        {
            if(m >= f[i])
            {
                m -= f[i];
                sum += j[i];
            }
            else
            {
                sum += m * sign[i];
                m -= f[i];
                break;
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
