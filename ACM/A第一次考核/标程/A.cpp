#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define MAXN 10005
#define ld  double
using namespace std;

ld S[MAXN], sum;
const ld PI = acos(-1.0);
int N, F;

bool Check(ld num)
{
    int cnt = 0;
    FOR(i,0,N) {
        cnt += (int) (S[i] / num);
        if (cnt >= (F + 1)) return true;
    }
    return false;
}

void Solve()
{
    scanf("%d %d", &N, &F);
    sum = 0.0;
    FOR(i,0,N) {
        ld r;
        scanf("%lf", &r);
        S[i] = PI * r * r;
        if (S[i] > sum) sum = S[i];
    }
    ld l = 0, r = sum;

    ld mid;
    while (r - l > EPS) {
        mid = (r + l) / 2.0;
        if (Check(mid)) l = mid;
        else r = mid;
    }
    printf("%.4f\n", mid);
}

int main()
{
    int T;
    scanf("%d", &T);
    FOR(i,0,T) Solve();
}
