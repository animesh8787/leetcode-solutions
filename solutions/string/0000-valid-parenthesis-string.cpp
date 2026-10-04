// Valid Parenthesis String
// Difficulty: Medium   Solved: 2026-10-04
// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } else {
                low = max(0, low - 1);
                high++;
            }

            if (high < 0) return false;
        }

        return low == 0;
    }
};
