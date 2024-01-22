/*
https://codeforces.com/contest/1808/problem/B

Sortings and some Math

Note that each column contribute independently to the answer, so we can look at
them separately.

Let's take the first test case:
3 5
1 4 2 8 5
7 9 2 1 4
3 8 5 3 1

All the pair combinations in the first column will give:
|1-7|  +  |1-3|  +  |7-3|
(-1+7) +  (-1+3) +  (7-3)
-1 +7 -1 +3 +7 -3
-1 -1 +3 -3 +7 +7
(+1*(0) -1*(2)) + (+3*(1) -3*(1)) + (+7*(2) -7*(0))
1*(0-2)         + 3*(1-1)         + 7*(2-0)

Note that the lowest number appear positive 0 times, and negative n-1 times
...
the highest number appear positive n-1 times, and negative 0 times

So my approach was to sort each column and iterate through it using the 'pos'
and 'neg' variables, related to the multiplier of that number

Time Complexity: O(m*n*lg(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(m, vector<int>(n)); // Made a transpose grid
    for(int i=0; i<n; i++)                       // because I wanted to
        for(int j=0; j<m; j++)                   // sort each column of
            cin >> grid[j][i];                   // the original input
    int ans = 0;
    for(int j=0; j<m; j++){
        sort(begin(grid[j]), end(grid[j])); // Sorting the input column
        for(int i=0, pos=0, neg=n-1; i<n; i++, pos++, neg--){ // Making the
            ans += grid[j][i] * (pos - neg);                  // calculation
        }                                                     // shown above
    }
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
