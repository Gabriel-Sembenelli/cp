/*
https://usaco.guide/bronze/intro-graphs#problem-usaco-1013

AdHoc

Observe the results of a naive approach to note that the vector go back to the
initial state after some operations. This 'cycle' value is not the same for all
inputs, but it is very small, so use the naive algorithm to calculate it, then
use it again only for the remainder of 'K % cycle' to get the answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)

void solve(){
    int N, K, A1, A2, B1, B2;
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    
    vector<int> v(N+1);
    iota(all(v), 0);
    vector<int> aux = v;
    
    int cycle = 0;
    do{
        for(int l=A1, r=A2; l<r; ++l, --r) swap(v[l], v[r]);
        for(int l=B1, r=B2; l<r; ++l, --r) swap(v[l], v[r]);
        ++cycle;
    }while(v != aux);
    
    K %= cycle;
    while(K--){
        for(int l=A1, r=A2; l<r; ++l, --r) swap(v[l], v[r]);
        for(int l=B1, r=B2; l<r; ++l, --r) swap(v[l], v[r]);
    }
    
    for(int i=1; i<=N; ++i) cout << v[i] << '\n';
}

void setIO(string file = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        auto i = freopen((file + ".in").c_str(), "r", stdin);
        auto o = freopen((file + ".out").c_str(), "w", stdout);
    }
}

signed main(){
    setIO("swap");
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
