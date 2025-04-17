/*
Topic: DP
Problem: https://www.geeksforgeeks.org/problems/word-break1352/1
References:
  [Erickson] Section 3.3
  https://jeffe.cs.illinois.edu/teaching/algorithms/book/03-dynprog.pdf
*/

// VERSÃO NOVA DO PROBLEMA (ABRIL DE 2025)
class Solution {
public:
    int dp[41234]{}; // Constraints estão erradas, s.size() passa de 30 mil
    
    // Iterativa (0.05s ~ 0.22s)
    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> dict;
        for(auto w : dictionary) dict.insert(w);
        int n = s.size();
        dp[n] = 1;
        for(int i = n - 1; i >= 0; --i){
            dp[i] = 0;
            string t = "";
            for(int j = i; j < min(n, i + 100); ++j){
                t += s[j];
                dp[i] |= dp[j + 1] && dict.count(t); // AC  (0.05s)
                //dp[i] |= dict.count(t) && dp[j + 1]; // AC (0.22s)
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
    
    // Recursiva (0.02s ~ 0.05s)
    bool solve(string &s, unordered_set<string>& dict, int i){
        if(dp[i] != -1) return dp[i];
        int n = s.size();
        if(i == n) return dp[i] = true;
        string t = "";
        for(int j = i; j < min(n, i + 100); j++){
            t += s[j];
            //if(solve(s, dict, j+1) && dict.count(t)) return dp[i] = true; // AC (0.05s)
            if(dict.count(t) && solve(s, dict, j+1)) return dp[i] = true; // AC  (0.02s)
        }
        return dp[i] = false;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> dict;
        for(auto w : dictionary) dict.insert(w);
        for(int i=0; i <= s.size(); ++i) dp[i] = -1;
        return solve(s, dict, 0);
    }
};

// VERSÃO ANTIGA DO PROBLEMA (SETEMBRO DE 2024)
class Solution {
public:
    int dp[1123]{};
    
    // Iterativa (0.5s ~ 0.6s)
    int wordBreak(int m, string s, vector<string> &dictionary) {
        unordered_set<string> dict;
        for(auto w : dictionary) dict.insert(w);
        int n = s.size();
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; --i){
            dp[i] = 0;
            string t = "";
            for(int j = i; j < n; ++j){
                t += s[j];
                dp[i] |= dp[j + 1] && dict.count(t); // AC  (0.6s)
                //dp[i] |= dict.count(t) && dp[j + 1]; // TLE (3.0s)
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
    
    // Recursiva (0.02 ~ 0.03s)
    bool solve(string s, unordered_set<string>& dict, int i){
        if(dp[i] != -1) return dp[i];
        int n = s.size();
        if(i == n) return dp[i] = true;
        string t = "";
        for(int j = i; j < n; j++){
            t += s[j];
            //if(solve(s, dict, j+1) && dict.count(t)) return dp[i] = true; // TLE (3.0s)
            if(dict.count(t) && solve(s, dict, j+1)) return dp[i] = true; // AC  (0.02s)
        }
        return dp[i] = false;
    }
    int wordBreak(int m, string s, vector<string> &dictionary) {
        unordered_set<string> dict;
        for(auto w : dictionary) dict.insert(w);
        for(int i=0; i <= s.size(); ++i) dp[i] = -1;
        return solve(s, dict, 0);
    }
};
