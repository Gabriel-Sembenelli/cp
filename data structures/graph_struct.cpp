#include <bits/stdc++.h>
using namespace std;

// Tem peso nas arestas
struct graph {
    vector<vector<int>> adj, peso;
    vector<bool> visited;
    vector<int> pos;
    
    // Inicializar grafo
    void init(int n){
        adj.resize(++n);
        peso.resize(n);
        visited.resize(n);
        pos.resize(n);
    }
    
    // Criar aresta entre nós 'a' e 'b'
    void edge(int a, int b, int w=1){
        adj[a].push_back(b);
        adj[b].push_back(a);
        peso[a].push_back(w);
        peso[b].push_back(w);
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
    
    // depth-first-search
    void dfs(int v){
        visited[v] = true;
        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i];
            int w = peso[v][i];
            if(visited[u]){
                continue;
            }
            dfs(u);
        }
    }
};

int main(){
    graph g;
    g.init(5);
    g.edge(1,2,100);
    g.dfs(1);
    g.debug();
	return 0;
}