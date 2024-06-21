/*
https://www.codingame.com/ide/puzzle/rod-cutting-problem

Basic DP

Just a little variation of the original problem presented on CLRS book,
section 15.1.
See also original problem:
https://www.geeksforgeeks.org/problems/rod-cutting0840/1
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

using Cut = pair<int,int>;
#define len first
#define val second

signed main()
{
    int L, N; cin >> L >> N;
    
    vector<Cut> cuts(N);
    for(int i=0; i<N; ++i)
        cin >> cuts[i].len >> cuts[i].val;
    sort(begin(cuts), end(cuts));
    
    vector<int> dp(L+1);
    for(int l=1; l<=L; ++l){
        for(int i=0; i<N; ++i){
            int k = cuts[i].len;
            int v = cuts[i].val;
            if(l < k) break;
            dp[l] = max(dp[l], v + dp[l-k]);
        }
    }
    
    cout << dp[L] << '\n';
    
    return 0;
}