#include <bits/stdc++.h>
using namespace std;

// m := max size of interval

// naive
// O(n*m)
void solve(){
    int n; cin >> n;
    vector<int> buckets(1010);
    while(n--){
        int s, t, b; cin >> s >> t >> b;
        for(int i=s; i<=t; i++)
            buckets[i] += b;
    }
    cout << *max_element(begin(buckets), end(buckets)) << '\n';
}

// técnica da ondinha (prefix sum)
// O(n+m)
void solve2(){
    int n; cin >> n;
    vector<int> buckets(1010);
    while(n--){
        int s, t, b; cin >> s >> t >> b;
        buckets[s] += b;
        buckets[t+1] -= b;
    }
    for(int i=1; i<=1000; i++)
        buckets[i] += buckets[i-1];
    cout << *max_element(begin(buckets), end(buckets)) << '\n';
}

signed main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 