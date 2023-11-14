/*
Link:
https://codeforces.com/problemset/problem/678/D

Tema:
Recorrência Linear

Takeouts:
"identity" é reservada no cpp20, troquei pra "eye"
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define int long long

const int MOD = 1e9+7;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix T;
matrix init;

matrix eye(int n){
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
    matrix ret = eye(sz(base));
    while(exp){
        if(exp & 1)
            ret = mult(ret, base);
        exp /= 2;
        base = mult(base, base);
    }
    return ret;
}

int g(int n){
    matrix Tn = fastxp(T, n);
    matrix res = mult(Tn, init);
    return res[0][0];
}

void solve(){
    int a, b, n , x;
    cin >> a >> b >> n >> x;
    T = {   {a,b},
            {0,1}};
    init = {{x},
            {1}};
    cout << g(n) << '\n';
}

signed main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
