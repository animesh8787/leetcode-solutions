// Largest Divisible Subset
// Difficulty: Medium   Solved: 2026-09-08
// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n, -1);

        int best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > dp[best])
                best = i;
        }

        vector<int> ans;

        while (best != -1) {
            ans.push_back(nums[best]);
            best = parent[best];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
