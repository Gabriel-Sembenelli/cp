/*
https://usaco.guide/silver/graph-traversal#problem-usaco-668

Implicit Graph, Graph Traversal, Geometry

If Dist(cow1, cow2) <= Power(cow1) then we can add an edge cow1 -> cow2.
(use squared quantities, no need to deal with doubles)
As N~1e2 we can do a O(N^3) approach, defining adjacencies for each pair of
cows in O(N^2), and then, for each starting cow, do a traversal to see how many
cows are reachable in O(N^3), since we can have ~N^2 edges.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void setIO(string file = "");

using Cow = pair<pair<int,int>,int>;
#define X first.first
#define Y first.second
#define P second

const int MAXN = 210;
vector<int> adj[MAXN];
bool visited[MAXN];
int qCows;

int dist2(Cow &a, Cow &b){
    return (a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y);
}

void dfs(int at){
    visited[at] = 1;
    ++qCows;
    for(auto to:adj[at]) if(!visited[to])
        dfs(to);
}

void solve(){
    int N; cin >> N;
    vector<Cow> cows(N);
    for(auto &c:cows) cin >> c.X >> c.Y >> c.P;
    
    for(int c1=0; c1<N; ++c1){
        for(int c2=0; c2<N; ++c2){
            if(c1 == c2) continue;
            if(dist2(cows[c1], cows[c2]) <= cows[c1].P * cows[c1].P)
                adj[c1].push_back(c2);
        }
    }
    
    int ans = 0;
    for(int c=0; c<N; ++c){
        qCows = 0;
        fill_n(visited, N, 0);
        dfs(c);
        ans = max(ans, qCows);
    }
    cout << ans << '\n';
}

signed main(){
    setIO("moocast");
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
