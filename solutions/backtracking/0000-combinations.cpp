// Combinations
// Difficulty: Medium   Solved: 2026-10-04
// https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int start, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            solve(i + 1, n, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k);
        return ans;
    }
};
