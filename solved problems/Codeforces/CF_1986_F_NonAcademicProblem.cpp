/*
https://codeforces.com/contest/1986/problem/F

Graphs, Graph Traversal, Finding Bridges

Only bridges/cut-edges are relevant to the question, since other edges cannot
change the initial answer.
Once you cut off a bridge, the graph is split into two components. If a
component has 'q' nodes, the smaller node can reach all other q-1 nodes, the
second smaller can reach q-2 and so on. Thus, we have (q choose 2) of such
pairs.
So, start with the answer as (n choose 2), since the initial graph is connected,
and for each bridge, find how many nodes are left in each component, I called it
'q' and 'q2', and make ans = min(ans, (q choose 2) + (q2 choose 2))
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int MAXN = 212345;
vector<vector<int>> adj;
int tin[MAXN], low[MAXN], visited[MAXN], w[MAXN];
int timer, n, m, ans;

void dfs(int at, int from){
    visited[at] = 1;
    tin[at] = low[at] = ++timer;
    w[at] = 1;
    for(auto to:adj[at]){
        if(!visited[to]){
            dfs(to, at);
            w[at] += w[to];
            low[at] = min(low[at], low[to]);
            if(low[to] == tin[to]){ // at--to is a cut-edge
                int q = w[to];
                int q2 = n - q;
                ans = min(ans, q * (q - 1) + q2 * (q2 - 1));
            }
        }else if(to != from)
            low[at] = min(low[at], tin[to]);
    }
}

void solve(){
    cin >> n >> m;
    ans = n * (n - 1);
    fill_n(tin, n+1, 0);
    fill_n(low, n+1, 0);
    fill_n(visited, n+1, 0);
    timer = 0;
    adj = vector<vector<int>>(n+1);
    
    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    cout << ans / 2 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
