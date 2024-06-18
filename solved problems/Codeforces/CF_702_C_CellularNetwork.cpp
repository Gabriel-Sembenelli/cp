/*
https://usaco.guide/silver/intro-sorted-sets#problem-cf-702C

Sortings, Sets, Binary Search

For each city, find the two closest towers (if possible) using Bin.Search,
keep the distance of the closest one. The answer is the maximum among all
those distances.

Similar to "Vanya and Lanterns"
https://codeforces.com/problemset/problem/492/B
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

void setIO(string file = "");


void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    sort(all(b));
    b.resize(unique(all(b)) - begin(b));
    m = sz(b);
    int ans = 0;
    for(auto x:a){
        // Finding closest tower to the right
        int idx = upper_bound(all(b), x) - begin(b);
        // There is no tower on the right
        if(idx == m) --idx;
        int dist = abs(x - b[idx]);
        // Comparing with the closest tower to the left (if possible)
        if(idx > 0) dist = min(dist, abs(x - b[idx-1]));
        ans = max(ans, dist);
    }
    cout << ans << '\n';
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
