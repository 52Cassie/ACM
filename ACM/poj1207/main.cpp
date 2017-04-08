#include <iostream>

using namespace std;

int main()
{
    int i,j,i1,j1;
    int n,m,k,p;
    while(cin>>i>>j)
    {
        n = m = 0;
        i1 = i;
        j1 = j;
        if(i > j)
        {
            int t = i;
            i = j;
            j = t;
        }
        for(p = i;p <= j;p ++)
       {
           k = p;
           m = 1;
           while(k != 1)
            {
                if(k%2)
                    k = 3*k+1;
                else
                    k = k/2;
                m++;
            }
            if(n < m)
                n = m;
       }
        cout << i1 <<" "<< j1 <<" "<< n <<endl;
    }
    return 0;
}
