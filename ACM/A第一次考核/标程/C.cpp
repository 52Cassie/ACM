#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 5005
#define INF 10000000
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
int N; 
short F[MAXN][MAXN];
string S;

void Solve()
{
    cin >> N >> S;

    ROF(i,N,1) FOR(j,0,N) {
        if (j <= i) continue;
        if (S[i-1] == S[j-1]) F[i][j] = F[i+1][j-1];
        else F[i][j] = min(F[i+1][j], F[i][j-1]) + 1;
    }
        
    cout << F[1][N] << "\n";
}

int main()
{
    Solve();
    return 0;
}
