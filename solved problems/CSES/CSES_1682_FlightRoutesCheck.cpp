/*
https://usaco.guide/silver/graph-traversal#problem-cses-1682

Directed Graphs, Strongly Connected Components.

I used Kosaraju's algorithm for SCCs (Strongly Connected Components).
If there is only 1 SSC, print YES,
else, print two vertices in different SCCs.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 112345;
int visited[MAXN], components=0;
vector<int> order, adj1[MAXN], adj2[MAXN];

void dfs1(int at){
    visited[at] = 1;
    for(auto to:adj1[at]) if(!visited[to])
        dfs1(to);
    order.push_back(at);
}

void dfs2(int at){
    visited[at] = 1;
    for(auto to:adj2[at]) if(!visited[to])
        dfs2(to);
}

void solve(){
    int n, m; cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int v=1; v<=n; ++v) if(!visited[v])
        dfs1(v);
    
    reverse(all(order));
    fill_n(visited, n+1, 0);
    
    for(auto v:order) if(!visited[v]){
        ++components;
        if(components == 2){
            cout << "NO\n";
            cout << v << ' ' << order[0] << '\n';
            return;
        }
        dfs2(v);
    }
    cout << "YES\n";
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
