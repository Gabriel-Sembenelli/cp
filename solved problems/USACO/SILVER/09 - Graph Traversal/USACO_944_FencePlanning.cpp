/*
https://usaco.guide/silver/graph-traversal#problem-usaco-944

Graph Traversal, Connected Components, Geometry

For each CC (Connected Component), find the lowest/highest X/Y coordinates. The
min perimeter for this CC can be directly calculated from this information.
If we call the boundaries loX, hiX, loY, hiY. The minimum fence will have sides
(hiX - loX) and (hiY - loY).
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 112345;
const int INF = 1e9;

int loX, hiX, loY, hiY;
int X[MAXN], Y[MAXN], visited[MAXN];
vector<int> adj[MAXN];

void dfs(int at){
    loX = min(loX, X[at]);
    hiX = max(hiX, X[at]);
    loY = min(loY, Y[at]);
    hiY = max(hiY, Y[at]);
    visited[at] = 1;
    for(auto to:adj[at]) if(!visited[to])
        dfs(to);
}

void solve(){
    int N, M; cin >> N >> M;
    
    for(int c=1; c<=N; ++c) cin >> X[c] >> Y[c];
    
    while(M--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = INF;
    for(int c=1; c<=N; ++c) if(!visited[c]){
        loX = INF;
        hiX = -INF;
        loY = INF;
        hiY = -INF;
        dfs(c);
        ans = min(ans, 2*(hiX - loX + hiY - loY));
    }
    cout << ans << '\n';
}

signed main(){
    setIO("fenceplan");
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
