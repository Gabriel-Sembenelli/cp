#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

// keep interval as large as possible
// be careful not to go outside [0,1000] (possible WA on test 2)
void solve(){
    int n; cin >> n;
    vector<tuple<string,int,int>> road(n);
    for(int i=0; i<n; i++){
        string ramp; int l, u;
        cin >> ramp >> l >> u;
        road[i] = {ramp, l, u};
    }
    
    // going in the highway direction
    int L = 0, U = 1000;
    for(int i=0; i<n; i++){
        string ramp; int l, u;
        tie(ramp, l, u) = road[i];
        if(ramp == "on"){        // ON ramp
            L = min(L+l, 1000);  //  add less to L
            U = min(U+u, 1000);  //  add more to U
        }else if(ramp == "off"){ // OFF ramp
            L = max(L-u, 0);     //  take more from L
            U = max(U-l, 0);     //  take less from U
        }else{                   // NONE ramp
            L = max(L, l);       //  merge/intersect intervals
            U = min(U, u);       // (valid intersection guaranteed to exist)
        }
    }
    int afterL = L, afterU = U;
    
    // going in the opposite direction
    L = 0, U = 1000;
    for(int i=n-1; i>=0; i--){
        string ramp; int l, u;
        tie(ramp, l, u) = road[i];
        // swap conditions, same logic
        if(ramp == "off"){       // OFF ramp now treated like an ON ramp
            L = min(L+l, 1000);
            U = min(U+u, 1000);
        }else if(ramp == "on"){  // ON ramp now treated like an OFF ramp
            L = max(L-u, 0);
            U = max(U-l, 0);
        }else{                   // NONE ramp still the same
            L = max(L, l);
            U = min(U, u);
        }
    }
    int beforeL = L, beforeU = U;
    
    cout << beforeL << ' ' << beforeU << '\n';
    cout << afterL << ' ' << afterU << '\n';
}

signed main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 