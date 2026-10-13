// Reverse String
// Difficulty: Easy   Solved: 2026-10-13
// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }

private:
    void helper(vector<char>& s, int l, int r) {
        if (l >= r) return;
        swap(s[l], s[r]);
        helper(s, l + 1, r - 1);
    }
};
