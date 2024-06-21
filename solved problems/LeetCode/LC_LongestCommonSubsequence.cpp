/*
https://leetcode.com/problems/longest-common-subsequence/

DP

I just followed the explanation presented on CLRS book, section 15.4.

Same explanation on wikipedia:
https://en.wikipedia.org/wiki/Longest_common_subsequence
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = size(text1), m = size(text2);
        int dp[1001][1001]{};
        text1 = "." + text1; // Just 1-indexing
        text2 = "." + text2; //
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};