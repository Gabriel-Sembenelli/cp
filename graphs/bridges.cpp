/*
Algorithm to find all bridges of a graph component.

Complexity: O(V + E)

Reference:
http://professor.ufabc.edu.br/~carla.negri/cursos/2023Q3-TG/aula9.pdf
Sedgewick - Algorithms in C, Part 5 - Graph Algorithms (p 108).
*/
void dfs(int at, int from){
    visited[at] = 1;
    tin[at] = low[at] = ++time;
    for(auto to:adj[at]){
        if(!visited[to]){
            dfs(to, at);
            low[at] = min(low[at], low[to]);
            if(low[to] == tin[to]) // at--to is a cut-edge
                ++bridges;
        }else if(to != from)
            low[at] = min(low[at], tin[to]);
    }
}