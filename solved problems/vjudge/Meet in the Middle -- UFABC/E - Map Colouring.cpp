#include <bits/stdc++.h>
using namespace std;

void solve(){
    int V, E; cin >> V >> E;
    vector<int> mex(V, 1), seen(V);
    vector<vector<int>> adj(V);
    
    set<pair<int,int>> edges;
    
    while(E--){
        int x, y; cin >> x >> y;
        edges.insert({min(x,y), max(x,y)});
    }
    
    for(auto [x,y]:edges){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    q.push(0); seen[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u:adj[v]){
            if(mex[v] == mex[u]) mex[u]++;
            if(seen[u]) continue;
            seen[u] = 1; q.push(u);
        }
    }
    
    int ans = *max_element(begin(mex), end(mex));
    if(ans <= 4) cout << ans << '\n';
    else cout << "many\n";
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
