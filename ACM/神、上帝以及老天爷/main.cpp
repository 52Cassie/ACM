#include<stdio.h>
/*ȫ�ֱ����ǻ��Զ���ʼ��Ϊ0�ģ�����OJ��ʹ��ȫ�ֱ�����һ��Ŀ�ģ�
ȫ�����ݴ洢�ھ�̬����������ݺܴ�Ļ���ջ��������ѻ��������ھ�̬���ȽϺá�*/
double way[25], sum;

double fac(int x)
{
    int i;
    double f=1;
    for(i=1;i<=x;i++)
        f=f*i;
    return f;
}

int main()
{
    int c,n,i,j;

    while(scanf("%d",&c)!=EOF)
    {
        for(i=1;i<=c;i++)
        {
            scanf("%d",&n);
            way[1]=0;
            way[2]=1;
            for(j=3;j<=n;j++)
            {
                way[j]=(way[j-1]+way[j-2])*(j-1);
            }
            sum=fac(n);
            printf("%.2lf%%\n",(way[n]*100.0)/sum);
        }
    }
    return 0;
}
