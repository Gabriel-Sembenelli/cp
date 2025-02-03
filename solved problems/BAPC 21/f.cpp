
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(X) ((int)(X).size())
#define all(X) (X).begin(),(X).end()

pair<int,int> soma(pair<int,int> x, pair<int,int> y){
    return {x.first + y.first, x.second + y.second};
}

signed main(){
    int n; cin >> n;
    if(n % 2){ cout << "impossible\n"; return 0; }
    vector<pair<int,int>> v(n); for(auto &[a,b] : v) cin >> a >> b;
    sort(all(v));
    //for(auto [a,b] : v) cout << a << ' ' << b << '\n';
    pair<int,int> target = soma(v[0], v[n-1]);
    for(int l = 0, r = n - 1; l < r; ++l, --r){
        if(soma(v[l], v[r]) != target){ cout << "impossible\n"; return 0; }
    }
    cout << "possible\n";
    return 0;
}