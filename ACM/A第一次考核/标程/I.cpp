#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <numeric>
#include <vector>
#define MAXN 1000005
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
bool prime[MAXN], mark[MAXN], sprime[MAXN];
int tot, HP[MAXN];

void MakeSemiHPrime()
{
    fill(prime, prime+MAXN, true);
    fill(sprime, sprime+MAXN, false);

    FOR(i,2,MAXN-1) 
        if (prime[i] && (i - 1) % 4 != 0) prime[i] = false;

    FOR(i,2,MAXN-1) {
        if (prime[i]) {
            int f = i * 2;
            while (f < MAXN) { prime[f] = false; f += i; }
        }
    }

    FOR(i,2, 200000) if (prime[i]) HP[tot++] = i;
    FOR(i,0,tot-1) {
        if (HP[i] > sqrt(MAXN)) break;
        FOR(j, i, tot-1) {
            long long p = (long long)HP[i] * (long long)HP[j];
            if (p > MAXN) break;
            if ((p-1)%4 == 0 &&  p <= MAXN) sprime[p] = true;
        }
    }
    tot = 0;
    FOR(i,2, MAXN-1) if (sprime[i]) {
        HP[tot++] = i;
    }
}


bool Solve()
{
    int num;
    cin >> num;
    if (num == 0) return false;

    int *ans = lower_bound(HP, HP + tot, num);
    if (*ans > num) ans--;
 
    cout << num << " " << (ans - HP)+1 << "\n";
    return true;
}

int main()
{
    MakeSemiHPrime();
    while (Solve());
    return 0;
}

