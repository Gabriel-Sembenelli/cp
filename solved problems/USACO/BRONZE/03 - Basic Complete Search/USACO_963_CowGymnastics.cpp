#include <bits/stdc++.h>
using namespace std;

//rank[c][k] := which rank c-th cow got on k-th session
void solve(){
    int K, N; cin >> K >> N;
    int rank[N+1][K+1]; // 1-indexed
    for(int k=1; k<=K; k++)
        for(int r=1; r<=N; r++){
            int cow; cin >> cow;
            rank[cow][k] = r;
        }
    int ans = 0;
    for(int c1=1; c1<=N; c1++){     // iterate through every
        for(int c2=1; c2<=N; c2++){ // pair of cows
            if(c1 == c2) continue;
            bool consistent = true;
            for(int k=1; k<=K; k++) // check consistency
                if(rank[c1][k] < rank[c2][k])
                    consistent = false;
            ans += consistent;
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}