/*
https://usaco.guide/bronze/intro-graphs#problem-usaco-941

Trees, AdHoc

This is just an implementation of Internal Sol. explanation.
I couldn't figure it all by myself.

I noticed the minimal impossible case:
pop1 A
pop2 B
pop3 A B
But wasn't sure if that was the only one.
Also, couldn't abstract to a problem of crossing sets.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)

void solve(){
    int N; cin >> N;
    map<string, vector<int>> mp;
    set<string> characteristics;
    for(int pop=0; pop<N; ++pop){
        int K; cin >> K;
        while(K--){
            string s; cin >> s;
            characteristics.insert(s);
            if(!mp.count(s)) mp[s].resize(N);
            mp[s][pop] = 1;
        }
    }
    
    for(auto c1:characteristics){       // For every pair of characteristics
        for(auto c2:characteristics){   //
            bool only1=0, only2=0, both=0;
            for(int pop=0; pop<N; ++pop){ // Check if they are crossing
                if(mp[c1][pop] and mp[c2][pop]) both = 1;
                else if(mp[c1][pop]) only1 = 1;
                else if(mp[c2][pop]) only2 = 1;
            }
            if(only1 and only2 and both){
                cout << "no\n";
                return;
            }
        }
    }
    cout << "yes\n";
}

void setIO(string file = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        auto i = freopen((file + ".in").c_str(), "r", stdin);
        auto o = freopen((file + ".out").c_str(), "w", stdout);
    }
}

signed main(){
    setIO("evolution");
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
