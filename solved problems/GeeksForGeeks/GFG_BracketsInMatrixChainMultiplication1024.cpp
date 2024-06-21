/*
https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

DP

I just followed the explanation presented on CLRS book, section 15.2.

On this task you need to print the optimal parenthesization, if you want to
just print the optimal value, see problem:
https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/
class Solution{
public:
    string matrixChainOrder(int arr[], int N)
    {
        --N;
        vector<vector<int>> dp(N+1, vector<int>(N+1)), s = dp;
        for(int l=2; l<=N; ++l){
            for(int i=1; i<=N-l+1; ++i){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; ++k){
                    int q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if(q < dp[i][j]){
                        dp[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        string ans = par(1, N, s);
        return ans;
    }
    
    string par(int i, int j, vector<vector<int>> &s){
        if(i == j)
            return string(1, 'A'+i-1);
        return "(" + par(i, s[i][j], s) + par(s[i][j] + 1, j, s) + ")";
    }
};