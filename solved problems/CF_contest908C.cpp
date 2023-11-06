/*
https://codeforces.com/contest/908/problem/C

Geometry

Bem basiquinho, implementação direta
*/

#include <bits/stdc++.h>
using namespace std;

void check(int x1, double y1, int x2, double &y2, int r){
    int dist = abs(x1-x2);
    if(dist > 2*r) return;
    double h = sqrt(4.0*r*r - dist*dist);
    y2 = max(y2, y1 + h);
}

void solve(){
    int n, r; cin >> n >> r;
    int x[n];
    double y[n];
    for(int i=0; i<n; i++){
        cin >> x[i];
        y[i] = r;
        for(int j=i-1; j>=0; j--)
            check(x[j], y[j], x[i], y[i], r);
        cout << setprecision(10) << fixed << y[i] << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
