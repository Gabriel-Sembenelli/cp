/*
Link:
https://br.spoj.com/problems/CANUBIS/

Tema:
Geometry

Takeouts:
- Naive passa, só é chatinho de codar.
- Precisa dar uma escovada de bit nos loops aninhados, i.e.,
ao invés de:
"for(i,0,n) for(j,0,n) for(k,0,n)"
fazer:
"for(i,0,n) for(j,i,n) for(k,j,n)"
deixa 6x mais rápido
- Fazer point com pair(pair) ou com struct é bem mais rápido do que
fazer com vector ou com tuple
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<pair<int,int>,int> point;
#define X first.first
#define Y first.second
#define Z second

int dot(point a, point b){return a.X*b.X + a.Y*b.Y + a.Z*b.Z;}

int norm(point a){return dot(a,a);}

point cross(point u, point v){
    return {{   u.Y * v.Z - u.Z * v.Y   ,
                u.Z * v.X - u.X * v.Z   },
                u.X * v.Y - u.Y * v.X   };
}

bool collinear(point a, point b, point c){
    b = {{b.X-a.X, b.Y-a.Y}, b.Z-a.Z};
    c = {{c.X-a.X, c.Y-a.Y}, c.Z-a.Z};
    return (norm(cross(b,c)) == 0);
}

// is 'p' in plane def by 'a','b','c'?
bool in_plane(point p, point a, point b, point c){
    b = {{b.X-a.X, b.Y-a.Y}, b.Z-a.Z};  // ab vector
    c = {{c.X-a.X, c.Y-a.Y}, c.Z-a.Z};  // ac vector
    point N = cross(b,c);   // Ax+By+Cz=D, where (A,B,C)=(N.x, N.y, N.z)
    return(dot(N, a) == dot(N, p));
}

void solve(){
    int n; cin >> n;
    vector<point> pts(n);
    for(int i=0; i<n; i++){
        cin >> pts[i].X >> pts[i].Y >> pts[i].Z;
    }
    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(collinear(pts[i], pts[j], pts[k])) continue;
                int aux = 0;
                for(int l=0; l<n; l++){
                    if(in_plane(pts[l], pts[i], pts[j], pts[k])){
                        aux++;
                    }
                }
                ans = max(ans, aux);
            }
        }
    }
    if(ans == -1) ans = n; // every point triplet was collinear
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
