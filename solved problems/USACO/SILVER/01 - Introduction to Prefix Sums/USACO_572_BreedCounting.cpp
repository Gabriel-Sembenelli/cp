/*
Direct application of Prefix Sums
Construct a P.Sum for each breed
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> pSum(3, vector<int>(N+1));
    for(int i=1; i<=N; i++){
        int id; cin >> id;
        id--; // 0-indexing
        pSum[id][i]++;
        
        pSum[0][i] += pSum[0][i-1];
        pSum[1][i] += pSum[1][i-1];
        pSum[2][i] += pSum[2][i-1];
    }
    while(Q--){
        int l, r; cin >> l >> r;
        for(int id=0; id<3; id++)
            cout << pSum[id][r] - pSum[id][l-1] << " \n"[id == 2];
    }
}

signed main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
