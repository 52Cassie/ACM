#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define ll long long
using namespace std;
string test = "112123123412345123456123456712345678123456789123456789101234567891011123456789101112";

long long R;


void Solve()
{
    long long c, r = 1;
    cin >> c;
    long long i = 1;
    long long mark = 1;

    while (c - mark > 0) {
        if (mark + r > c) break;
        mark += r;
        i++;
        r += (int)log10(i) + 1;
    }

    i = 1;
    while (true) {
        if (c - (mark + (int)log10(i) + 1) < 0) break;
        else  {mark += (int)log10(i) + 1; i++; }
    }

    int len = 0, tmp = i;
    while (tmp > 0) {tmp /= 10; len++;}
    int ans = i / (int)pow(10, len - c + mark-1)  % 10;
    cout << ans << "\n";
}

int main()
{
    int T;
    cin >> T;
    FOR(i,1,T) Solve();
    return 0; 
}
