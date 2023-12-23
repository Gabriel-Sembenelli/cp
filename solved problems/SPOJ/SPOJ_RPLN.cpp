/*
Meu primeiro AC de SegTree
https://www.spoj.com/problems/RPLN/
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 112345;

int seg[4*N];
int a[N];

// index, left_limit, right_limit, query_left, query_right
int query(int i, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr) return seg[i];
    if(qr < l or r < ql) return INF;
    int m = (l+r)/2;
    return min(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
}

void build(int i, int l, int r){
    if(l == r){seg[i] = a[l]; return;}
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    seg[i] = min(seg[2*i], seg[2*i+1]);
}

void solve(int tc){
    cout << "Scenario #" << tc << ":" << endl;
    
    int n, q; cin >> n >> q;
    
    for(int i=1; i<=n; i++) cin >> a[i];
    
    build(1,1,n);
    
    // doing queries
    while(q--){
        int ql, qr; cin >> ql >> qr;
        cout << query(1, 1, n, ql, qr) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; for(int i=1; i<=t; i++)
    solve(i);
    return 0;
}
