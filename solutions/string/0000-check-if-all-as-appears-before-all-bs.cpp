// Check if All A's Appears Before All B's
// Difficulty: Easy   Solved: 2026-11-22
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (s[i] == 'b' && s[i + 1] == 'a') return false;
        }
        return true;
    }
};
