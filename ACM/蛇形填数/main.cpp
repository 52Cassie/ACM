#include<stdio.h>
#include<string.h>

int main()
{
    int a[10][10];
    int n,i,j,t,sum;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    t=a[i=0][j=n-1]=1;
    sum=n*n;
    while(t<sum)
    {
        while(!a[i+1][j]&&i<n-1)
            a[++i][j]=++t;
        while(!a[i][j-1]&&j>0)
            a[i][--j]=++t;
        while(!a[i-1][j]&&i>0)
            a[--i][j]=++t;
        while(!a[i][j+1]&&j<n-1)
            a[i][++j]=++t;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
