#include<stdio.h>
#include<string.h>

int main()
{
    char a[10],buf[80];
    int abc,de,count=0,ok,n;
    scanf("%s",a);
    for(abc=111;abc<=999;abc++)
    {
        for(de=11;de<=99;de++)
        {
            int x=abc*(de%10);
            int y=abc*(de/10);
            int z=abc*de;
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);//把结果输入进字符串中
            n=strlen(buf);
            for(int i=0;i<n;i++)
            {
                if(strchr(a,buf[i]))ok=1;//字符串中的数依次与a中的数字相比较
                else
                {
                    ok=0;
                    break;
                }
            }
            if(ok==1)
            {
                printf("<%d>\n",++count);
                 printf("%5d\nX%4d\n----\n%5d\n%4d\n----\n%5d\n\n",abc,de,x,y,z);
            }

        }
    }
    printf("The number of solutions=%d\n",count);
    return 0;
}
