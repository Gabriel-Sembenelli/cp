/*
!!! NEEDS REFACTORING / HEURISTICS TO SPEED UP !!!

Implementation of Push-Relabel Algorithm for st-MaxFlows,
proposed by Goldberg & Tarjan and officially published at [4].

Input: A weighted graph (directed or not)
Output: The value of a st-MaxFlow in O(V^2 E)

Tested at:
(AC,  0.03s) https://cses.fi/problemset/task/1694/
(TLE, 2.00s) https://www.spoj.com/problems/FASTFLOW/

Reference:
1. https://cp-algorithms.com/graph/push-relabel.html
2. https://cp-algorithms.com/graph/push-relabel-faster.html
3. https://www.youtube.com/watch?v=0hI89H39USg
4. https://dl.acm.org/doi/10.1145/48014.61051
5. https://link.springer.com/chapter/10.1007/3-540-50517-2_69
Probably faster implementations:
6. https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/PushRelabel.h
7. https://github.com/Chillee/Algorithms/blob/master/Max%20Flow%20(Dinic's%2C%20HLPP)/hlpp.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(V) begin(V),end(V)

const int INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, s, t;
vector<vector<int>> c, f, adj; // capacity, flow, adjacency list
vector<int> h, ex; // height, excess
queue<int> Q; // excess vertices

void push(int u, int v){
    int d = min(ex[u], c[u][v] - f[u][v]);
    f[u][v] += d;
    f[v][u] -= d;
    ex[u] -= d;
    ex[v] += d;
    if(d && ex[v] == d && v != t) Q.push(v);
}

void relabel(int u){
    int d = INF;
    for(auto v : adj[u]) if(c[u][v] - f[u][v] > 0)
        d = min(d, h[v]);
    h[u] = d + 1;
}

void discharge(int u){
    for(auto v : adj[u]){
        if(ex[u] == 0) break;
        if(c[u][v] - f[u][v] > 0 && h[u] > h[v])
            push(u, v);
    }
    if(ex[u] > 0){
        relabel(u);
        discharge(u);
    }
}

int maxflow(){
    f.assign(n, vector<int>(n, 0));
    h.assign(n, 0);
    h[s] = n;
    ex.assign(n, 0);
    ex[s] = INF;
    for(auto v : adj[s]) push(s, v);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        discharge(v);
    }
    return ex[t];
}

// example main
signed main(){
    cin >> n >> m; s = 0; t = n - 1;
    c.assign(n, vector<int>(n, 0));
    adj.assign(n, {});
    while(m--){
        int a, b, w; cin >> a >> b >> w;
        if(--a == --b) continue; // ignore loops
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] += w;
        //c[b][a] += w; // use if undirected
    }
    for(int v = 0; v < n; ++v){ // remove parallel edges
        auto &vec = adj[v];
        sort(all(vec));
        vec.resize(unique(all(vec)) - begin(vec));
    }
    cout << maxflow() << '\n';
    return 0;
}
