#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define MAXN 105
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
using namespace std;

struct Edge {
    int from, to;
    double w;
    Edge(){}
    Edge(int _from, int _to, double _w) {from = _from; to = _to; w = _w;}
};
struct Point {
    double x, y, z;
    Point(){}
    Point(double _x, double _y, double _z) {x = _x; y = _y; z = _z;}
};

struct Sphere {
    Point p;
    double r;
    Sphere(){}
    Sphere(const Point& _p, double _r) {p = _p; r = _r;}
} S[MAXN];

int n, father[MAXN];
vector<Edge> G;
Point C[MAXN];

bool cmp (const Edge& e1, const Edge& e2) {return e1.w < e2.w;} 
double dis(Point& p1, Point& p2) {return sqrt(pow(p2.x - p1.x, 2.0) + pow(p2.y - p1.y, 2.0) + pow(p2.z - p1.z, 2.0));} 
bool connected(Sphere& a, Sphere& b) {return fabs(a.r + b.r) >= dis(a.p, b.p);}
int GetFather(int i) { return father[i] == i ? i : GetFather(father[i]); }

bool Solve()
{
    fill(father, father + MAXN, 0);
    G.clear();

    cin >> n;
    if (n == 0) return false;
    FOR(i, 0, n) {
        double x,y,z,r;
        cin >> x >> y >> z >> r;
        S[i] = Sphere(Point(x,y,z), r);
        father[i] = i;
    }
    
    FOR(i,0,n) FOR(j,i+1,n)
        if (connected(S[i], S[j])) father[GetFather(j)] = GetFather(i);

    FOR(i,0,n) FOR(j,i+1,n) 
        if (GetFather(i) != GetFather(j)) 
            G.pb(Edge(i, j , dis(S[i].p, S[j].p) - fabs(S[i].r + S[j].r)));

    double ans = 0.0;
    sort(G.begin(), G.end(), cmp);
    FOR(i,0,G.size()) {
        int f1 = GetFather(G[i].to), f2 = GetFather(G[i].from);
        if (f1 != f2) {
            father[f2] = f1;
            ans += G[i].w;
        }
    }
    
    printf("%.3lf\n", ans);
    return true;
}

int main()
{
    while (Solve());
    return 0;
}
