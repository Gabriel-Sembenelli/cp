/*
https://usaco.guide/silver/intro-sorted-sets#problem-cses-1188

Sets, PURQ

I just did CSES 1163 Traffic Lights two times, one for each bit.
https://usaco.guide/silver/intro-sorted-sets#problem-cses-1163
*/
#include <bits/stdc++.h>
using namespace std;

//#define int     long long // a little faster, TL is tight for this one
#define sz(x)   (int)size(x)

void setIO(string file = "");

void solve(){
    string s; int m;
    cin >> s >> m;
    int n = sz(s);
    
    set<int> pos[2];        // Store all positions for each bit
    multiset<int> dist[2];  // Store all distances for each bit
    
    pos[0].insert({-1, n});         // Initializing positions
    pos[1].insert({-1, n});         //
    for(int i=0; i<n; ++i)          //
        pos[s[i] - '0'].insert(i);  //
    
    for(int d=0; d<2; ++d) // Initializing distances
        for(auto it = ++begin(pos[d]); it != end(pos[d]); ++it)
            dist[d].insert(*it - *prev(it));
    
    while(m--){
        int idx; cin >> idx; --idx; // 0-index
        int digit = s[idx] - '0';   // Find which bit we are changing
        auto it = pos[digit].find(idx);     // Find closest L and
        int L = *prev(it), R = *next(it);   // R bits of this type
        dist[digit].erase(dist[digit].find(idx - L)); // This bit lose this 
        dist[digit].erase(dist[digit].find(R - idx)); // distances
        dist[digit].insert(R - L);                    // And gain this
        pos[digit].erase(it);      // Also lose this position
        
        digit = !digit; // Now we look at the opposite bit structures
        s[idx] = '0' + digit; // Change the bit in string
        it = pos[digit].upper_bound(idx); // Find L and R opposite
        L = *prev(it), R = *it;           // bits around idx
        dist[digit].erase(dist[digit].find(R - L)); // Do the opposite
        dist[digit].insert({R - idx, idx - L});     // of before
        pos[digit].insert(idx);                     //
        
        // The answer is the maximum value at the end of the sets
        cout << max(*rbegin(dist[0]), *rbegin(dist[1])) - 1 << ' ';
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
