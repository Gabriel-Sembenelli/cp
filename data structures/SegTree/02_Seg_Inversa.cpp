/*
SegTree Inversa
Range update, point query
Nesse caso, cada nó guarda as alterações que foram feitas em seu range.
Em outras palavras, o valor no vetor será o mesmo que a soma dos valores
dos nós da seg, desde sua respectiva folha até a raiz.
*/

const int N = 112345;
int seg[4*N];

// seg_index, left_limit, right_limit, query_index
int query(int i, int l, int r, int qi){
    if(l == r) return seg[i];
    int m = (l+r)/2;
    if(qi <= m) return seg[i] + query(2*i, l, m, qi);
    else return seg[i] + query(2*i+1, m+1, r, qi);
}

// seg_index, left_lim, right_lim, query_left, query_right, new_value
void update(int i, int l, int r, int ql, int qr, int x){
    if(qr < l or r < ql) return;
    if(ql <= l and r <= qr){seg[i] += x; return;}
    int m = (l+r)/2;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
}
