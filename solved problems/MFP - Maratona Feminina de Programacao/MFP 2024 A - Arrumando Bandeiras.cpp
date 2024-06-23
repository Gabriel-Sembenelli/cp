/*
https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/A

AdHoc, Implementation, Recursion, DP.

A forma mais direta de implementar o problema é com recursão:
Bandeira(N) = Bandeira(N-1) + char(N) + Bandeira(N-1)
Os casos base são:
    Bandeira(0):
        Essa é vazia, só retornar.
    size(ans) > 1e5:
        A gente não quer gerar bandeiras tão grandes, retorna.
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

string ans;
const int MAXN = 1e5;

void calc(int n){
    if(n == 0 or sz(ans) > MAXN) return;
    calc(n-1);
    ans += 'a' + n - 1;
    calc(n-1);
}

void solve(){
    int N; cin >> N;
    calc(N);
    for(int i=0; i<min(sz(ans), MAXN); ++i) cout << ans[i];
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
