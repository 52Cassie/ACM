#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;

double pi = acos(-1.0);             // 圆周率的表示
int T, n, f;
double b[10003];

int juge(double x)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += int(b[i] / x);
    }
    if (total>f)
        return 1;
    else
        return 0;
}

int main()
{
    double l, r, mid, rad;
    cin >> T;
    while (T--)
    {
        cin >> n >> f;
        double sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> rad;
            b[i] = rad*rad*pi;
            sum += b[i];
        }
        l = 0;
        double r = sum / (f + 1);
        while (r - l>0.0001)           // 此题精度小数点后四位
        {
            mid = (l + r) / 2;
            if (juge(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.4lf\n", mid);
    }
    return 0;
}