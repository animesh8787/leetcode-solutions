// Minimum Add to Make Parentheses Valid
// Difficulty: Medium   Solved: 2026-10-06
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans = 0;

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
