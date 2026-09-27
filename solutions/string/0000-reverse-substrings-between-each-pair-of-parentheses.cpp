// Reverse Substrings Between Each Pair of Parentheses
// Difficulty: Medium   Solved: 2026-09-27
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr;

        for (char c : s) {
            if (c == '(') {
                st.push(curr);
                curr.clear();
            } else if (c == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            } else {
                curr += c;
            }
        }

        return curr;
    }
};
