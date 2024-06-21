/*
https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Basic DP

Just see CLRS book section 15.1 for explanation of this classic problem.
See a variation:
https://www.codingame.com/ide/puzzle/rod-cutting-problem
*/
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1);
        
        for(int l=1; l<=n; ++l){
            for(int k=1; k<=l; ++k){
                dp[l] = max(dp[l], price[k-1] + dp[l-k]);
            }
        }
        
        return dp[n];
    }
};