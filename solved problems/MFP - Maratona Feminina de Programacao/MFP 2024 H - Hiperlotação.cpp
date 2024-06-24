/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/H

Simulation, Implementation, Priority Queue.

Simula tudo com (priority)queues.
Não itere cada valor de tempo em [0..1e9], vai pulando só pros momentos
importantes, onde algo acontece.

Obs.: A priority_queue do C++, por padrão, coloca o máximo no .top().
Pra colocar o mínimo no top, é só inserir/tirar os valores com sinal invertido.
Ou pode fazer priority_queue<int, vector<int>, greater<int>>.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

#define C first
#define T second

void print(priority_queue<int> pq){while(!pq.empty()){cerr << -pq.top() << ' '; pq.pop();}cerr << '\n';}
void print(queue<pair<int,int>> q){while(!q.empty()){cerr << '{' << q.front().C << ',' << q.front().T << "} "; q.pop(); } cerr << '\n';}

void solve(){
    int N, K; cin >> N >> K;
    queue<pair<int,int>> wait; // Guarda quem ta esperando na fila
    priority_queue<int> pq;    // Guarda os tempos de quando alguem vai terminar de ser atendido (menor primeiro)
    
    vector<pair<int,int>> cliente(N);
    for(auto &[c,t]:cliente) cin >> c >> t;
    
    int ans = 0;
    int time = 0;
    for(int i=0; i<N;){
        // Pula direto pra algum momento importante, que é quando chega um
        // cliente ou quando alguém termina de ser atendido, o que vier antes
        time = cliente[i].C;
        if(!pq.empty()) time = min(time, -pq.top());
        
        // Debug
        //cerr << "time: " << time << '\n'; cerr << "cliente: {" << cliente[i].C << "," << cliente[i].T << "}\n"; cerr << "pq antes:   "; print(pq); cerr << "wait antes: "; print(wait);
        
        // Tira todo mundo que terminou de ser atendido nesse momento
        while(!pq.empty() and -pq.top() <= time) pq.pop();
        
        // Coloca todo mundo que tava esperando pra ser atendido, sem estourar K
        while(!wait.empty() and wait.front().C <= time and sz(pq) < K){
            pq.push(-(time + wait.front().T));
            wait.pop();
        }
        
        // Se o tempo atual é o tempo que esse cliente chega,
        if(time == cliente[i].C){
            // Então, se tem espaço, coloca ele pra ser atendido, senão fica na espera
            if(sz(pq) < K) pq.push(-(time + cliente[i].T));
            else wait.push(cliente[i]);
            ++i;
        }
        
        // Debug
        //cerr << "pq dps:     "; print(pq); cerr << "wait dps  : "; print(wait); cerr << '\n';
        
        // Agora que processamos tudo o que acontece nesse momento, olhamos
        // pro estado das filas
        ans = max(ans, sz(wait) + sz(pq));
    }
    
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
