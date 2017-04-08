#include<stdio.h>
#include<string.h>

int compare(char a[],char b[]);
int main()
{
    char name[105][21];
    int sign[105];
    int i,j;
    int n,count;
    while(scanf("%d",&n) != EOF)
    {
        for(i = 0;i < n;i ++)
        {
            scanf("%s",name[i]);
        }
        memset(sign,1,sizeof(sign));
        count = 0;
        for(i = 0;i < n-1;i ++)
        {
            for(j = 1;j < n;j ++)
                if(compare(name[i],name[j]))
                {
                    sign[i] = 0;
                    sign[j] = 0;
                }
        }
        for(i = 0;i < n;i ++)
        {
            if(sign[i] == 0)
            {
                count ++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

int compare(char a[],char b[])
{
    int lena,lenb,i,num;
    lena = strlen(a);
    lenb = strlen(b);
    num = 0;
    if(lena == lenb)
    {
        for(i = 0;i < lena;i ++)
        {
            if(a[i] == b[i] || a[i]+32 == b[i] || a[i]-32 == b[i])
                num ++;
            if(num > 2)
                return 1;
        }
        return 0;
    }
    else return 0;
}
