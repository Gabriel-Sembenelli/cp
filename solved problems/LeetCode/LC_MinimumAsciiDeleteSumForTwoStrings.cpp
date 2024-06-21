/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

The idea is very similar to the LCS (Longest Common Subsequence) problem.
This is because the idea is to keep one of the LCSs and remove the rest.

Imagine that MDS(i, j) gives the answer to s1[1..i] s2[1..j]
If s1[i] == s2[j], then makes sense to keep this character on the LCS, without deleting.
    so, MDS(i, j) = MDS(i-1, j-1)
If s1[i] != s2[j], then one of the two characters will be deleted (there is no way of keeping both on the LCS).
    if the best choice is to delete s1[i], then MDS(i, j) = MDS(i-1, j) + s1[i]
    if the best choice is to delete s2[j], then MDS(i, j) = MDS(i, j-1) + s2[j]

Note the similarities with the LCS properties.

See also:
https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = size(s1), m = size(s2);
        int dp[1001][1001]{};
        s1 = "." + s1; // 1-indexing
        s2 = "." + s2; //
        
        // Base cases (one string is empty)
        for(int i=1; i<=n; ++i) dp[i][0] = dp[i-1][0] + s1[i];
        for(int j=1; j<=m; ++j) dp[0][j] = dp[0][j-1] + s2[j];
        
        // Calculating the other cases
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j] + s1[i], dp[i][j-1] + s2[j]);
            }
        }
        return dp[n][m];
    }
};