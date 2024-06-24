/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/D

Brute Force.

Temos 6 jogadoras para desempenharem 6 funções distintas, ou seja, podemos
pensar em permutações (a função f(i) é uma permutação no intervalo [1..6]).
Como 6 é pequeno, podemos testar todas as 6! = 720 permutações, fazendo, ao
todo, 6*6! = 4320 operações, que é muito pouco.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void solve(){
    const int N = 6;
    
    int A[N][N];
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> A[i][j];
    
    int f[N];
    iota(f, f+N, 0);
    
    int ans = 0;
    do{
        int aux = 0;
        for(int i=0; i<N; ++i) aux += A[i][f[i]];
        ans = max(ans, aux);
    }while(next_permutation(f, f+N));
    
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
