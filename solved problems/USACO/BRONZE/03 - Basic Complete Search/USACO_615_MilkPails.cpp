#include <bits/stdc++.h>
using namespace std;

/*
Try to pour 0*Y units and complete the rest with X pours
Try to pour 1*Y units and complete the rest with X pours
Try to pour 2*Y units and complete the rest with X pours
...
Until n*Y exceeds M
*/
void solve(){
    int X, Y, M; cin >> X >> Y >> M;
    int ans = 0;
    for(int i=0; Y*i <= M; i++)
        ans = max(ans, Y*i + ((M - Y*i) / X) * X);
    cout << ans << '\n';
}

signed main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}