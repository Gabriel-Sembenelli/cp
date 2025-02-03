
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(X) ((int)(X).size())
#define all(X) (X).begin(),(X).end()

signed main(){
    int n; cin >> n;
    vector<pair<int,int>> st(n);
    for(auto &[s, t] : st) cin >> t;
    for(auto &[s, t] : st) cin >> s;
    sort(all(st));
    int ans = 0, sum_t = 0;
    for(auto [s, t] : st){
        if(s == -1) continue;
        sum_t += t;
        ans = max(ans, (sum_t + s - 1) / s); // max(ans, ceil(sum_t / s));
    }
    cout << ans << '\n';
    
    return 0;
}