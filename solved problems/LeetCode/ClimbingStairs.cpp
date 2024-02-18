/*
https://leetcode.com/problems/climbing-stairs/description/

You can reach i-th step by reaching i-1 and taking 1 step,
or by reaching i-2 and taking 2 steps.
So you can add together the number of ways of reaching i-1 and i-2.
*/

class Solution {
public:

    // Bottom-Up, Iteractive approach
    int climbStairs(int n) {
        int dp[50];
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2]; // hey, Fibonacci sequence :D
        return dp[n];
    }

    // Top-Down, Recursive approach
    int memo[50]{};

    int dp(int n){
        if(n <= 1) return 1; // base case
        
        int &dpm = memo[n]; // memoization
        if(dpm) return dpm;
        
        dpm = dp(n-1) + dp(n-2); // recursive step
        return dpm;
    }
    
    int climbStairs2(int n) {
        return dp(n);
    }
};
