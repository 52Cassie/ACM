#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for (int i = a; i < b; i++)
using namespace std;

int Ys, Ms, Ye, Me, tot_day, ans1, ans2;

bool IsLeapYear(int Year)
{
    if (Year < 1582) return Year % 4 == 0;
    else {
        if (Year == 1700) return true;
        if (Year % 100 == 0) return Year % 400 == 0;
        return Year % 4 == 0;
    }
}

int DayOfMonth(int Year, int Month) {
    int LeapMonth[] = {1, 3, 5, 7, 8, 10, 12};
    if (Year == 1752 && Month == 9) return 19;
    if (Month == 2) return IsLeapYear(Year) ? 29 : 28;
    FOR(i, 0, 7) if (Month == LeapMonth[i]) return 31;
    return 30;
}

int DayOfWeek(int tot)
{
    return (tot % 7 + 5) % 7;
}

void Solve()
{
    cin >> Ys >> Ms >> Ye >> Me;
    
    ans1 = ans2 = 0;
    int M = 1, Y = 1;
    tot_day = 1;

    while (M != Ms || Y != Ys) {
        tot_day += DayOfMonth(Y, M);
        if (M == 12) {Y++; M = 1;}
        else M++;
    }

    while (true) {
        if (DayOfWeek(tot_day) == 0 || DayOfWeek(tot_day) == 6 || DayOfWeek(tot_day) == 1) ans1++;
        tot_day += DayOfMonth(Ys, Ms) - 1;
        if (DayOfWeek(tot_day) == 0 || DayOfWeek(tot_day) == 6 || DayOfWeek(tot_day) == 5) ans2++;
        tot_day += 1;
        if (Ms == Me && Ys == Ye) break;
        if (Ms == 12) { Ms = 1; Ys++; }
        else Ms++;
    }
    cout << ans2 << " " << ans1 << "\n";
}

int main()
{
    int T;
    cin >> T;
    FOR(i,0,T) Solve();
}
