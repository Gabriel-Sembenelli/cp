/*
Input: An undirected weighted graph (adjacency matrix representation)
Output: Global Min-Cut in O(V^3)
Reference:
https://en.wikipedia.org/wiki/Stoer%E2%80%93Wagner_algorithm
https://dl.acm.org/doi/pdf/10.1145/263867.263872
https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=6f557b163ab5e9295bb41d3bbd974c544d336deb
https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/GlobalMinCut.h
*/

pair<int, vector<int>> mincut(vector<vector<int>> adj) {
    pair<int, vector<int>> best = {INT_MAX, {}};
    int n = adj.size();
    vector<vector<int>> co(n); // component (or metavertex)

    for(int i = 0; i < n; ++i) co[i] = {i}; // 0-indexed

    for(int ph = 1; ph < n; ++ph){
        vector<int> w = adj[0];
        int s = 0, t = 0;
        for(int it = 0; it < n - ph; ++it){ // O(V^2) (com p_queue fica O(E log V))
            w[t] = INT_MIN;
            s = t;
            t = max_element(w.begin(), w.end()) - w.begin();
            for(int i = 0; i < n; ++i) if(w[i] >= 0) w[i] += adj[t][i];
        }
        best = min(best, {w[t] - adj[t][t], co[t]});
        co[s].insert(co[s].end(), co[t].begin(), co[t].end());
        for (int i = 0; i < n; ++i) adj[s][i] += adj[t][i];
        for (int i = 0; i < n; ++i) adj[i][s] = adj[s][i];
        adj[0][t] = INT_MIN;
    }
    return best;
}
