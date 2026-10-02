// Generate Parentheses
// Difficulty: Medium   Solved: 2026-10-02
// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void generate(int open, int close, int n, string& cur, vector<string>& ans) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            generate(open + 1, close, n, cur, ans);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            generate(open, close + 1, n, cur, ans);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        generate(0, 0, n, cur, ans);
        return ans;
    }
};
