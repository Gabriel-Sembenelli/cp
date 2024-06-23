/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/C

Math, Brute Force.

A menor volta possível, mesmo que não divida A, é A-B, pois B tá na volta final.
Então começa em A-B e vai subindo até achar alguém que divida A.
Os limites são 1e5 então dá pra brutar, testar um por um.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

void solve(){
    int A, B; cin >> A >> B;
    int ans = A-B;
    while(A % ans) ++ans;
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
