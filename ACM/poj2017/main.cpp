#include <iostream>

using namespace std;

int main()
{
    int s[11],t[11];
    int n;
    int sum;
    while(cin>>n && n != -1)
    {
        sum = 0;
        for(int i = 0;i < n;i ++)
        {
            cin>>s[i]>>t[i];
        }
        sum += s[0]*t[0];
        for(int i = 1;i < n;i ++)
        {
            sum += s[i]*(t[i]-t[i-1]);
        }
        cout << sum << " miles\n";
    }
    return 0;
}
