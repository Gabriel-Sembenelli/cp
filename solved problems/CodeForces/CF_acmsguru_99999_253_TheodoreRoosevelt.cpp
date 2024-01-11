/*
Link:
https://codeforces.com/problemsets/acmsguru/problem/99999/253

Tema:
Geometry

Tekeouts:
Constraints ruins. Pelo enunciado, O(N*M) não passaria
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define int long long

typedef pair<int, int> point;
#define X first
#define Y second
typedef vector<point> polygon;

bool ccw(point a, point b, point c){
    b = {b.X - a.X, b.Y - a.Y};
    c = {c.X - a.X, c.Y - a.Y};
    return (b.X*c.Y - b.Y*c.X >= 0);
}

bool is_inside(point q, polygon P){
    int n = sz(P);
    for(int i=0; i<n; i++)
        if(!ccw(P[i], P[(i+1)%n], q))
            return false;
    return true;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    
    polygon region(n);
    for(auto &[x,y]:region)
        cin >> x >> y;
    
    int hits = 0;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        point rocket = {x, y};
        hits += is_inside(rocket, region);
    }
    
    if(hits >= k) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
