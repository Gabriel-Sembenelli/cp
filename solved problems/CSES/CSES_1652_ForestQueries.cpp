/*
Direct application of "2D Prefix Sum"
More details at https://usaco.guide/silver/more-prefix-sums#2d-prefix-sums
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    int psum[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c; cin >> c;
            psum[i][j] = psum[i-1][j] + psum[i][j-1]
                         - psum[i-1][j-1] + (c == '*');
        }
    }
    while(q--){
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
        cout << psum[i2][j2] - psum[i2][j1-1]
                - psum[i1-1][j2] + psum[i1-1][j1-1] << '\n';
    }
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}