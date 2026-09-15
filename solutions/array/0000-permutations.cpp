// Permutations
// Difficulty: Medium   Solved: 2026-09-15
// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        function<void(int)> backtrack = [&](int idx) {
            if (idx == nums.size()) {
                ans.push_back(nums);
                return;
            }

            for (int i = idx; i < nums.size(); i++) {
                swap(nums[idx], nums[i]);
                backtrack(idx + 1);
                swap(nums[idx], nums[i]);
            }
        };

        backtrack(0);
        return ans;
    }
};
