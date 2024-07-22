/*
Link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3914

Tema:
Recorrência Linear

Takeouts:
Precisa escrever.
Escreve um estado F(n), vê de quem ele depende, acha a matriz de 
recorrência, pensa como faz pra sair do caso base pro próximo, acha o 
expoente que vc precisa pra calcular F(n) a partir do caso base.
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define int long long

const int MOD = 1e9+9;

#define vi vector<int>
#define matrix vector<vi>

matrix identity(int n){
    matrix ret(n, vi(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ret[i][j] = (i==j);
    return ret;
}

matrix mult(matrix a, matrix b){
    int l = sz(a);
    int c = sz(b[0]);
    matrix ret(l, vi(c));
    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            for(int k=0; k<sz(b); k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    return ret;
}

matrix fastxp(matrix base, int exp){
    matrix ret = identity(sz(base));
    while(exp){
        if(exp & 1)
            ret = mult(ret, base);
        exp /= 2;
        base = mult(base, base);
    }
    return ret;
}

int solve(int n){
    n--;
    if(n <= 2) return n;
    matrix T = {{1,1,1},
                {1,0,0},
                {0,1,0}};
    matrix init = { {2},
                    {1},
                    {0}};
    T = fastxp(T, n-2);
    matrix ans = mult(T, init);
    return ans[0][0];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    int n;
    while(cin >> n){
        if(n == 0) break;
        cout << solve(n) << '\n';
    }
    return 0;
}
