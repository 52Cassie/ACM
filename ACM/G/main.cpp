#include <iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[2005],v[27];
    int T,i,sum,n;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>str;
            n = strlen(str);
            sum=0;
            for(i=0;i<27;i++)
                v[i]=0;
            for(i=1;i<n;i+=2)
            {
                if(str[i]>='a' && str[i]<='z' && v[str[i]-'a'] == 0)
                {
                    sum++;
                    v[str[i]-'a'] = 1;
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
