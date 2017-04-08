#include<stdio.h>
#include<string.h>

int main()
{
    char a[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i,c;
    while((c=getchar())!=EOF)
    {
        if(c==' '||c=='\n')
                putchar(c);
        for(i=1;a[i]!='\0';i++)
        {
            if(a[i]==c)
                putchar(a[i-1]);
        }
    }
    return 0;
}
