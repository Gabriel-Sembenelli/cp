#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int M[101]{}, E[101]{}, B[101]{}; // cows production
    M[0] = E[0] = B[0] = 7;
    while(n--){
        int day, change; string cow;
        cin >> day >> cow >> change;
        if(cow[0] == 'M') M[day] += change; //
        if(cow[0] == 'E') E[day] += change; // register changes
        if(cow[0] == 'B') B[day] += change; //
    }
    vector<int> win = {1,1,1}; // all cows tied initially
    int ans = 0;
    for(int i=1; i<=100; i++){
        M[i] += M[i-1]; //
        E[i] += E[i-1]; // accumulate changes
        B[i] += B[i-1]; //
        int mx = max({M[i], E[i], B[i]});
        vector<int> newwin(3);
        if(M[i] == mx) newwin[0] = 1; //
        if(E[i] == mx) newwin[1] = 1; // calculate new winners
        if(B[i] == mx) newwin[2] = 1; //
        if(newwin != win) ans++;
        win = newwin;
    }
    cout << ans << '\n';
}

signed main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 