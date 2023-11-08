/*
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2168

Geometry

Naive passa, só é chato de codar.
Pega par a par e gera todas as linhas possíveis. Depois passa ponto a
ponto e incrementa o contador de cada linha a qual ele pertence.
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(V) (int)(V).size()

const double EPS = 1e-9;

typedef pair<double, double> point;
#define X first
#define Y second

typedef pair<point, point> line;
#define P1 first
#define P2 second

double dist_pl(point p, line l){
    point a = l.P1;
    point b = l.P2;
    double num =
    abs( (b.Y - a.Y)*p.X - (b.X - a.X)*p.Y + b.X*a.Y - b.Y*a.X );
    double den =
    sqrt( (b.Y - a.Y)*(b.Y - a.Y) + (b.X - a.X)*(b.X - a.X) );
    return num / den;
}

void solve(int tc){
    int n; cin >> n;
    
    line lns[n][n];
    int best[n][n]; memset(best, 0, sizeof(best));
    
    cout << "Data set #" << tc << " contains ";
    
    set<point> spt;
    for(int i=0; i<n; i++){
        double x, y; cin >> x >> y;
        spt.insert({x,y});
    }
    vector<point> pts(spt.begin(), spt.end());
    n = sz(pts);
    if(n == 1){
        cout << "a single gnu.\n";
        return;
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            lns[i][j] = {pts[i], pts[j]};
    for(auto p:pts){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(dist_pl(p, lns[i][j]) < EPS) best[i][j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, best[i][j]);
        }
    }
    cout << n << " gnus, out of which a maximum of " << ans << " are aligned.\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; for(int i=1; i<=t; i++)
    solve(i);
    return 0;
}
