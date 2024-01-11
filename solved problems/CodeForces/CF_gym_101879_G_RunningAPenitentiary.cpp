/*
Problema interessante de SegTree
https://codeforces.com/gym/101879/problem/G
*/
#include <bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long
#define mp      make_pair

const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 212345;

pair<int,int> seg[4*N];

// index, left_limit, right_limit, query_left, query_right
pair<int,int> query(int i, int l, int r, int ql, int qr){
    if(qr < l or r < ql) return mp(-INF, INF);
    if(ql <= l and r <= qr) return seg[i];
    
    int m = (l+r)/2;
    int f1l, f1r, f2l, f2r;
    tie(f1l, f1r) = query(2*i, l, m, ql, qr);
    tie(f2l, f2r) = query(2*i+1, m+1, r, ql, qr);
    if(f1r < f2l or f2r < f1l) return mp(1,0);  // doesn't intersect
    return mp(max(f1l, f2l), min(f1r, f2r));    // intersect
}

// index, lo, hi, query_index, query_left_value, query_right_value
void update(int i, int l, int r, int qi, int ql, int qr){
    if(l == r){seg[i] = {ql, qr}; return;}
    
    int m = (l+r)/2;
    if(qi <= m) update(2*i, l, m, qi, ql, qr);
    else update(2*i+1, m+1, r, qi, ql, qr);
    
    int f1l, f1r, f2l, f2r;
    tie(f1l, f1r) = seg[2*i];
    tie(f2l, f2r) = seg[2*i+1];
    if(f1r < f2l or f2r < f1l) seg[i] = {1,0};      // doesn't intersect
    else seg[i] = {max(f1l, f2l), min(f1r, f2r)};   // intersect
}

void solve(){
    int n, q; cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        int l, r; cin >> l >> r;
        update(1, 1, n, i, l, r);
    }
    
    while(q--){
        char c; cin >> c;
        if(c == 'C'){
            int qi, l, r; cin >> qi >> l >> r;
            update(1, 1, n, qi, l, r);
        }else{
            int ql, qr; cin >> ql >> qr;
            pair<int,int> ans = query(1, 1, n, ql, qr);
            cout << ans.second - ans.first + 1 << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
