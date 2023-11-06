/*
Exemplo de MergeSortTree para responder queries do tipo:
- Em [l,r], quantos elementos têm valor no intervalo [a,b]?
Note que não tem update (entra em tópicos mais avançados)
*/

const int N = 112345;

vector<int> seg[4*N];
int a[N];

// building seg based on MergeSort algorithm
void build(int i, int l, int r){
    if(l == r){seg[i].push_back(a[l]); return;}
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    merge(  seg[2*i].begin(),   seg[2*i].end(),     // very useful
            seg[2*i+1].begin(), seg[2*i+1].end(),   // function to merge
            back_inserter(t[i]) );                  // arrays a,b into c
}

// in [ql,qr], how many numbers are in [qa,qb]
int query(int i, int l, int r, int ql, int qr, int qa, int qb){
    if(qr < l or r < ql) return 0;
    if(ql <= l and r <= qr){
        return  upper_bound(seg[i].begin(), seg[i].end(), qb) -
                lower_bound(seg[i].begin(), seg[i].end(), qa);
    }
    int m = (l+r)/2;
    return  query(2*i,   l,   m, ql, qr, qa, qb) +
            query(2*i+1, m+1, r, ql, qr, qa, qb);
}

signed main(){
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int ql, qr, qa, qb; cin >> ql >> qr >> qa >> qb;
        cout << query(1, 1, n, ql, qr, qa, qb) << "\n";
    }
    return 0;
}
