/*
https://leetcode.com/problems/shortest-common-supersequence/

DP

The answer has at least the Longest Common Subsequence of str1 and str2.
After this, just complete with the characters of str1 and str2 that do not take
part on LCS.

See also:
https://leetcode.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = size(str1), m = size(str2);
        
        // Finding LCS size of str1 and str2
        int dp[1001][1001]{}, marca1[1001]{}, marca2[1001]{};
        str1 = "." + str1; // soh pra 1-indexar as strings
        str2 = "." + str2; //
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(str1[i] == str2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // Marking characters of str1 and str2 that take part on LCS
        for(int i=n, j=m; i>0 and j>0;){
            if(str1[i] == str2[j])
                marca1[i--] = 1, marca2[j--] = 1;
            else if(dp[i-1][j] >= dp[i][j-1])
                --i;
            else
                --j;
        }
        // Building answer
        string ans;
        for(int i=1, j=1; i<=n or j<=m;){
            while((i <= n) and (!marca1[i])) ans += str1[i++];
            while((j <= m) and (!marca2[j])) ans += str2[j++];
            while((i <= n) and (j <= m) and (marca1[i]*marca2[j])) ans += str1[i++], j++;
        }
        return ans;
    }
};