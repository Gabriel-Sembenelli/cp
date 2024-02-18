/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/
class Solution {
public:
    // (15-70 ms)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> ret(n);
        for(int i=n-1; i>=0; i--){
            if(abs(nums[l]) <= abs(nums[r]))
                ret[i] = nums[r] * nums[r--];
            else
                ret[i] = nums[l] * nums[l++];
        }
        return ret;
    }
    // Same logic (40-70 ms)
    vector<int> sortedSquares2(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> ret(n);
        int i = n-1;
        while(l <= r){
            int sql = nums[l] * nums[l];
            int sqr = nums[r] * nums[r];
            if(sql <= sqr){
                ret[i--] = sqr;
                r--;
            }else{
                ret[i--] = sql;
                l++;
            }
        }
        return ret;
    }
    // I don't know why runtime fluctuates this much.
};
