/*
Link:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1204

Tema:
Geometry

Takeouts:
Da pra resolver de 2 maneiras:
1: Busca ternária nos segmentos minimizando distância
2: Fórmula usando projeção ortogonal de M sobre os segmentos
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
#define X first
#define Y second

#define dbgp(P) cout<<#P<<"=("<<P.X<<","<<P.Y<<") "

const double EPS = 1e-9;
point M;
double ans = 1e300;
point ptans;

double dist(point a, point b){
    return sqrt((a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y));
}

// SOL 1: using ternary search -----------------------------------------

// ternary search to find min dist from 'M' to 'ab' segment
void bt(point a, point b){
    while(dist(a,b) > EPS){
        point m1 = {a.X + (b.X-a.X)/3.0, a.Y + (b.Y-a.Y)/3.0};
        point m2 = {a.X + 2.0*(b.X-a.X)/3.0, a.Y + 2.0*(b.Y-a.Y)/3.0};
        if(dist(m1, M) < dist(m2, M)) b = m2;
        else a = m1;
    }
    if(dist(a,M) < ans){
        ptans = a;
        ans = dist(a,M);
    }
}

void solve(){
    ans = 1e300;
    int n; cin >> n;
    vector<point> pts(n+1);
    for(auto &p:pts)
        cin >> p.X >> p.Y;
    //dbgp(M);for(auto p:pts)dbgp(p);cout<<'\n';
    for(int i=0; i<n; i++)
        bt(pts[i], pts[i+1]);
    cout << ptans.X << '\n' << ptans.Y << '\n';
}

// SOL 2: using orthogonal projection ----------------------------------

// orthogonal projection to find min dist from 'M' to 'ab' segment
void dist_M_seg(point a, point b){
    // The idea is to project u onto v
    // Proj(u,v) = (<u,v>/|v|^2)v = (alpha)v
    point u = {M.X - a.X, M.Y - a.Y};   // u = M-a
    point v = {b.X - a.X, b.Y - a.Y};   // v = b-a
    point proj;
    double alpha = (u.X*v.X + u.Y*v.Y)/(v.X*v.X + v.Y*v.Y);
    
    if(alpha < 0) proj = a;      // proj   a----b
    else if(alpha > 1) proj = b; // a----b   proj
    else proj = {a.X + alpha * v.X, a.Y + alpha * v.Y};
    
    if(dist(proj, M) < ans){
        ans = dist(proj, M);
        ptans = proj;
    }
}

void solve2(){
    ans = 1e300;
    int n; cin >> n;
    vector<point> pts(n+1);
    for(auto &p:pts)
        cin >> p.X >> p.Y;
    for(int i=0; i<n; i++)
        dist_M_seg(pts[i], pts[i+1]);
    cout << ptans.X << '\n' << ptans.Y << '\n';
}

// ---------------------------------------------------------------------

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << setprecision(4) << fixed;
    while(cin >> M.X >> M.Y)
        solve();
    return 0;
}

/*
remember to reset globals on multiple testcases! (memo, ans, ...)
*/
