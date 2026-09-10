// Minimum Add to Make Parentheses Valid
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0)
                    open--;
                else
                    ans++;
            }
        }

        return ans + open;
    }
};
