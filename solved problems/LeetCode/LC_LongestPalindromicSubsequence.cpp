/*
https://leetcode.com/problems/longest-palindromic-subsequence/

DP

The solution idea is similar to LCS (Longest Common Subsequence) problem.
It is well explained on CLRS, section 15.4.

Let's use two indices (i,j), one at each end of the string.
If s[i] == s[j], then LPS(s[i..j]) = LPS(s[i+1..j-1]) + 2
    i.e., it's clear that these characters will be part of the common palindrome.
    (almost the same idea of s1[i] == s2[j] case on LCS)
If s[i] != s[j], then one of the two doesn't participate in the palindrome
(suppose by means of contradiction that both participate to convince yourself)
    if s[i] don't participate, then LPS(s[i..j]) = LPS(s[i+1..j])
    se s[j] don't participate, then LPS(s[i..j]) = LPS(s[i..j-1])
    (also similar to the s1[i] != s2[j] case on LCS)

See also:
https://leetcode.com/problems/longest-common-subsequence/
*/

class Solution { // Recursive sol.
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        int n = size(s);
        memset(dp, -1, sizeof(dp));
        return calc(s, 0, n-1);
    }
    int calc(string &s, int i, int j){
        if(dp[i][j] >= 0) return dp[i][j];
        if(j < i) return dp[i][j] = 0;
        if(i == j) return dp[i][j] = 1;
        if(s[i] == s[j]) return dp[i][j] = calc(s, i+1, j-1) + 2;
        return dp[i][j] = max(calc(s, i+1, j), calc(s, i, j-1));
    }
};

class Solution2 { // Iterative sol.
public:
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001]{};
        int n = size(s);
        for(int i=0; i<n; ++i) dp[i][i] = 1;
        for(int l=2; l<=n; ++l){
            for(int i=0; i<=n-l; ++i){
                int j = i+l-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};