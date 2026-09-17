// Permutations II
// Difficulty: Medium   Solved: 2026-09-17
// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<bool>& used, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, used, curr);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> curr;

        solve(nums, used, curr);

        return ans;
    }
};
