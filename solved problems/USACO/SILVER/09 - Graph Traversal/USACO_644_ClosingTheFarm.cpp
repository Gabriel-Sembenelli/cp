/*
https://usaco.guide/silver/graph-traversal#problem-usaco-644

Graph Traversal, Connected Components

N ~ 1e3 so we can do a naive O(N^2) approach.
For each closed barn, do a traversal to see if all remaining barns are connected.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 3123;
vector<int> adj[MAXN];
bool visited[MAXN], open[MAXN];
int connected;

void dfs(int at){
    visited[at] = 1;
    ++connected;
    for(auto to:adj[at]) if(!visited[to] and open[to])
        dfs(to);
}

void solve(){
    int N, M; cin >> N >> M;
    while(M--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> perm(N); for(auto &barn:perm) cin >> barn;
    int s = perm.back(); // The last barn to be closed is a good starting point
    fill_n(open, N+1, 1);
    for(int i=0; i<N; ++i){
        connected = 0;
        fill_n(visited, N+1, 0);
        dfs(s);
        cout << (connected == N-i ? "YES\n" : "NO\n");
        open[perm[i]] = 0;
    }
}

signed main(){
    setIO("closing");
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
