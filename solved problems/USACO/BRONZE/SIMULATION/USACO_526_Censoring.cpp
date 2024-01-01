#include <bits/stdc++.h>
using namespace std;

// iteratively constructs answer from S and
// erase every occurrence of T when encountered,
// like a stack
void solve(){
    string s, t, ans; cin >> s >> t;
    for(auto c:s){
        ans.push_back(c);
        if(size(ans) < size(t)) continue;
        int sz = size(t);
        int ini = size(ans) - sz;
        if(ans.substr(ini, sz) == t)
            ans.erase(ini, sz);
    }
    for(auto c:ans)
        cout << c;
    cout << '\n';
}

signed main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 