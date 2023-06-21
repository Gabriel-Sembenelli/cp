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

ll binexp(ll a, ll n){
    if(n==0) return 1;
    ll ret = binexp(a, n/2)%MOD;
    if(n%2) return ((ret%MOD)*(ret%MOD)*(a%MOD))%MOD;
    return ((ret%MOD)*(ret%MOD))%MOD;
}


void solve(int test_case=1){
    ll n; cin >> n;
    ll ans = binexp(2,n);
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