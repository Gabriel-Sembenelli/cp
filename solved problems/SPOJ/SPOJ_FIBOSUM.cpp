/*
Link:
https://www.spoj.com/problems/FIBOSUM/

Tema:
Recorrência linear / FastXP

Takeouts:
- Cuidado com negativos ao fazer aritm. mod. (a-b+MOD)%MOD
- Atenção ao valor do MOD (1e9 +7 ou +9)
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define int long long

const int MOD = 1e9+7;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix T = {{1,1,0},
            {0,1,1},
            {0,1,0}};
matrix init = { {0},
                {1},
                {0}};

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

int A(int n){
    if(n < 1) return 0;
    matrix Tn = fastxp(T, n);
    matrix res = mult(Tn, init);
    return res[0][0];
}

void solve(){
    int n, m; cin >> n >> m;
    cout << (A(m) - A(n-1) + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}
