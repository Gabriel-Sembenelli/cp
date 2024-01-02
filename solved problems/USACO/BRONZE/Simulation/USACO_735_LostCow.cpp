#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y; cin >> x >> y;
    int pos = x, xf = 1, step = 1, ans = 0;
    while(pos != y){
        while(pos != x+xf and pos != y){
            pos += step;
            ans++;
        }
        xf *= -2;   // duplicate and change direction;
        step *= -1; //
    }
    cout << ans << '\n';
}

signed main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 