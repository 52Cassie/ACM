#include<stdio.h>
#include<string.h>

int palindrome(char str[],int n)
{
    int i;
    for(i=0;i<=n/2;i++)
    {
        if(str[i]!=str[n-1-i])
            break;
    }
    if(i<=n/2)return 0;
    else
        return 1;
}

int mirror(char str[],int n)
{
    int i,j;
    char a[2][40]={{"ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"},{'A',' ',' ',' ','3',' ',' ','H','I','L',' ','J','M',' ','O',' ',' ',' ','2','T','U','V','W','X','Y','5','1','S','E',' ','Z',' ',' ','8',' '}};
    for(i=0;i<=n/2;i++)
    {
        for(j=0;j<35;j++)
        {
            if(str[i]==a[0][j])
                break;
        }
        if(a[1][j]!=str[n-i-1])
            break;
    }
    if(i<=n/2)return 0;
    else
        return 1;
}

int main()
{
    char a[80];
    while(scanf("%s",a)!=EOF)
    {
        int n=strlen(a);
        if(palindrome(a,n)&&mirror(a,n))printf("%s -- is a mirrored palindrome.\n\n",a);
        else if(mirror(a,n))printf("%s -- is a mirrored string.\n\n",a);
        else if(palindrome(a,n))printf("%s -- is a regular palindrome.\n\n",a);
        else printf("%s -- is not a palindrome.\n\n",a);
    }
    return 0;
}
