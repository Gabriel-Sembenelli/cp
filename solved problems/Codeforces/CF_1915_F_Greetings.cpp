/*
https://codeforces.com/contest/1915/problem/F

Ordered Set

(Desenhar ajuda bastante a pensar nesse)

Um greeting só acontece quando um segmento tá completamente contido em outro.
Então basta achar um jeito rápido de contar a quantidade de pares de segmentos
contidos um dentro do outro.

Ordena os pares por ordem decrescente de término (b[i])
Percorre essa ordenação e, pra um dado i, vê com quantos pares anteriores na
ordenação ele cruza.
Pra isso, vc só precisa ver quantos a[j] satisfazem a[j] < a[i] (j < i).
Isso se faz rápido com set e busca binária dentro do set.
Mas note que o "set" padrão do C++ não suporta busca binária, então precisamos
usar o ordered_set.

Obs.:
Dá pra usar set pq todos os pontos são distintos, senão precisaria de multiset,
imagino.
*/
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
using Par = pair<int,int>;

void solve(){
    int n; cin >> n;
    vector<Par> v(n);
    for(auto &[a,b]:v) cin >> a >> b;
    sort(begin(v), end(v), [](Par &x, Par &y){ return x.second > y.second; });
    
    ordered_set<int> prevA;
    int ans = 0;
    for(auto &[a,b]:v){
        prevA.insert(a);
        ans += prevA.order_of_key(a);
    }
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

