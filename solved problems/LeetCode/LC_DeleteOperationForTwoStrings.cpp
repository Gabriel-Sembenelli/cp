/*
https://leetcode.com/problems/delete-operation-for-two-strings/

DP

Just find the LCS (Longest Common Subsequence) between the two words and erase
the letters that don't take part on the LCS.

See also:
https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int minDistance(string str1, string str2) {
        int n = size(str1), m = size(str2);
        int dp[501][501]{};
        str1 = "." + str1; // 1-indexing
        str2 = "." + str2; //
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(str1[i] == str2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int szLCS = dp[n][m];
        return (n - szLCS) + (m - szLCS);
    }
};