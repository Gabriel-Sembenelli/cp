#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

void solve(){
	ll n; cin >> n;
	vector<int> v(n), acc(32, 0);
	for(int j = 0; j < n;  j++){
		int x; cin >> x;
		for(int i = 0; i < 32; i++){
			acc[i] += ((x >> i)&1LL);
		}
	}
	for(int j = 0; j < n; j++){
		int x = 0;
		for(int i = 0; i < 32; i++){
			if(acc[i] > 0){
				x |= (1LL << i);
				acc[i]--;
			}
		}
		cout << x << " \n"[j == n-1];
	}

}

signed main(){
	//int t; cin >> t; while(t--);
	solve();
}