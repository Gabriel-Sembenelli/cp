/*
https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

DP

I just followed the explanation presented on CLRS book, section 15.2.

On this task you just need to print the optimal value, if you want to implement
a recover on the optimal parenthesization, see problem:
https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
*/
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        --N;
        vector<vector<int>> dp(N+1, vector<int>(N+1));
        for(int l=2; l<=N; ++l){
            for(int i=1; i<=N-l+1; ++i){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
            }
        }
        
        return dp[1][N];
    }
};