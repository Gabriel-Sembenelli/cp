/*
Sets, Sorting
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long

void setIO(string file = "");


void solve(){
    int n, m; cin >> n >> m;
    multiset<int> h;
    while(n--){
        int x; cin >> x;
        h.insert(x);
    }
    while(m--){
        int x; cin >> x;
        auto it = h.upper_bound(x);
        if(it == begin(h)) cout << -1 << '\n';
        else cout << *(--it) << '\n', h.erase(it);
    }
}

signed main(){
    setIO();
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

void setIO(string file){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        auto i = freopen((file + ".in").c_str(), "r", stdin);
        auto o = freopen((file + ".out").c_str(), "w", stdout);
    }
}
