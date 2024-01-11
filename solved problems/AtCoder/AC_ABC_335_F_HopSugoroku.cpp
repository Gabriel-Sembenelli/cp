/*
Solution based on
https://youtu.be/cJiP8-Mq1jI?si=bPETS3oxhNzy0n6D&t=199

Topics:
- DP
- DP Optimization
- AM-GM-Inequality
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

signed main(){
    int N; cin >> N;
    int A[N]; for(auto &e:A) cin >> e;
    vector<int> dp(N, 1); // For all positions you can just stop there
    
    int lim = int(sqrt(N)); // Best value to choose, because of AM-GM-inequality
    vector<vector<int>> s(lim+1, vector<int>(lim+1));
    for(int i=N-1; i>=0; i--){
        
        // Computing dp[i]
        if(A[i] > lim){
            for(int j=i+A[i]; j<N; j+=A[i]){ // This could be TLE for small A[i]
                dp[i] += dp[j];              // If A = {1,1,1,...}, then it
                dp[i] %= MOD;                // would be O(N^2). That's why we
            }                                // use 'lim' to optimize the DP.
        }else{
            dp[i] += s[A[i]][i % A[i]]; // Computes all paths that we can go
            dp[i] %= MOD;               // when taking a step of x*A[i] in O(1)
        }
        
        // Adding the results to future computations of small steps
        for(int j=1; j<=lim; j++){
            s[j][i % j] += dp[i];
            s[j][i % j] %= MOD;
        }
        
    } // Note: i = k (mod A[i])  <=>  i + x*A[i] = k (mod A[i])
    
    cout << dp[0] << '\n';
    
    return 0;
}
