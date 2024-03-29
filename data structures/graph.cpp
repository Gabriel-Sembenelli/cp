// Tem peso nas arestas
struct Graph {
    vector<vector<int>> adj, peso;
    vector<bool> visited;
    
    // Construtor
    Graph(int n): adj(++n), peso(n), visited(n){} // 1-indexado
    
    // Criar aresta entre nós 'a' e 'b' com peso 'p' (opcional)
    void edge(int a, int b, int p=1){
        adj[a].push_back(b);
        adj[b].push_back(a);
        peso[a].push_back(p);
        peso[b].push_back(p);
    }
    
    // Depth-First Search
    void dfs(int v){
        visited[v] = 1;
        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i];
            int p = peso[v][i];
            if(!visited[u]){
                dfs(u);
            }
        }
    }
    
    // Breadth-First Search
    void bfs(int x){
        queue<int> q;
        q.push(x);
        visited[x] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int i=0; i<adj[v].size(); i++){
                int u = adj[v][i];
                int p = peso[v][i];
                if(!visited[u]){
                    visited[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    
    // Debugar grafo
    void debug(){
        for(int i=1; i<adj.size(); i++){
            cout <<  "adj[" << i << "] = \t";
            for(auto e: adj[i]){cout << e << " ";} cout << endl;
            cout << "peso[" << i << "] = \t";
            for(auto e:peso[i]){cout << e << " ";} cout << endl;
        }
    }
};
