#include <bits/stdc++.h>
using namespace std;

// usar .clear() e .resize()
const int MAX = 2e5+1;
vector<vector<int>> adj;
vector<int> visited;


void add_edge(int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}


void DFS(int x){
    for(int i=0; i<adj[x].size(); i++){ //  Roda para os vizinhos de 'x'
        int v = adj[x][i];              
        if(!visited[v]){                //      Se um vizinho 'v' ainda não foi visitado
            visited[v] = 1;             //          Então agora foi visitado
            DFS(v);                     //          DFS recursiva no viznho 'v'
        }
    }
}


void BFS(int x){
    queue<int> q;
    q.push(x);                                  //  Primeiramente coloco 'x' na fila
    visited[x] = 1;                             //  Defino 'x' como visitado
    while(!q.empty()){                          //  Enquanto tiver gente na fila:
        int v = q.front(); q.pop();             //      Pego o primeiro elemento 'v'
        for(int i=0; i<adj[v].size(); i++){     //      Para todo vizinho de 'v',
            int u = adj[v][i];                  //          definidos como 'u'
            if(!visited[u]){                    //          Se 'u' ainda não foi visitado
                visited[u] = 1;                 //              Então agora foi
                q.push(u);                      //              Coloca na fila da BFS
            }
        }
    }
}