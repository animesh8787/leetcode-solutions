// Maximum K to Sort a Permutation
// Difficulty: Medium   Solved: 2026-10-23
// https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1; // all bits set
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }
        return ans == -1 ? 0 : ans;
    }
};
