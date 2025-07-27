#include <bits/stdc++.h>
using namespace std;

#define int long long

using T = int;

struct Pt{
    T x, y;
    Pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Pt   operator -  (const Pt p) const { return Pt(x - p.x, y - p.y); }
    T    operator ^  (const Pt p) const { return x * p.y - y * p.x; }
    friend istream& operator >> (istream& in, Pt& p){ return in >> p.x >> p.y; }
};

// does the path a,b,c makes a counter-clockwise curve?
string ccw(Pt a, Pt b, Pt c){
    T det = (b - a) ^ (c - a);
    if(det == 0) return "TOUCH"; // collinear
    if(det >  0) return "LEFT";  // ccw
    return              "RIGHT"; // cw
}

void solve(){
    Pt p1, p2, p3; cin >> p1 >> p2 >> p3;
    cout << ccw(p1, p2, p3) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--)
        solve();
    return 0;
}