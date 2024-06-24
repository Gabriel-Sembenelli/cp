/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/G

DP, Knapsack, Sortings.

Parece bastante um problema de Knapsack (pegar ou largar).

Itere sobre as garotas e teste as possibilidades. Precisamos saber em qual
índice estamos, 'idx', e quanto de girl power temos, 'power'. Nosso objetivo é
responder quantos times podemos formar se seguirmos adiante a partir dessa
configuração, ou seja,
dp[idx][power] :=   Quantos times podemos formar a partir da garota 'idx',
.                   tendo girl power 'power'.

Para cada garota temos duas opções *:
    Não adicionamos ela ao time:
        Nesse caso seguimos para idx + 1, com power inalterado.
    Adicionamos ela ao time *(só se power >= g[idx]):
        Nesse caso seguimos para idx + 1, com power + g[idx].
    Como cada escolha gera um time diferente (todos os times que têm a garota
    idx necessariamente são diferentes dos times que não têm a garota idx),
    então retornamos a soma dos resultados de cada opção testada.

Os casos base são:
    Quando nosso power já é >= X:
        Nesse caso, o enunciado não deixa adicionarmos mais garotas ao time.
    Quando não temos mais garotas para analisar (idx == N):
        Nesse caso, retornamos 1 se deu pra formar o time e 0 caso contrário.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int MOD = 1e9 + 7;
const int MAXN = 2e3;
int N, X;
int g[MAXN];
int dp[MAXN][MAXN];

int calc(int idx, int power){
    if(power >= X) return 1;
    if(idx == N) return 0;
    if(dp[idx][power] >= 0) return dp[idx][power];
    
    int res = 0;
    res = (res + calc(idx + 1, power)) % MOD;
    if(power >= g[idx]) res = (res + calc(idx + 1, power + g[idx])) % MOD;
    
    return dp[idx][power] = res;
}

void solve(){
    cin >> N >> X;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; ++i) cin >> g[i];
    sort(g+1, g+N);
    cout << calc(1, g[0]) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

/*
Mesma ideia, mas usando map para a DP. Fica bem mais lento mas passou.
Solução com matriz: ~100ms
Solução com map:    ~2100ms (TL é 2500ms)

Se o enunciado não limitasse o power do time a X, poderíamos ter todas as N=1500
garotas com g[i]=1500. Aí o tamanho da DP de matriz teria que ser
1500 por 1500*1500 (MLE).
Mas com esse limite, dá pra fazer uma DP em matriz de 1500 por 1500 só.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int MOD = 1e9 + 7;
const int MAXN = 2e3;
int N, X;
int g[MAXN];

map<pair<int,int>, int> dp;

int calc(int idx, int power){
    if(power >= X) return 1;
    if(idx == N) return 0;
    if(dp.count({idx, power})) return dp[{idx, power}];
    
    int res = 0;
    res = (res + calc(idx + 1, power)) % MOD;
    if(power >= g[idx]) res = (res + calc(idx + 1, power + g[idx])) % MOD;
    
    return dp[{idx, power}] = res;
}

void solve(){
    cin >> N >> X;
    for(int i=0; i<N; ++i) cin >> g[i];
    sort(g+1, g+N);
    cout << calc(1, g[0]) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
