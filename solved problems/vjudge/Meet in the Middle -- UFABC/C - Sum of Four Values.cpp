// CSES 1642
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x;
using vii = vector<pair<int,int>>;
vector<int> a;
map<int, vii> poss;

void solve(){
    cin >> n >> x;
    a.resize(n);
    for(auto &e:a) cin >> e;
    
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            poss[a[i]+a[j]].push_back({i+1,j+1});
    
    for(auto [sum,v]:poss){
        if(poss.count(x - sum)){
            for(auto [i,j]:v){
                for(auto [i2,j2]:poss[x - sum]){
                    set<int> indexes = {i,j,i2,j2};
                    if(indexes.size() == 4){
                        printf("%lld %lld %lld %lld\n", i, j, i2, j2);
                        return;
                    }
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
