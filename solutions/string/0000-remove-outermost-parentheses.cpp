// Remove Outermost Parentheses
// Difficulty: Easy   Solved: 2026-10-08
// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0)
                    ans += c;
                balance++;
            } else {
                balance--;
                if (balance > 0)
                    ans += c;
            }
        }

        return ans;
    }
};
