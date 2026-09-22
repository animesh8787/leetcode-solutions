// Permutation Sequence
// Difficulty: Hard   Solved: 2026-09-22
// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        k--;

        string ans;

        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];

            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }

        return ans;
    }
};
