/*
Problema:
https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

Tema:
DP com recover da resposta

Referência:
https://www.youtube.com/watch?v=IHuZAgKGM6Y&ab_channel=MaratonUSP
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 101;

vector<int> ans;
int n, m;
int a[N], b[N];
int memo[N][N];

int dp(int i, int j){
    if(i == n or j == m) return 0;
    
    int &dpm = memo[i][j];
    if(dpm != -1) return dpm;
    
    dpm = 0;
    if(a[i] == b[j]) dpm = max(dpm, 1 + dp(i+1, j+1));
    dpm = max({dpm, dp(i+1, j), dp(i, j+1)});
    
    return dpm;
}

void recover(int i, int j){
    if(i == n or j == m) return;
    
    int alt1, alt2, alt3 = -1;
    alt1 = dp(i+1, j);
    alt2 = dp(i, j+1);
    if(a[i] == b[j]) alt3 = 1 + dp(i+1, j+1);
    
    if(max({alt1, alt2, alt3}) == alt3){
        ans.push_back(a[i]);
        recover(i+1, j+1);
    }else if(alt1 > alt2){
        recover(i+1, j);
    }else{
        recover(i, j+1);
    }
}

void solve(){
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    recover(0,0);
    
    for(auto e:ans) cout << e << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; for(int i=1; i<=t; i++)
    solve();
    return 0;
}
