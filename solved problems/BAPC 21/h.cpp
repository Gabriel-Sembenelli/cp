
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(X) ((int)(X).size())
#define all(X) (X).begin(),(X).end()

int n, m;
vector<int> adj[212345];
int seen[212345];

void dfs(int at, int c){
    seen[at] = 1;
    if(c) cout << at << ' ';
    for(auto to : adj[at]) if(!seen[to]) dfs(to, !c);
    if(!c) cout << at << ' ';
}

signed main(){
    cin >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //for(int i = 1; i <= n; ++i){for(auto v : adj[i]) cout << v << ' '; cout << '\n';} cout << '\n';
    for(int i = 1; i <= n; ++i){
        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])), adj[i].end());
    }
    //for(int i = 1; i <= n; ++i){for(auto v : adj[i]) cout << v << ' '; cout << '\n';} cout << '\n';
    dfs(1, 1); cout << '\n';

    return 0;
}