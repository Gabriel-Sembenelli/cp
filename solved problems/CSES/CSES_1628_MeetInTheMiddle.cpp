#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using ll = long long;
using Map = gp_hash_table<ll, ll, custom_hash>;

ll n, x;

void search(vector<ll> &v, Map &m, ll i, ll sum){
    if(i == ll(size(v))){ m[sum]++; return; }
    if(sum > x) return;
    search(v, m, i+1, sum);
    search(v, m, i+1, sum + v[i]);
}

// too slow
void search(vector<ll> &v, Map &m){
    ll N = v.size();
    ll lim = 1LL << N;
    for(ll mask = 0; mask < lim; mask++){
        ll sum = 0;
        for(ll b = 1, i = 0; b < lim; b <<= 1, i++){
            if(b & mask) sum += v[i];
            if(sum > x) break;
        }
        if(sum <= x)
            m[sum]++;
    }
}

void solve(){
    cin >> n >> x;
    vector<ll> t(n); for(auto &e:t) cin >> e;
    vector<ll> a(begin(t), begin(t) + n/2);
    vector<ll> b(begin(t) + n/2, end(t));
    
    Map ma, mb;
    search(a, ma, 0, 0);
    search(b, mb, 0, 0);
    
    ll ans = 0;
    for(auto [f,s]:ma)
        ans += s * mb[x - f];
    
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    
    return 0;
}
