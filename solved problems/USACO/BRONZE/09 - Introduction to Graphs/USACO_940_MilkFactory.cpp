/*
The statement gives us a Directed Acyclic Graph (DAG).

Sol 1.
When there is the case that a station 'i' can be reached by every other station,
then if we could reverse directions of every conveyor belt, 'i' would reach
every other station. This lead to a feasible solution where we check, for each
node, if it can reach all of the others. I did this using DFS. This is O(N^2).

Sol 2.
Another elegant solution is to note that such node 'i' exists iff the DAG has
exactly one sink. This is O(N).
(A sink is a node that has no arcs starting from it, every DAG has at least one)
*/
#include <bits/stdc++.h>
using namespace std;

// Sol 1. ----------------------------------------------------------------------
vector<int> adj[123];
int visited[123];
int qReach;

void dfs(int v){
    visited[v] = 1;
    qReach++;
    for(auto u:adj[v])
        if(!visited[u])
            dfs(u);
}

void solve(){
    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        adj[b].push_back(a); // Construct reversed DAG
    }
    for(int v=1; v<=N; v++){    // Test for each v
        fill_n(visited, 123, 0);
        qReach = 0;
        dfs(v);
        if(qReach == N){    // if it can reach all nodes
            cout << v << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
// -----------------------------------------------------------------------------

// Sol 2. ----------------------------------------------------------------------
void solve2(){
    int N; cin >> N;
    int dout[N+1]{};  // Outdegree array
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        dout[a]++;
    }
    int ans = 0;
    for(int v=1; v<=N; v++){
        if(ans != 0 and dout[v] == 0) ans = -1; // Found another sink
        if(ans == 0 and dout[v] == 0) ans = v;  // Found our first sink
    }
    cout << ans << '\n';
}
// -----------------------------------------------------------------------------

signed main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve2();
    
    return 0;
}
