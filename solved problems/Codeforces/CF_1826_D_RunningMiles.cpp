/*
https://codeforces.com/contest/1826/problem/D

Greedy, Prefix "Maximum"(?)

The editorial already have a good explanation with an easier approach imo.
https://codeforces.com/blog/entry/115892

Note that two of the optimal b[i] will be at the extremes of the interval, i.e.,
(b[i1], b[i2], b[i3]) = (b[l], b[m], b[r])

Then I kinda thought like this:
b[l] + b[m] + b[r] - (r - l) =
 b[l]          + b[m] +  b[r] - (r - l) =
 b[l]          + b[m] +  b[r] - (r-m + m-l) =
(b[l] - (m-l)) + b[m] + (b[r] - (r-m)),
i.e., the distance from 'l' to 'm' will take out points from the beauty b[l].
The same is true for 'r'.

Now, my approach was to make two arrays, L and R.
L[i] := if 'i' was the middle sight, what would be the best (b[l] - (i-l))?
R[i] := if 'i' was the middle sight, what would be the best (b[r] - (r-i))?

Note that, for some i, b[i] will actually worth b[i]-1 at position i+1 or i-1, 
                                                b[i]-2 at position i+2 or i-2,
                                                and so on...

So, when iterating from left to right we have two options for L[i]:
    L[i-1] - 1
    b[i-1] - 1
which means, we can either keep the previous L or substitute it by the i-1
sight. We can just greedily take the maximum and continue.

Do the same for R[i], iterating from right to left:
    R[i+1] - 1
    b[i+1] - 1
take the maximum and continue.

Now the answer will be the highest value of L[i] + b[i] + R[i].
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> b(n), L(n), R(n);
    for(auto &e:b) cin >> e;
    
    // Finding best (b[l] - (i-l)) for each 'i' greedily
    for(int i=1; i<n; i++)
        L[i] = max(L[i-1] - 1, b[i-1] - 1);  // Prefix maximum?
    
    // Finding best (b[r] - (r-i)) for each 'i' greedily
    for(int i=n-2; i>=0; i--)
        R[i] = max(R[i+1] - 1, b[i+1] - 1);  // Suffix maximum?
    
    // Answer is the maximum L[i] + b[i] + R[i] we can find
    int ans = 0;
    for(int i=1; i<n-1; i++)
        ans = max(ans, L[i] + b[i] + R[i]);
    
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
