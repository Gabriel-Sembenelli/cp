/*
https://usaco.guide/bronze/intro-graphs#problem-usaco-916

Graph, AdHoc

Abstract to a problem of painting vertices in a graph.
Iterate vertices 1..N trying to paint each one with
the first color that wasn't used by its neighbors.
After painting the vertex, mark this color as used for
all its neighbors.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    vector<vector<bool>> used(N+1, vector<bool>(5));
    vector<int> color(N+1);

    while(M--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int at=1; at<=N; ++at){ // Iterate 1..N increasing to get smallest answer
        int col = 1;
        while(used[at][col]) ++col;             // Find first unused color
        color[at] = col;                        // Paintint the vertex
        for(auto to:adj[at]) used[to][col] = 1; // Marking its neighbors
    }

    for(int i=1; i<=N; ++i) cout << color[i];
    cout << '\n';
}

signed main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin >> t; while(t--)
    solve();
}