// Reverse String
// Difficulty: Easy   Solved: 2026-10-01
// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
