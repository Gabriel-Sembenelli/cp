#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

void solve(){
	ll n; cin >> n;
	vector<array<ll, 2>> p(n + 1);
	p[0] = {1, 1};
	for(ll i = 1; i <= n; i++){
		ll nm = p[i - 1][1], d = 1 * p[i - 1][1] + p[i - 1][0];
		ll gc = gcd(nm, d);
		nm /= gc, d /= gc;
		p[i][0] = nm, p[i][1] = d;
	}
	cout << p.back()[0] << "\n";
}

signed main(){
	//int t; cin >> t; while(t--);
	solve();
}