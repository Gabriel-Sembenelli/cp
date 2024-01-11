/*
Conteúdos interessantes:

- Condensação de vértices (usando Union-Find)
- DP em DAG

Referências: (não consegui fazer tudo sozinho)
https://youtu.be/cJiP8-Mq1jI?t=146&si=_skw7IocgSjjlOfk
https://www.youtube.com/live/TeVnz_hZNUg?si=Ki8PAgvE9ktxhpEy&t=2101
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 212345;
int p[MAX], w[MAX];

typedef pair<int,int> Node; // {A[v], v}
typedef pair<int,int> Edge; // {u, v}

int find(int x){ return (p[x] == x ? x : p[x]=find(p[x])); }

void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(w[x] < w[y]) p[x] = y;
    else if(w[y] < w[x]) p[y] = x;
    else{
        p[y] = x;
        w[x]++;
    }
}

signed main(){
    int N, M; cin >> N >> M;
    
    int A[N+1];
    vector<Node> nodes(N);
    for(int i=1; i<=N; i++){
        cin >> A[i];
        nodes[i-1] = {A[i], i};
        p[i] = i;
        w[i] = 0;
    }
    sort(begin(nodes), end(nodes)); // Ordena por A[i] pra fazer a DP mais tarde
    
    vector<Edge> edges(M);
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        edges[i] = {u,v};
        if(A[u] == A[v]) join(u,v); // Condensa os A[u] = A[v] interligados
    }
    
    vector<vector<int>> adj(N+1);
    for(auto [u,v]:edges){
        u = find(u);
        v = find(v);
        if(u == v) continue;    // Ignora os condensados
        if(A[u] < A[v]) adj[v].push_back(u); // Aresta direcionada só pros
        else adj[u].push_back(v);            // vizinhos que têm A[i] menor
    }
    
    vector<int> score(N+1, -INF); // -INF pra evitar contar um caminho crescente que começa antes do 1 (motivo de muitos WAs meus)
    score[find(1)] = 1; // Caminho começa no 1, então pelo menos ele é exclusivo
    for(auto [a,v]:nodes){
        v = find(v);
        for(auto u:adj[v]){
            score[v] = max(score[v], score[u] + 1); // Faz a DP na score
        }
    }
    int ans = score[find(N)]; // Resultado tá no grupo do N
    if(ans < 0) ans = 0;      // Se deu menor que 0 é pq não tem caminho crescente de 1 a N
    cout << ans << '\n';
    
    return 0;
}