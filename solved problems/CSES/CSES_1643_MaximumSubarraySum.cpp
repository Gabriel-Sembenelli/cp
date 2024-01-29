/*
This problem can be solved in at least two ways:
1 - Kadane's Algorithm
2 - Prefix Sum
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

// Kadane's Algorithm
void solve(){
    int n; cin >> n;
    int curr, ans;
    curr = ans = -INF;
    while(n--){
        int a; cin >> a;
        curr = max(curr + a, a); // Take 'a' or start a new subarray with 'a'
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}

// Prefix sum
void solve2(){
    int n; cin >> n;
    int ans, psum[n+1]{}, pmin[n+1]{};
    ans = -INF, psum[0] = pmin[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> psum[i];
        psum[i] += psum[i-1];
        pmin[i] = min(pmin[i-1], psum[i]);
        ans = max(ans, psum[i] - pmin[i-1]);
    }
    cout << ans << '\n';
} // More details at https://usaco.guide/silver/more-prefix-sums#solution---max-subarray-sum

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}