/*
Link:
https://www.spoj.com/problems/MPOW/

Tema:
FastEXP

Referência:
https://cp-algorithms.com/algebra/binary-exp.html
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define matrix vector<vi>

const int MOD = 1e9+7;
int m, n;

// matrix multiplication with modulo
matrix mult(matrix a, matrix b){
    matrix ret(m, vi(m));
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<m; k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    return ret;
}

void solve(){
    cin >> m >> n;
    matrix mat(m, vi(m)), ans(m, vi(m));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];           // reading input
            if(i == j) ans[i][j] = 1;   // making ans = identity matrix
            else ans[i][j] = 0;
        }
    }
    // BinExp
    while(n){
        if(n % 2)
            ans = mult(ans, mat);
        mat = mult(mat, mat);
        n /= 2;
    }
    
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            cout << ans[i][j] << " \n"[j == m-1];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}

/*
remember to reset globals on multiple testcases! (memo, ans, ...)
*/
