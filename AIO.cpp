// TEMPLATE -------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

#define endl        "\n"
#define dbg(V)      cout<<#V<<"= "<<V<<" "
#define dbgv(V)     cout<<#V<<"=";for(auto e:V)cout<<" "<<e;cout<<endl
#define int         long long

const int    INF    = 0x3f3f3f3f;
const int    LINF   = 0x3f3f3f3f3f3f3f3fLL;
const int    MOD    = 1e9+7;


void solve(){
    
}

signed main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}




// BINEXP -------------------------------------------------

const int MOD = 1e9+7;

long long binexpMOD(long long a, long long n){
    if(n==0) return 1;
    long long ret = binexpMOD(a, n/2);
    if(n%2) return ((ret%MOD)*(ret%MOD)*(a%MOD))%MOD;
    return ((ret%MOD)*(ret%MOD))%MOD;
}

long long binexp(long long a, long long n){
    if(n==0) return 1;
    long long ret = binexp(a, n/2);
    if(n%2) return ret*ret*a;
    return ret*ret;
}



















// CRIVO + FATORAÇÃO -------------------------------------------------

typedef long long   ll;

#define MAX 100001
vector<ll> primes;

void crivo(){ // CHAMAR CRIVO NA MAIN
    ll n=MAX;
    int cr[n]; for(int i=0; i<n; i++) cr[i]=0;
    for(ll i=2; i*i<n; i++)
        if(cr[i]==0)
            for(ll j=i*i; j<n; j+=i) cr[j]=1;
    for(ll i=2; i<n; i++)
        if(cr[i]==0) primes.push_back(i);
}

vector<ll> factors(ll n){
    vector<ll> re;
    for(auto p:primes){
        if(p*p > n){                // Nesse ponto, já fatorei 'n' em todos os
            if(n>1){                // primos antes de 'p', então se p*p>n,
                re.push_back(n);    // não tem mais o que fazer, ou seja, 'n'
                n=1;                // não pode mais ser fatorado, e o valor
                break;              // que sobrou é primo
            }
        }else{
            while(n % p == 0){
                re.push_back(p);
                n /= p;
            }
        }
    }
    return re;
}


// MERGESORT -------------------------------------------------

const int INF = 0x3f3f3f3f;

void mergesort(vector<int> &v){
    int n = v.size();
    if(n==1) return;
    vector<int> a, b;
    for(int i=0; i<n; i++){
        if(i<n/2) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    mergesort(a);
    mergesort(b);
    a.push_back(INF);
    b.push_back(INF);
    for(int ia=0, ib=0, iv=0; iv<n; iv++){
        if(a[ia] < b[ib]) v[iv] = a[ia++];
        else v[iv] = b[ib++];
    }
}








// GRAFO COM STRUCT -------------------------------------------------

// Tem peso nas arestas
struct graph {
    vector<vector<int>> adj, peso;
    vector<bool> visited;
    
    // Construtor
    graph(int n): adj(++n), peso(n), visited(n){}
    
    // Criar aresta entre nós 'a' e 'b'
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
            if(!visited[u]){ dfs(u); }
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

int main(){
    graph g(5);
    g.edge(1,2,100);
    g.dfs(1);
    g.bfs(1);
    g.debug();
	return 0;
}

// GRAFO SEM STRUCT -------------------------------------------------

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





























// UNION-FIND -------------------------------------------------

const int MAX = 2e5+1;
vector<int> p(MAX);  // pais
vector<int> w(MAX);  // weights

int find(int x){                //  Função para achar o patriarca de 'x'
    if(p[x] == x) return x;     //      'x' é o patriarca
    return p[x] = find(p[x]);   //      acha patriarca de p[x] e salva (otim.)
}

void join(int x, int y){        //  Função para unir famílias de 'x' e 'y'
    x = find(x);                //      Basta unir os patriarcas
    y = find(y);                //      de 'x' e 'y'

    if(x == y) return;          //      Se o patriarca é o mesmo, então já estão unidos

    if(w[x] > w[y]){            //      Família de 'x' é maior:
        p[y] = x;               //          Então pai de 'y' se torna 'x'
    }else if(w[x] < w[y]){      //      Família de 'y' é maior:
        p[x] = y;               //          Então pai de 'x' se torna 'y'
    }else if(w[x] == w[y]){     //      Famílias com mesmo peso:
        p[y] = x;               //          Escolhe pai arbitrariamente
        w[x]++;                 //          Aumenta o peso dele
    }
}

void init(int n){               //  Função para inicializar vetores 'p' e 'w'
    for(int i=1; i<=n; i++){
        p[i] = i;               //      p[1]=1, p[2]=2, ...
        w[i] = 0;               //      w = {0, 0, 0, ...}
    }
}


// PYTHON -------------------------------------------------

lista = list(map(int, input().split()))     // ler input 
x, y, z = list(map(int, input().split()))   //

myset = {1, 2, 3}           // criando set
myset = set([1, 2, 3])      // typecasting lista pra set
myset.add(4)                // insert
setUniao = set1 | set2      // união de sets
setInter = set1 & set2      // interseção de sets

dict = {    "nome":"Gabs",  //
            "altura":1.76,  // criando map com alguns elementos
            "ano":2001      //
}
dict["curso"] = "BCC"       // funciona igual C++
dict.pop("nome")            // remove item
