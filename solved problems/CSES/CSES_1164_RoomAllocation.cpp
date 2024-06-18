/*
https://usaco.guide/silver/intro-sorted-sets#problem-cses-1164

PriorityQueue, Simulation

The Internal Sol. is well explained and very similar to this.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

void setIO(string file = "");

#define A first.first
#define B first.second
#define idx second

#define T first
#define room second

void solve(){
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> cust(n);
    for(int i=0; i<n; ++i){
        cin >> cust[i].A >> cust[i].B;
        cust[i].idx = i;
    }
    sort(all(cust));
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    int qrooms = 1;
    
    vector<int> ans(n);
    for(auto &c:cust){
        pair<int,int> top = pq.top();
        if(-top.T <= c.A){
            ans[c.idx] = top.room;
            pq.push({-(c.B + 1), top.room});
            pq.pop();
        }else{
            ++qrooms;
            ans[c.idx] = qrooms;
            pq.push({-(c.B + 1), qrooms});
        }
    }
    cout << qrooms << '\n';
    for(auto e:ans) cout << e << ' ';
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
