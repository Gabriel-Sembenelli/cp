#include <bits/stdc++.h>
using namespace std;

// One can shuffle the cows to match the IDs input order (my solution)
// or unshuffle the IDs to match the cows initial order

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), cows(n+1);
    vector<string> ids(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cows[i] = i;
    }
    for(int shuffles=3; shuffles--;){
        vector<int> shuffled(n+1);
        for(int i=1; i<=n; i++)
            shuffled[a[i]] = cows[i];
        cows = shuffled;
    }
    for(int i=1; i<=n; i++)
        cin >> ids[cows[i]];
    for(int i=1; i<=n; i++)
        cout << ids[i] << '\n';
    
}

signed main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 