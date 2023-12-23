/*
Meu segundo AC em SegTree
https://www.beecrowd.com.br/judge/pt/problems/view/1301
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int N = 112345;

int seg[4*N];

// index, left_limit, right_limit, query_left, query_right
int query(int i, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr) return seg[i];
    if(qr < l or r < ql) return 1; // 1 is neutral
    int m = (l+r)/2;
    return query(2*i, l, m, ql, qr) * query(2*i+1, m+1, r, ql, qr);
}

// index, left_limit, right_limit, query_index, value
void update(int i, int l, int r, int qi, int x){
    if(l == r){
        if(x > 0) x = 1;    // Only signal matters, not the actual
        if(x < 0) x = -1;   // product value. It also avoids overflow.
        seg[i] = x;
        return;
    }
    int m = (l+r)/2;
    if(qi <= m) update(2*i, l, m, qi, x);
    else update(2*i+1, m+1, r, qi, x);
    seg[i] = seg[2*i] * seg[2*i+1];
}

void solve(int n){
    int q; cin >> q;
    
    // building seg
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
    
    // doing queries
    while(q--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'C') update(1, 1, n, x, y);
        else{
            int ans = query(1, 1, n, x, y);
            if(ans > 0) cout << "+";
            else if(ans < 0) cout << "-";
            else cout << "0";
        }
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int i; while(cin>>i)
    solve(i);
    return 0;
}
