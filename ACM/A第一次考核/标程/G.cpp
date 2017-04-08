#include <iostream>
#include <cstdio>
#include <string>

#define MAXN 1004

using namespace std;

int N, a[MAXN], step;

int clockwise(int n, int s)
{
    return (n + s) % N;
}

int uclockwise(int n, int s)
{
    int ret = (n - s) % N;
    if (ret < 0) ret += N;
    return ret;
}

bool Solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    while (a[0] != 0) {
        a[0] = (a[0] + 1) % N;
        step++;
    }

    for (int i = 1; i < N; i++) {
        if (i % 2)
            if (uclockwise(a[i], step) != i) return false;
        if (i % 2 == 0)
            if (clockwise(a[i], step) != i) return false;
    }
    return true;
}
int main()
{
    if (Solve()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
