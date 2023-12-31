#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve(){
    int n; cin >> n;
    int r[2*n];
    for(int i=0; i<n; i++){
        cin >> r[i];        // concatenate barn array to itself
        r[i+n] = r[i];      // to make circular calculations easier
    }
    int ans = INF;
    for(int i=0; i<n; i++){ // what if i-th room was selected?
        int aux = 0;
        for(int j=i; j<i+n; j++)
            aux += (j-i)*r[j];  // sum all distances
        ans = min(ans, aux); // pick minimum
    }
    cout << ans << '\n';
}

signed main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 