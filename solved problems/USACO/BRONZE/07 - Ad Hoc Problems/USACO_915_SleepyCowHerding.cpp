/*
Approach: Compute each space between the points (sp1 and sp2),
then look at each case.

If both are zero, there's nothing to do.
If any of them is 1, we can do 1 movement to group the cows, otherwise
we will need at least 2 movements.
The maximum movements we need are always the same as the biggest space size,
because we can move an endpoint close to the other and so on.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> c(3); for(auto &e:c) cin >> e;
    sort(begin(c), end(c));
    int sp1 = c[1] - c[0] - 1;
    int sp2 = c[2] - c[1] - 1;
    int ans, ANS;
    if(!sp1 and !sp2){ cout << 0 << '\n' << 0 << '\n'; return; }
    if(sp1 == 1 or sp2 == 1) ans = 1;
    else ans = 2;
    ANS = max(sp1, sp2);
    cout << ans << '\n' << ANS << '\n';
}

signed main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
