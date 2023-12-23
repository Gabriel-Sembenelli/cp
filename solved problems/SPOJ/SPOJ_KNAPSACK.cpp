/*
https://www.spoj.com/problems/KNAPSACK/

Problema clássico de DP.

A ideia é testar tudo de um jeito otimizado (usando memo).
Pro i-ésimo item, tenho a opção de pegar ou ignorar.
Aí vou para o próximo item, carregando os efeitos da decisão anterior.
Isso abre uma árvore de possibilidades.
Muitos ramos são repetidos, e aí eles são "podados" com a memo.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2023;

// [i-th_item][remaining_capacity]
int memo[N][N];

int siz[N];
int val[N];

int s, n; // max_capacity, n_items

int dp(int i, int cap){
    if(cap < 0) return -INF;    // exceeded max capacity
    if(i == n) return 0;        // no more items to look
    
    if(memo[i][cap] != -1) return memo[i][cap];
    
    int alt1 = dp(i + 1, cap - siz[i]) + val[i];    // take i-th item
    int alt2 = dp(i + 1, cap);                      // ignore i-th item
    return memo[i][cap] = max(alt1, alt2);
}

void solve(){
    memset(memo, -1, sizeof(memo));
    cin >> s >> n;
    for(int i=0; i<n; i++)
        cin >> siz[i] >> val[i];
    cout << dp(0, s) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
