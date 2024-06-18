/*
https://usaco.guide/silver/intro-sorted-sets#problem-cses-1164

Sets, Implementation

Use two (multi)sets, one to store light positions and another to store distances
between them. Consider that initially we have only two lights, at 0 and x.
lights: {0, x}
distances: {x}
When a new light is added at position 'p', we find the closest light to its left
and closest to its right (B.Search on lights set), let's call its positions 'L'
and 'R'. This addition will transform the distance R-L into two distances,
R-p and p-L. After the changes, print the last value stored in distances set.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

void setIO(string file = "");


void solve(){
    int x, n; cin >> x >> n;
    set<int> lights;
    multiset<int> distances;
    lights.insert({0, x});
    distances.insert(x);
    while(n--){
        int p; cin >> p;
        auto it = lights.upper_bound(p);
        int R = *it, L = *(--it);
        distances.erase(distances.find(R-L));
        distances.insert({R - p, p - L});
        lights.insert(p);
        cout << *(--end(distances)) << ' ';
    }
    cout << '\n';
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
