#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;

#define endl        "\n"
#define dbg(var)    cout<<#var<<"="<<var<<" "
#define dbgv(var)   cout<<#var<<"=";for(auto e:var)cout<<" "<<e;cout<<endl

const int    INF    = 0x3f3f3f3f;
const ll     LINF   = 0x3f3f3f3f3f3f3f3f;
const int    MOD    = 1e9+7;

/*

*/

map<ll,ll> factors(ll n){
    map<ll,ll> ret;
    ll mx = n;
    for(ll i=2; i<=5; i++){
        while(n%i==0){
            n/=i;
            ret[i]++;
        }
    }
    if(n>1) ret[n]++;
    return ret;
}

void solve(int test_case=1){
    ll n; cin>>n;
    map<ll,ll> f = factors(n);
    ll ans = min(f[2], f[5]);
    cout << ans << endl;
}


int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}