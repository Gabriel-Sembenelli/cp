/*
Meu terceiro AC em SegTree
https://www.spoj.com/problems/HORRIBLE/
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int N = 112345;

int seg[4*N];
int lazy[4*N];

// lazy propagation
void prop(int i, int l, int r){
    seg[i] += lazy[i] * (r-l+1);
    if(l != r){
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
    }
    lazy[i] = 0;
}

// index, left_limit, right_limit, query_left, query_right
int query(int i, int l, int r, int ql, int qr){
    prop(i, l, r);
    if(ql <= l and r <= qr) return seg[i];
    if(qr < l or r < ql) return 0;
    int m = (l+r)/2;
    return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
}

// index, left_limit, right_limit, query_left, query_right, value
void update(int i, int l, int r, int ql, int qr, int x){
    prop(i, l, r);      // dont forget
    if(qr < l or r < ql) return;
    if(ql <= l and r <= qr){
        lazy[i] += x;
        prop(i, l, r);  // dont forget
    }else{
        int m = (l+r)/2;
        update(2*i, l, m, ql, qr, x);
        update(2*i+1, m+1, r, ql, qr, x);
        seg[i] = seg[2*i] + seg[2*i+1];
    }
}

void solve(){
    // need to make sure to reset the arrays after each test
    fill(seg, seg+4*N, 0);
    fill(lazy, lazy+4*N, 0);
    //memset(seg, 0, sizeof(seg));      // may be faster
    //memset(lazy, 0, sizeof(lazy));    //
    
    int n, q; cin >> n >> q;
    
    // doing queries
    while(q--){
        int c; cin >> c;
        if(c == 0){
            int ql, qr, x; cin >> ql >> qr >> x;
            update(1, 1, n, ql, qr, x);
        }else{
            int ql, qr; cin >> ql >> qr;
            cout << query(1, 1, n, ql, qr) << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
