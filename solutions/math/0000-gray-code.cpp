// Gray Code
// Difficulty: Medium   Solved: 2026-10-21
// https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};
