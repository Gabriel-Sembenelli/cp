/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

4 solutions, worst to best
First two keep the characters that are inside the sliding window
Last two keep the index of last ocurrence of the characters
*/
class Solution {
public:
    // TreeSet approach (70 ms, 13.8 MB)
    int lengthOfLongestSubstring1(string s) {
        set<char> chars;
        int ret=0, l=0, r=0, n=s.size();
        while(r < n){
            while(chars.count(s[r]))
                chars.erase(s[l++]);
            chars.insert(s[r++]);
            ret = max(ret, r-l);
        }
        return ret;
    }
    // HashSet approach (16-66 ms, 11.2 MB)
    int lengthOfLongestSubstring2(string s) {
        unordered_set<char> chars;
        int ret=0, l=0, r=0, n=s.size();
        while(r < n){
            while(chars.count(s[r]))
                chars.erase(s[l++]);
            chars.insert(s[r++]);
            ret = max(ret, r-l);
        }
        return ret;
    }
    // HashMap approach (23-34 ms, 8.8 MB)
    int lengthOfLongestSubstring3(string s) {
        unordered_map<char, int> index;
        int ret=0, l=0, r=0, n=s.size();
        while(r < n){
            char curr = s[r];
            if(index.count(curr) and l <= index[curr])
                l = index[curr] + 1;
            index[curr] = r++;
            ret = max(ret, r-l);
        }
        return ret;
    }
    // Array approach (3-10 ms, 7.2 MB)
    int lengthOfLongestSubstring(string s) {
        int index[128];
        fill(index, index+128, -1);
        int ret=0, l=0, r=0, n=s.size();
        while(r < n){
            char curr = s[r];
            if(l <= index[curr])
                l = index[curr] + 1;
            index[curr] = r++;
            ret = max(ret, r-l);
        }
        return ret;
    }
};