#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)(x).size()
#define all(x)  begin(x), end(x)

const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, p, t;
vector<vector<int>> d, adj, adj2;
vector<int> seen, deg, dp;
bool has_cycle;

void floyd_warshal() {
    for(int i = 0; i < n; ++i) d[i][i] = 0;
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int dfs(int at) {
    seen[at] = 1;
    int re = 0;
    for(auto to : adj[at]) if(!seen[to]) {
        if(to == t) re += 1;
        else re += dfs(to);
    }
    return re;
}

int dfs2(int at){
    if(seen[at] == 1){ has_cycle = 1; return 0; }
    if(seen[at] == 2) return dp[at];
    seen[at] = 1;
    int& dpm = dp[at];
    for(auto to : adj2[at])
        dpm = max(dpm, d[at][to] + dfs2(to));
    seen[at] = 2;
    return dpm;
}

void solve(){
    cin >> n >> m >> p >> t;
    --p, --t;
    d.assign(n, vector<int>(n, INF));
    adj.resize(n);
    adj2 = adj;
    seen.resize(n);
    deg = seen;
    while(m--){
        int a, b, l; cin >> a >> b >> l;
        --a, --b;
        d[a][b] = d[b][a] = l;
        deg[a]++, deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    floyd_warshal();
    
    // Na primeira fuga, se só tem um pt-caminho, então tudo o que 'p' vê sem passar por 't' é proibido de ir
    vector<int> proibido(n);
    if(dfs(p) == 1)
        proibido = seen;
    
    // Acha, dentre os não-proibidos, os mais distantes de 't'
    vector<int> first_run;
    for(int i = 0, best = t; i < n; ++i) if(!proibido[i]){
        if(d[t][i] == d[t][best]){
            first_run.push_back(i);
        }else if(d[t][i] > d[t][best]){
            best = i;
            first_run = {i};
        }
    }
    
    // Cria digrafo subjacente de fugas. Um vértice 'v' foge para outro 'w' só se deg[v] > 1, pois 1 aresta é usada pela polícia.
    for(int v = 0; v < n; ++v) if(deg[v] > 1) {
        int best = v;
        for(int w = 0; w < n; ++w) {
            if(d[v][w] == d[v][best]){
                adj2[v].push_back(w);
            }else if(d[v][w] > d[v][best]){
                best = w;
                adj2[v] = {w};
            }
        }
    }
    
    // No digrafo de fugas, se houver ciclo, é possível fugir pra sempre. Caso contrário, i.e., se for um DAG, a dp dá a maior resposta.
    seen.assign(n, 0); dp = seen;
    int ans = 0;
    for(auto v : first_run)
        ans = max(ans, d[t][v] + dfs2(v));
    ans += d[p][t];
    
    if(has_cycle)   cout << "impossible\n";
    else            cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
