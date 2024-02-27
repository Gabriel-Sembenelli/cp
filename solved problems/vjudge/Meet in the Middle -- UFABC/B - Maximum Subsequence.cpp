#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x),end(x)

int n, m, ans = 0;

vector<int> poss;

void test(int sum, int i){
    if(0 <= i and i < poss.size())
        ans = max(ans, (sum + poss[i]) % m);
}

void search(int token, vector<int> &v, int i, int sum){
    if(i == v.size()){
        if(!token){
            poss.push_back(sum);
        }else{
            int i = lower_bound(all(poss), m - sum) - begin(poss);
            test(sum, i-1);
            test(sum, i);
        }
        return;
    }
    search(token, v, i+1, sum);
    search(token, v, i+1, (sum + v[i]) % m);
}

void solve(){
    cin >> n >> m;
    vector<int> a(n); for(auto &e:a) cin >> e;
    vector<int> b(begin(a), begin(a) + n/2);
    vector<int> c(begin(a) + n/2, end(a));
    
    search(0, b, 0, 0);
    
    sort(all(poss));
    poss.resize(unique(all(poss)) - begin(poss));
    
    search(1, c, 0, 0);
    
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
