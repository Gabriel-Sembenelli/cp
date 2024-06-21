/*
https://cses.fi/problemset/task/1668/

Graph Traversal, Bicolor/Bipartite Graph

For each component we find, we run a traversal to bicolor it. The first node
is colored 1, its neighbours 2, its neighbours 1 and so on.
If we find neighbours with same color, print IMPOSSIBLE.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 112345;
vector<int> adj[MAXN];
int color[MAXN];

void solve(){
    int n, m; cin >> n >> m;
    
    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int v=1; v<=n; ++v) if(!color[v]){ // For each component
        queue<int> q;
        q.push(v);
        color[v] = 1;
        while(!q.empty()){ // Do a BFS to bicolor it
            int t = q.front(); q.pop();
            for(auto u:adj[t]){
                if(!color[u]){
                    color[u] = 3 - color[t]; // opposite color
                    q.push(u);
                }else if(color[u] == color[t]){
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }
        }
    }
    
    for(int i=1; i<=n; ++i) cout << color[i] << ' ';
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
        (void)!freopen((file + ".in").c_str(), "r", stdin);
        (void)!freopen((file + ".out").c_str(), "w", stdout);
    }
}
