/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=41&page=show_problem&problem=1251

Geometry
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;
#define X first
#define Y second

double dist(point p, point q){
    return sqrt((p.X - q.X)*(p.X - q.X) + (p.Y - q.Y)*(p.Y - q.Y));
}

void solve(){
    int n;
    cout << setprecision(3) << fixed;
    while(cin >> n){
        bool flag = false;
        point gop, dog;
        cin >> gop.X >> gop.Y >> dog.X >> dog.Y;
        for(int i=0; i<n; i++){
            point hole;
            cin >> hole.X >> hole.Y;
            double dist_gop = dist(gop, hole);
            double dist_dog = dist(dog, hole);
            if(!flag and 2*dist_gop <= dist_dog){
                cout << "The gopher can escape through the hole at ("
                << hole.X << "," << hole.Y << ").\n";
                flag = true;
            }
        }
        if(!flag) cout << "The gopher cannot escape.\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; for(int i=1; i<=t; i++)
    solve();
    return 0;
}
