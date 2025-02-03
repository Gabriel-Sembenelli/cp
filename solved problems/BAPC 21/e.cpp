#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int sz_chunk = 10;

string lcs(string s, string t){
    int n = sz(s);
    s = "." + s; t = "." + t;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(s[i] == t[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string re(dp[n][n], '.');
    for(int i = n, j = n, k = sz(re) - 1; k >= 0;){
        if(s[i] == t[j]) re[k--] = s[i--], j--;
        else if(dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    return re;
}

signed main(){
    int n; cin >> n;
    string s, t, ans = ""; cin >> s >> t;
    for(int i = 0; i < n; i += sz_chunk){
        int tam = min(sz_chunk, n - i);
        ans += lcs(s.substr(i, tam), t.substr(i, tam));
    }
    cout << ans << '\n';
    return 0;
}
