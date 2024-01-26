/*
Prefix Sum with a bit of Modular Arithmetic.

I essentially followed the same idea of this video: (solved before watching)
https://www.youtube.com/watch?v=wXNhLjiuTgw

For each remainder mod 7, find the longest prefix sum with it.
Do the same for the smaller prefixes.
The pair with the biggest difference gives the answer.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, prefix[50001], last[7];

void solve(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        prefix[i] %= 7;
        last[prefix[i]] = i;
    }
    int ans = 0;
    for(int i=0; i<=N; i++)
        ans = max(ans, last[prefix[i]] - i);
    cout << ans << '\n';
}

signed main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
