/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Binary Search

Iterate through original array and do the search in a sorted array

Time complexity: O(n*lg(n))
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret, sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(auto n:nums){
            int lb = lower_bound(sorted.begin(), sorted.end(), n) - sorted.begin();
            ret.push_back(lb);
        }
        return ret;
    }
};