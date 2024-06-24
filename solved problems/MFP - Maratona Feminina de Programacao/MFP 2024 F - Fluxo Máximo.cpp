/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/F

Graphs, Binary Search, Graph Traversal.

Apesar de muito suspeito, não usamos um algoritmo de fluxo para resolver esse
problema. Na verdade, a forma que usei pra resolver esse problema foi quase
exatamente a mesma que usei nesse:
https://usaco.guide/silver/graph-traversal#problem-usaco-992

Faça uma Busca Binária na resposta.
Pra cada chute, comece um Traversal (DFS/BFS) a partir de S e veja se consegue
alcançar T, usando só vértices que tem capacidade >= ao chute.
Imprima o maior chute que dá certo. Se nenhum deu certo, -1.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int MAXN = 212345;
vector<pair<int,int>> adj[MAXN]; // {to, capacity}
int visited[MAXN];
int N, M, S, T;
bool reach;

void dfs(int at, int minC){
    if(at == T) reach = 1;
    visited[at] = 1;
    for(auto [to, cap]:adj[at]) if(!visited[to] and minC <= cap)
        dfs(to, minC);
}

bool ok(int minC){
    fill_n(visited, N+1, 0);
    reach = 0;
    dfs(S, minC);
    return reach;
}

void solve(){
    cin >> N >> M >> S >> T;
    while(M--){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    int ans = 0;
    for(int step = 1e9; step; step /= 2)
        while(ans + step <= 1e9 and ok(ans + step)) ans += step;
    
    cout << (ans == 0 ? -1LL : ans) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
