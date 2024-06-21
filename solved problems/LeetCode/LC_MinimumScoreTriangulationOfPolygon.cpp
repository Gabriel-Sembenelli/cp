/*
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

DP

The idea is very similar to the classic Matrix Chain Multiplication problem,
presented on CLRS, section 15.2.

Correcting the Hint 1:
Without loss of generality, there is a triangle that uses adjacent vertices A[0]
and A[N-1] (where N = A.length). Depending on your choice K of it, this breaks
down the triangulation into two subproblems A[0:K] and A[K:N-1].

See also:
https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

class Solution { // Iterative solution
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = size(v);
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int l=3; l<=n; ++l){
            for(int i=0; i<=n-l; ++i){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};

class Solution2 { // Recursive solution
public:
    vector<int> v;
    vector<vector<int>> dp;

    int minScoreTriangulation(vector<int>& values) {
        int n = size(values);
        v = values;
        dp.resize(n, vector<int>(n, -1));
        return calc(0, n-1);
    }

    int calc(int i, int j){
        if(dp[i][j] >= 0) return dp[i][j];
        
        if(j - i <= 1) return dp[i][j] = 0;
        
        dp[i][j] = INT_MAX;
        for(int k=i+1; k<j; ++k)
            dp[i][j] = min(dp[i][j], calc(i, k) + calc(k, j) + v[i]*v[k]*v[j]);
        
        return dp[i][j];
    }
};