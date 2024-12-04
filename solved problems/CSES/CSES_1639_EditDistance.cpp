/*
DP

References:
[DPV] Section 6.3
http://algorithmics.lsi.upc.edu/docs/Dasgupta-Papadimitriou-Vazirani.pdf#page=165
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

const int MAXN = 5123;
int dp[MAXN][MAXN]{};

void solve(){
    string S, T; cin >> S >> T;
    int n = sz(S), m = sz(T);
    S = "." + S; // 1-indexing
    T = "." + T; //
    for(int i = 0; i <= n; ++i) dp[i][0] = i;
    for(int j = 0; j <= m; ++j) dp[0][j] = j;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = min({1 + dp[i-1][j],
                            1 + dp[i][j-1],
                            (S[i] != T[j]) + dp[i-1][j-1]});
        }
    }
    cout << dp[n][m] << '\n';
    //cout << "\t"; for(auto c : T) cout << c << '\t'; cout << '\n'; for(int i=0; i<=n; ++i){ cout << S[i] << '\t'; for(int j=0; j<=m; ++j) cout << dp[i][j] << '\t'; cout << '\n'; }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
