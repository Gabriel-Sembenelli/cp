#include <bits/stdc++.h>
using namespace std;

#define int long long

using T = int;

struct Pt{
    T x, y;
    Pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Pt   operator -  (const Pt p) const { return Pt(x - p.x, y - p.y); }
    T    operator *  (const Pt p) const { return x * p.x + y * p.y; }
    T    operator ^  (const Pt p) const { return x * p.y - y * p.x; }
    friend istream& operator >> (istream& in, Pt& p){ return in >> p.x >> p.y; }
};

// does the path a,b,c makes a counter-clockwise curve?
int ccw(Pt a, Pt b, Pt c){
    T det = (b - a) ^ (c - a);
    if(det == 0) return 0; // collinear
    if(det > 0) return 1;  // ccw
    return -1;             // cw
}

bool inseg(Pt p, Pt a, Pt b){ // The point p is in segment ab
    return ((a - p)^(b - p)) == 0 && ((a - p)*(b - p)) <= 0;
}

bool intersect(Pt a, Pt b, Pt c, Pt d){ // The segments ab and cd intersect
    if(inseg(a, c, d) || inseg(b, c, d) || inseg(c, a, b) || inseg(d, a, b))
        return true;
    return ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b);
}

void solve(){
    Pt a, b, c, d; cin >> a >> b >> c >> d;
    cout << (intersect(a, b, c, d) ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--)
        solve();
    return 0;
}