/*
Yefim Dinitz' algorithm for st-MaxFlows.
Actually, this is an alternative version, developed and
popularized in the West by Shimon Even and Alon Itai.

Input: A weighted graph (directed or not)
Output: The value of an st-MaxFlow in O(V^2 E)

Tested at:
(AC, 0.09s) https://cses.fi/problemset/task/1694/
(AC, 0.32s) https://www.spoj.com/problems/FASTFLOW/

Reference:
1. https://cp-algorithms.com/graph/dinic.html
2. https://github.com/wmrmrx/icpc-notebook/blob/main/code/flow-and-matching/dinic.cpp
3. https://gitlab.com/pedroteosousa/icpc-notebook/-/blob/master/code/flow/dinic.cpp
4. https://link.springer.com/chapter/10.1007/11685654_10
*/
struct Dinitz {
    using F = long long; // flow type
    const F INF = numeric_limits<F>::max();
    
    struct Edge {
        int u, v; 
        F c, f = 0;
        F r() { return c - f; } // residue
    };
    
    int s, t, n, m = 0;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> lv, ptr;
    queue<int> q;
    
    Dinitz(int n): n(n), adj(n), lv(n), ptr(n) {}
    
    void add_edge(int u, int v, F c, F rc = 0){ // edge uv, capacity c, reverse_capacity rc
        edges.push_back({u, v, c }); adj[u].push_back(m++);
        edges.push_back({v, u, rc}); adj[v].push_back(m++);
    }

    bool bfs(){
        ptr.assign(n, 0);
        lv.assign(n, 0);
        lv[s] = 1;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto id : adj[u]){
                Edge& e = edges[id]; // e: u-->v
                if(!e.r() || lv[e.v]) continue;
                lv[e.v] = lv[u] + 1;
                q.push(e.v);
            }
        }
        return lv[t];
    }

    F dfs(int u, F pushed){
        if(!pushed || u == t) return pushed;
        for(int& i = ptr[u]; i < (int)adj[u].size(); i++){
            int id = adj[u][i];
            Edge& e = edges[id];
            if(lv[u] + 1 != lv[e.v] || !e.r()) continue;
            F f = dfs(e.v, min(e.r(), pushed));
            if(!f) continue;
            edges[id].f += f;
            edges[id ^ 1].f -= f;
            return f;
        }
        return 0;
    }

    F get_flow(int _s, int _t){
        s = _s, t = _t;
        F flow = 0;
        while(bfs()) while(F f = dfs(s, INF)) flow += f;
        return flow;
    }
};
