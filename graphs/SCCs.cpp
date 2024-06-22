/*
Kosaraju, 1979

References:
https://cp-algorithms.com/graph/strongly-connected-components.html
http://professor.ufabc.edu.br/~carla.negri/cursos/2023Q3-TG/aula15.pdf

Complexity: O(V + E)
*/
int visited[MAXN], comp[MAXN], components=0;
vector<int> order, adj1[MAXN], adj2[MAXN];

void dfs1(int at){
    visited[at] = 1;
    for(auto to:adj1[at]) if(!visited[to])
        dfs1(to);
    order.push_back(at);
}

void dfs2(int at){
    comp[at] = components;
    for(auto to:adj2[at]) if(!comp[to])
        dfs2(to);
}

void SCCs(){
    for(int e=0, a,b; e<E; ++e){
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    
    fill_n(visited, V+1, 0);
    for(int v=1; v<=N; ++v) if(!visited[v])
        dfs1(v);
    
    reverse(all(order));
    fill_n(comp, V+1, 0);
    for(auto v:order) if(!comp[v]){
        ++components;
        dfs2(v);
    }
}
