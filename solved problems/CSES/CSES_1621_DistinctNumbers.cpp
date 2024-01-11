#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n; cin >> n;
    
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(begin(a), end(a));
    
    int ans = 1; // Account a[0];
    for(int i=1; i<n; i++)
        if(a[i-1] != a[i])
            ans++;
    
    cout << ans << '\n';
    
    return 0;
}
