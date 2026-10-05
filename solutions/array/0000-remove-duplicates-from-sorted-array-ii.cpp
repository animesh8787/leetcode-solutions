// Remove Duplicates from Sorted Array II
// Difficulty: Medium   Solved: 2026-10-05
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int x : nums) {
            if (k < 2 || x != nums[k - 2]) {
                nums[k++] = x;
            }
        }

        return k;
    }
};
