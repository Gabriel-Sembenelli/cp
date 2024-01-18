/*
Take some time to compare the wrong lineup with the sorted lineup.

Note that the answer is the number of differences between them - 1 (if there are
any).
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    int ans = 0;
    
    vector<int> orig(N);
    for(auto &e:orig) cin >> e;
    
    vector<int> srtd = orig;
    sort(begin(srtd), end(srtd));
    
    for(int i=0; i<N; i++)
        ans += (orig[i] != srtd[i]);
    
    cout << (ans > 0 ? ans-1 : 0) << '\n';
}

signed main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
