/*
SegTree clássica de mínimo
Point update, range query
Operações só precisam ser associativas pra fazer SegTree
*/

const int N = 112345;   // be careful with problem constraints
int seg[4*N];

// seg_index, left_limit, right_limit, query_left, query_right
int query(int i, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr) return seg[i];  // [l,r] in [ql,qr]
    if(qr < l or r < ql) return INF;        // [l,r] out of [ql,qr]
    int m = (l+r)/2;
    return min( query(2*i, l, m, ql, qr),       // part of [l,r] in,
                query(2*i+1, m+1, r, ql, qr) ); // part of [l,r] out
}

// seg_index, left_limit, right_limit, query_index, new_value
void update(int i, int l, int r, int qi, int x){
    if(l == r){seg[i] = x; return;} // updating leaf node
    int m = (l+r)/2;
    if(qi <= m) update(2*i, l, m, qi, x);   // qi is in left child
    else update(2*i+1, m+1, r, qi, x);      // qi is in right child
    seg[i] = min(seg[2*i], seg[2*i+1]); // updating non-leaf node
}

signed main(){
    int n, q; cin >> n >> q;
    // building seg
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
    // doing queries
    while(q--){
        int ql, qr; cin >> ql >> qr;
        cout << query(1, 1, n, ql, qr) << "\n";
    }
    return 0;
}
