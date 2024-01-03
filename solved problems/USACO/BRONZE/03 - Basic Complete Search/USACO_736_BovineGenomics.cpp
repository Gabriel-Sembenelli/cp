#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, M; cin >> N >> M;
    string spotty[N], plain[N];
    for(int i=0; i<N; i++) cin >> spotty[i];
    for(int i=0; i<N; i++) cin >> plain[i];
    
    int ans = 0;
    for(int p=0; p<M; p++){                     // for each position
        bool explain = true;
        for(int i=0; i<N; i++)                  // compare each spotty
            for(int j=0; j<N; j++)              // with each plain
                if(spotty[i][p] == plain[j][p]) // check consistency
                    explain = false;
        ans += explain;
    }
    cout << ans << '\n';
}

signed main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}