#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

void solve(){
    int l, r, ans = 0;
    vector<int> a, b;
    while(cin >> l >> r)
        a.push_back(l), b.push_back(r);
    sort(all(a)), sort(all(b));
    for(int i = 0; i < sz(a); ++i)
        ans += abs(a[i] - b[i]);
    cout << ans << '\n';
}

void solvee(){
    int l, r, ans = 0;
    vector<int> a;
    map<int, int> freq;
    while(cin >> l >> r)
        a.push_back(l), freq[r]++;
    for(auto e:a)
        ans += e * freq[e];
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solvee();
    return 0;
}
