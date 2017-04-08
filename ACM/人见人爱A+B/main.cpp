#include<stdio.h>

int main()
{
    int AH,AM,AS,BH,BM,BS;
    int SH,SM,SS;
    int n,i;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d",&AH,&AM,&AS,&BH,&BM,&BS);
            if(AS+BS>=60)
            {
                SS=AS+BS-60;
                if(AM+BM+1>=60)
                {
                    SM=AM+BM+1-60;
                    SH=AH+BH+1;
                }
                else
                {
                    SM=AM+BM+1;
                    SH=AH+BH+1;
                }
            }
            else
            {
                SS=AS+BS;
                if(AM+BM>=60)
                {
                    SM=AM+BM-60;
                    SH=AH+BH+1;
                }
                else
                {
                    SM=AM+BM;
                    SH=AH+BH;
                }
            }
            printf("%d %d %d\n",SH,SM,SS);
        }
    }
    return 0;
}
