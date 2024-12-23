#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

void solve(){
	ll n, k; cin >> n >> k;
	int ans = k-(n-1);
	cout << ans/n << endl;
	
}

signed main(){
	//int t; cin >> t; while(t--);
	solve();
}