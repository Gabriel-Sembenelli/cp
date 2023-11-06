/*
Exemplo de SegTree de soma com Lazy Propagation
Serve pra range updates & range queries
*/

const int N = 112345;

int seg[4*N];
int lazy[4*N];

// lazy propagation
void prop(int i, int l, int r){
    if(lazy[i]){
        seg[i] += lazy[i] * (r-l+1);    // updating current node value
        if(l != r){
            lazy[2*i] += lazy[i];   // propagating change to
            lazy[2*i+1] += lazy[i]; // both child nodes
        }
        lazy[i] = 0;    // reset changes on current node
    }
}

// index, left_limit, right_limit, query_left, query_right
int query(int i, int l, int r, int ql, int qr){
    prop(i, l, r);  // dont forget
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
