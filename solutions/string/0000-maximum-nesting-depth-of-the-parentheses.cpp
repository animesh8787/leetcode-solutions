// Maximum Nesting Depth of the Parentheses
// Difficulty: Easy   Solved: 2026-09-28
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, ans = 0;

        for (char c : s) {
            if (c == '(') {
                ++depth;
                ans = max(ans, depth);
            } else if (c == ')') {
                --depth;
            }
        }

        return ans;
    }
};
