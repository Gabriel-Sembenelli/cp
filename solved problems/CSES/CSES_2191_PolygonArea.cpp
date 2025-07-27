#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()

using T = int;

struct Pt{
    T x, y;
    Pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    T    operator ^  (const Pt p) const { return x * p.y - y * p.x; }
    friend istream& operator >> (istream& in, Pt& p){ return in >> p.x >> p.y; }
};

using Polygon = vector<Pt>;

// Shoelace Formula to compute the area of a generic polygon
T area_polygon(Polygon& P){
    int n = sz(P);
    T re = 0;
    for(int i = 0; i < n; ++i)
        re += (P[i] ^ P[(i + 1) % n]);
    return abs(re); // 2 * area
}

void solve(){
    int n; cin >> n;
    Polygon P(n);
    for(Pt& a : P) cin >> a;
    cout << area_polygon(P) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}