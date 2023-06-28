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

map<pair<ll,ll>, ll> memo;

ll f(ll n, ll m){
    if(memo.count({n,m})) return memo[{n,m}];
    if(n==0 || m==0) return memo[{n,m}] = 0;
    if(n==1 || m==1) return memo[{n,m}] = 1;
    return memo[{n,m}] = f(n-1, m) + f(n, m-1);
}

void solve(int test_case=1){
    memo.clear();
    ll n, m; cin>>n>>m;
    ll ans = f(n,m);
    cout << ans << endl;
}

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}