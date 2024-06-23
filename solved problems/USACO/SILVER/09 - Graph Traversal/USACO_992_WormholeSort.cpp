/*
https://usaco.guide/silver/graph-traversal#problem-usaco-992

Graphs, Binary Search, Connected Components, DSU

Do a B.Search on the minimum width.
For each test, define components for all cows and nodes using only edges that
satisfy minWidth <= edge.width.
It is possible to sort the cows <-> for all i, comp(ith cow) == comp(ith node)
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

const int MAXN = 112345;
int N, M, qComp;
int cowAt[MAXN], compCow[MAXN], compNode[MAXN];
vector<pair<int,int>> adj[MAXN]; // {to, width}

void dfs(int at, int minW){
    compNode[at] = qComp;
    compCow[cowAt[at]] = qComp;
    for(auto [to, w]:adj[at]) if(!compNode[to] and minW <= w)
        dfs(to, minW);
}

bool ok(int minW){
    fill_n(compCow, N+1, 0);
    fill_n(compNode, N+1, 0);
    qComp = 0;
    for(int v=1; v<=N; ++v) if(!compNode[v]){
        ++qComp;
        dfs(v, minW);
    }
    
    for(int i=1; i<=N; ++i) if(compCow[i] != compNode[i])
        return false;
    
    return true;
}

void solve(){
    cin >> N >> M;
    for(int cow=1; cow<=N; ++cow){
        int node; cin >> node;
        cowAt[node] = cow;
    }
    
    while(M--){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    int ans = 0;
    for(int step = 1e9 + 1; step; step /= 2)
        while(ans + step <= 1e9 + 1 and ok(ans + step))
            ans += step;
    
    cout << (ans > 1e9 ? -1LL : ans) << '\n';
}

signed main(){
    setIO("wormsort");
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
