#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> limit(100), speed(100);
    int N, M; cin >> N >> M;
    int i=0;
    while(N--){
        int len, lim; cin >> len >> lim;
        while(len--)
            limit[i++] = lim;
    }
    i=0;
    while(M--){
        int len, spd; cin >> len >> spd;
        while(len--)
            speed[i++] = spd;
    }
    int exceed = 0;
    for(i=0; i<100; i++)
        exceed = max(exceed, speed[i] - limit[i]);
    cout << exceed << '\n';
}

signed main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 