using Vertex = int;
using ii = array<int, 2>;
using iii = array<int, 3>;
vector<vector<ii>> adj; // {weight, v_to}

// returns MST
vector<Vertex> prim(Vertex s){
    int n = adj.size();
    vector<Vertex> mst(n);
    vector<bool> vis(n);
    priority_queue<iii> pq; // {weight, v_to, v_from}
    pq.push({0, s, s});
    while(!pq.empty()){
        auto [_, at, from] = pq.top(); pq.pop();
        if(vis[at]) continue;
        vis[at] = true;
        mst[at] = from;
        for(auto [w, to] : adj[at]) if(!vis[to])
            pq.push({-w, to, at});
    }
    return mst;
}

// returns MST's weight
int prim2(Vertex s){
    int n = adj.size();
    vector<bool> vis(n);
    priority_queue<ii> pq; // {weight, v_to}
    for(auto [w, to] : adj[s]) pq.push({-w, to});
    vis[s] = true;
    int weight = 0;
    while(!pq.empty()){
        auto [w, at] = pq.top(); pq.pop();
        if(vis[at]) continue;
        weight += -w;
        vis[at] = true;
        for(auto [w2, to] : adj[at]) if(!vis[to])
            pq.push({-w2, to});
    }
    return weight;
}
