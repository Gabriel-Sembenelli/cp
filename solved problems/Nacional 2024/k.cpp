#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
vector<vector<int>> dp;
ll n; 
vector<int> res, v;
bool toma(int i, int s){
	//cerr << i << ' ' << s  << endl;
	if(i == n or s < 0 ) return 0;
	if(s == 0){
	
		return 1;
	}
	if(dp[i][s] != -1) return dp[i][s];
	bool da = toma(i+1, s-v[i]);
	//cerr << da << endl;
	da |= toma(i+1, s);
	return dp[i][s] = da;
}

void constroi(vector<int>&re, int i, int s){
	if(s == 0 or i == n) return;
	if(toma(i+1, s-v[i]) == 1){
		re.push_back(i);
		constroi(re, i+1, s-v[i]);
		return;
	}
	constroi(re, i+1, s);
}
void solve(){
	cin >> n;
	v.resize(n);
	for(auto &e : v) cin >> e;
	int tot = accumulate(v.begin(), v.end(), 0LL);
	if(tot%2 && cout << "-1\n") return;
	dp.resize(n, vector<int>(tot+1, -1));
	if(toma(0, tot/2)){
		set<int> s;
		constroi(res, 0, tot/2);
		vector<int> bo;
		for(int i = 0; i < n; i++) if(!binary_search(res.begin(), res.end(), i)) bo.push_back(i);
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			int p;
			if(a <= b){
				a += v[res.back()];
				p = v[res.back()];
				res.pop_back();
			}else{
				b += v[bo.back()];
				p = v[bo.back()];
				bo.pop_back();
			}
			cout << p << " \n"[i == n-1];
		}
	}else{
		cout << "-1\n";
	}
}

signed main(){
	//int t; cin >> t; while(t--);
	solve();
}