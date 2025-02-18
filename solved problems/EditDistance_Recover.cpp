/*
https://cses.fi/problemset/task/1639/

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
int dp[MAXN][MAXN]{}, s[MAXN][MAXN]{};
string x, y, edx, edy;

void recover(int i, int j){
    if(i == 0 and j == 0) return;
    if(s[i][j] == 1){
        recover(i-1, j);
        edx.push_back(x[i]);
        edy.push_back('-');
    }else if(s[i][j] == 2){
        recover(i, j-1);
        edx.push_back('-');
        edy.push_back(y[j]);
    }else{
        recover(i-1, j-1);
        edx.push_back(x[i]);
        edy.push_back(y[j]);
    }
}

void solve(){
    cin >> x >> y;
    int n = sz(x), m = sz(y);
    x = "." + x; // 1-indexing
    y = "." + y; //
    for(int i = 0; i <= n; ++i) dp[i][0] = i, s[i][0] = 1;
    for(int j = 0; j <= m; ++j) dp[0][j] = j, s[0][j] = 2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int alt1 = 1 + dp[i-1][j];                  // x[i] /  -
            int alt2 = 1 + dp[i][j-1];                  //  -   / y[j]
            int alt3 = (x[i] != y[j]) + dp[i-1][j-1];   // x[i] / y[j]
            int mn = min({alt1, alt2, alt3});
            dp[i][j] = mn;
            if(mn == alt1)      s[i][j] = 1;
            else if(mn == alt2) s[i][j] = 2;
            else                s[i][j] = 3;
        }
    }
    recover(n, m);
    cout << dp[n][m] << '\n' << edx << '\n' << edy << '\n';
    //cout << "\t"; for(auto c : y) cout << c << '\t'; cout << '\n'; for(int i=0; i<=n; ++i){ cout << x[i] << '\t'; for(int j=0; j<=m; ++j) cout << dp[i][j] << '\t'; cout << '\n'; }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}