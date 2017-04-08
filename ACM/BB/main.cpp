#include<stdio.h>
#include<string.h>

int main()
{
    int count = 0,t,n;
    int p[25],w[25] = {0},str[1000];
    int i,ac,sum = 0,pre,j;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(str,0,sizeof(str));
            count = 0;
            sum = 0;
            memset(w,0,sizeof(w));
            scanf("%d",&n);
            for(i = 0;i < n;i++)
            {
                scanf("%d",&p[i]);
            }
            ac = p[0];
            while(ac --)
            {
                str[count ++] = 0;
            }
            str[count ++] = 1;
            for(i = 1;i < n;i ++)
            {
                ac = p[i] - p[i-1];
                while(ac--)
                {
                    str[count ++] = 0;
                }
                str[count ++] = 1;
            }
            pre = str[0];
            for(i = 1;i <= count-1;i ++)
            {
                if(str[i] == 0)
                    pre = i;
                else
                {
                    for(j = i;j >=0;j --)
                    {
                        if(str[j] == 1)
                            w[sum]++;
                        if(j == pre)
                            break;
                    }
                    sum++;
                    str[pre] = -1;
                    for(j = pre;j > -1;j --)
                    {
                        if(str[j] == 0)
                        {
                            pre = j;
                            break;
                        }
                    }
                }
            }
            for(i = 0;i < n-1;i ++)
            {
                printf("%d ",w[i]);
            }
            printf("%d\n",w[n-1]);
        }
    }
    return 0;
}
