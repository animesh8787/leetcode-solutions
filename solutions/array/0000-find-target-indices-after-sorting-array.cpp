// Find Target Indices After Sorting Array
// Difficulty: Easy   Solved: 2026-10-19
// https://leetcode.com/problems/find-target-indices-after-sorting-array/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for (int x : nums) {
            if (x < target) less++;
            else if (x == target) equal++;
        }
        vector<int> ans;
        for (int i = 0; i < equal; i++) {
            ans.push_back(less + i);
        }
        return ans;
    }
};
