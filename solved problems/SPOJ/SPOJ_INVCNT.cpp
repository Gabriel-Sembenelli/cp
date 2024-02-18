#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void mergesort(vector<int> &v){
    int n = v.size();
    if(n == 1) return;
    vector<int> a, b;
    for(int i=0; i<n; i++){
        if(i<n/2) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    mergesort(a);
    mergesort(b);
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    for(int ia=0, ib=0, iv=0; iv<n; iv++){
        if(a[ia] <= b[ib])
            v[iv] = a[ia++];
        else{
            v[iv] = b[ib++];
            ans += a.size()-ia-1;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(auto &e:v) cin >> e;
    ans = 0;
    mergesort(v);
    cout << ans << '\n';
}

signed main(){
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
