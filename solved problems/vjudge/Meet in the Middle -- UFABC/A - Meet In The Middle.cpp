// CSES 1628
// Solução mais rápida que consegui (~350ms)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll, ll> m;
ll n, x, ans = 0;

// 'token' evita construir outro Map pra segunda metade e evita codar um search2
void search(ll token, vector<ll> &v, ll i, ll lim, ll sum){
    if(i == lim){
        if(!token) m[sum]++;
        else if(m.count(x-sum)) ans += m[x-sum];
        return;
    }
    if(sum > x) return;
    search(token, v, i+1, lim, sum);
    search(token, v, i+1, lim, sum + v[i]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> x;
    vector<ll> t(n); for(auto &e:t) cin >> e;
    sort(begin(t), end(t)); // TLE se não usar (n sei pq)
    
    m.reserve(1 << (n/2)); // Melhora um pouquinho
    search(0, t, 0, n/2, 0);
    search(1, t, n/2, n, 0);
    
    cout << ans << '\n';
}