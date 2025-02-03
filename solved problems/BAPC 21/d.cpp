#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, -INF));
    vector<int> p(n); for(auto& e : p) cin >> e;
    for(int j = 1; j < n; ++j)
        dp[n - 1][j] = p[n - 1];
    for(int X = n - 2; X >= 0; --X)
        for(int J = 1; J < n; ++J){
            auto& dpm = dp[X][J];
            dpm = dp[X][J - 1];
            if(X + J < n) dpm = max(dpm, p[X] + dp[X + J][J]);
        }
    //for(int x = 0; x < n; ++x){ for(int j = 1; j < n; ++j) cout << dp[x][j] << ' '; cout << '\n'; }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
