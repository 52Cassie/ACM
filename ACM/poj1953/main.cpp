#include <iostream>

using namespace std;

int main()
{
    int n,i = 0,j;
    int S[50];
    S[1] = 2;
    S[2] = 3;
    for(int i = 3;i <= 46;i ++)
    {
        S[i] = S[i-1] + S[i-2];
    }
    while(cin >> n)
    {
        while(n--){
            cin >> j;
            cout << "Scenario #" << ++i << ":" <<endl << S[j] << endl << endl;
        }

    }
    return 0;
}
