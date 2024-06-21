/*
https://cses.fi/problemset/task/1666/

Graph Traversal, Connected Components

Find all CCs (Connected Components). We will need connect them all.
To use the minimum number of edges, just connect the CCs in a line fashion.
If we have K CCs, we use K-1 edges.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 112345;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int at){
    visited[at] = 1;
    for(auto to:adj[at]) if(!visited[to])
        dfs(to);
}

void solve(){
    int n, m; cin >> n >> m;
    
    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> comp;
    for(int v=1; v<=n; ++v) if(!visited[v]){
        comp.push_back(v);
        dfs(v);
    }
    
    cout << sz(comp) - 1 << '\n';
    for(int i=0; i<sz(comp)-1; ++i)
        cout << comp[i] << ' ' << comp[i+1] << '\n';
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
        (void)!freopen((file + ".in").c_str(), "r", stdin);
        (void)!freopen((file + ".out").c_str(), "w", stdout);
    }
}
