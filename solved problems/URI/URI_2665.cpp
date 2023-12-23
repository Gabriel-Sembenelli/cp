/*
Geometry

https://www.beecrowd.com.br/judge/pt/problems/view/2665

Takeouts:
- Guloso em maior altura não funciona nesse problema, então o melhor é
uma DP de baixo pra cima.
- Poderia ter só invertido os defines, pra não ter que criar uma
função 'comp', i.e., fazer X=second e Y=first.
*/
#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef pair<int, int> point;
typedef vector<point> polygon;
#define X first
#define Y second

int ccw(point a, point b, point c){
    int det = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    if(det > 0) return 1;   // ccw
    if(det < 0) return -1;  // cw
    return 0;               // collinear
}

bool is_inside(point a, polygon P){
    int n = sz(P);
    for(int i=0; i<n; i++)
        if(ccw(P[i], P[(i+1)%n], a) == -1)
            return false;
    return true;
}

bool comp(point a, point b){
    if(a.Y == b.Y) return (a.X < b.X);
    return (a.Y < b.Y);
}

void solve(){
    int n, xa, xb; cin >> n >> xa >> xb;
    polygon P(3);
    P[0] = {xa, 0};
    P[1] = {xb, 0};
    polygon pts(n);
    for(int i=0; i<n; i++)
        cin >> pts[i].X >> pts[i].Y;
    sort(pts.begin(), pts.end(), comp);
    vector<int> best(n);
    int ans = 0;
    for(int i=0; i<n; i++){
        best[i] = 1;
        P[2] = pts[i];
        for(int j=0; j<n; j++){
            if(j == i) continue;
            if(is_inside(pts[j], P))
                best[i] = max(best[i], best[j]+1);
        }
        ans = max(ans, best[i]);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
