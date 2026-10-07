// Remove Invalid Parentheses
// Difficulty: Hard   Solved: 2026-10-07
// https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    unordered_set<string> ans;
    
    void dfs(string &s, int idx, int left, int right, int open, int close, string cur) {
        if (idx == s.size()) {
            if (open == 0 && left == 0 && right == 0)
                ans.insert(cur);
            return;
        }

        if (left + right > (int)s.size() - idx)
            return;

        if (s[idx] == '(') {
            if (left > 0)
                dfs(s, idx + 1, left - 1, right, open, close, cur);

            dfs(s, idx + 1, left, right, open + 1, close, cur + '(');
        }
        else if (s[idx] == ')') {
            if (right > 0)
                dfs(s, idx + 1, left, right - 1, open, close, cur);

            if (open > 0)
                dfs(s, idx + 1, left, right, open - 1, close + 1, cur + ')');
        }
        else {
            dfs(s, idx + 1, left, right, open, close, cur + s[idx]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        dfs(s, 0, left, right, 0, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
