/*
- O que é o código:
SegTreeBeats para resolver um problema da seletiva da USP

- Problema:
Inicialmente, o i-ésimo elemento tem cor i e colorfulness 0.
As queries vão mudar [ql,qr] elementos para a cor x.
A colorfulness de um elemento nesse intervalo vai incrementar por:
    |x-ci| , onde ci é a cor atual do i-ésimo elemento

- Ideia:
Fazer Seg sobre a colorfulness.

- Conceito necessário:
  Uma query grande pode mudar o valor de vários elementos (possivelmente
diferentes), para terem o mesmo valor. Isso é algo bom, pois as contas
sobre vários elementos iguais ficam mais fáceis.
  Pra deixar os elementos diferentes, precisamos de várias queries de
tamanho 1.
  Mas é mais provável ter queries de tamanho > 1 do que tamanho = 1.
  Se o "potencial" é definido pra ser uma medida de quão diferente os
elementos do vetor são entre si, então o potencial tende a diminuir.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl    "\n"
#define int     long long

const int N = 112345;

// segtree, lazy_sum, lazy_change, min_color, max_color
int seg[4*N], lzs[4*N], lzc[4*N], lo[4*N], hi[4*N];

void build(int i, int l, int r){
    lo[i] = l, hi[i] = r;
    if(l == r) return;
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
}

void prop(int i, int l, int r){
    // lazy propagating colorfulness
    if(lzs[i]){
        seg[i] += lzs[i] * (r-l+1);
        if(l != r){
            lzs[2*i] += lzs[i];
            lzs[2*i+1] += lzs[i];
        }
        lzs[i] = 0;
    }
    // lazy propagating element changes
    if(lzc[i]){
        lo[i] = hi[i] = lzc[i];
        if(l != r){
            lzc[2*i] = lzc[i];
            lzc[2*i+1] = lzc[i];
        }
        lzc[i] = 0;
    }
}

int query(int i, int l, int r, int ql, int qr){
    prop(i, l, r);
    if(qr < l or r < ql) return 0;
    if(ql <= l and r <= qr) return seg[i];
    int m = (l+r)/2;
    return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, int x){
    prop(i, l, r);
    if(qr < l or r < ql) return;
    if(ql <= l and r <= qr and lo[i]==hi[i]){ // one more condition
        lzs[i] += abs(x-lo[i]);
        lzc[i] = x;
        prop(i, l, r);
        return;
    }
    int m = (l+r)/2;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
    
    seg[i] = seg[2*i] + seg[2*i+1];
    lo[i] = min(lo[2*i], lo[2*i+1]);
    hi[i] = max(hi[2*i], hi[2*i+1]);
}
