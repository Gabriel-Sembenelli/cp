/*
https://www.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one2236/1

DP

Had to read the editorial, I found this problem difficult.
I didn't think of making two DPs (for prefix and suffix).
I also didn't think about the (*) property.

|s1| := n, |s2| := m.
Suppose we insert the char c to the left of the i-th position of s1.
For this operation to increase LCS between s1 and s2, it has to be a position
in s2 such that s2[j] == c and that:
LCS(s1, s2) == LCS(s1[1..i-1], s2[1..j-1]) + LCS(s1[i..n], s2[j+1..m]) (*)

1 ... i-1 c i   ... n
1 ... j-1 j j+1 ... m

If  DPL[i][j] := LCS(s1[1..i], s2[1..j])
and DPR[i][j] := LCS(s1[i..n], s2[j..m])
Then we can rewrite (*) as:
LCS(s1, s2) == DPL[i-1][j-1] + DPR[i][j+1]

See also:
https://leetcode.com/problems/longest-common-subsequence/
*/

class Solution{
public:
    int waysToIncreaseLCSBy1(int n, string s1, int m, string s2)
    {
        s1 = "." + s1 + "."; // 1-indexing
        s2 = "." + s2 + "."; //
        
        // Filling LCS table for prefix substrings
        int dpl[n+2][m+2]{};
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i] == s2[j])
                    dpl[i][j] = dpl[i-1][j-1] + 1;
                else
                    dpl[i][j] = max(dpl[i-1][j], dpl[i][j-1]);
            }
        }
        
        // Filling LCS table for suffix substrings
        int dpr[n+2][m+2]{};
        for(int i=n; i>=1; --i){
            for(int j=m; j>=1; --j){
                if(s1[i] == s2[j])
                    dpr[i][j] = dpr[i+1][j+1] + 1;
                else
                    dpr[i][j] = max(dpr[i+1][j], dpr[i][j+1]);
            }
        }
        
        int best = dpl[n][m];
        
        int ans = 0;
        // For all possible insertion positions in first string
        for(int i=1; i<=n+1; ++i){
            
            // For all possible lower case characters
            for(char c='a'; c<='z'; ++c){
                
                // Loop over same character positions in second string
                for(int j=1; j<=m; ++j) if(s2[j] == c){
                    
                    // If both, left and right substrings make total LCS then increase result by 1
                    if(dpl[i-1][j-1] + dpr[i][j+1] == best){
                        ++ans;
                        break; // Editorial's solution forgot this break (WA).
                    }
                }
            }
        }
        
        return ans;
    }
};